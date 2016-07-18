// pro2_1View.cpp : implementation of the CPro2_1View class
//

#include "stdafx.h"
#include "pro2_1.h"

#include "pro2_1Doc.h"
#include "pro2_1View.h"
#include "mainfrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPro2_1View

IMPLEMENT_DYNCREATE(CPro2_1View, CView)

BEGIN_MESSAGE_MAP(CPro2_1View, CView)
	//{{AFX_MSG_MAP(CPro2_1View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPro2_1View construction/destruction

CPro2_1View::CPro2_1View()
{
	// TODO: add construction code here

}

CPro2_1View::~CPro2_1View()
{
}

BOOL CPro2_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPro2_1View drawing

static double CON = 0.4; //欲计算的等值
const double EPS = 1e-8; //精度
const double RAND_RANGE = RAND_MAX - 1.0; //随机数范围映射[0,RAND_RANGE] => [0,1]

/* 左上角顶点相对屏幕左上角偏移位置 */
const int LEFT_TOP_X = 10;
const int LEFT_TOP_Y = 10;

/* 网格规模为GRID_SIZE x GRID_SIZE */
const int GRID_SIZE = 50;

/* 网格大小，设置依据为(屏幕长/宽的较小者)除以(网格数量加5) */
const int SCREEN_WIDTH = GetSystemMetrics(SM_CXFULLSCREEN);
const int SCREEN_HEIGHT = GetSystemMetrics(SM_CYFULLSCREEN);
const int INC = min(SCREEN_WIDTH, SCREEN_HEIGHT) / (GRID_SIZE + 5);
const double INC_DB = (double)INC;

/* 各顶点坐标 */
int pos[GRID_SIZE + 1][GRID_SIZE + 1][2];

/* 单个网格内，各线段间的下标相对中心点坐标的偏移关系 */
int match_hor[2][2] = {0,0, 0,1};
int match_ver[2][2] = {0,0, 1,0};

double value[GRID_SIZE + 1][GRID_SIZE + 1]; //各顶点value值
int hor[GRID_SIZE][GRID_SIZE + 1][2]; //水平线段上的等值点坐标
int ver[GRID_SIZE + 1][GRID_SIZE][2]; //垂直线段上的等值点坐标

//线段两端点函数值分别为x,y，返回该线段上是否存在等值点
bool valid(double x, double y) {
	return (x - CON) * (y - CON) < EPS;
}

//返回一个范围在[0,1.0]的伪随机小数
double generate() {
	//return (rand() % 10) / 9.0;
	return rand() / RAND_RANGE;
}

//传入一个网格四边上等值点的横坐标(若无则为-1)，返回该网格是否存在二义性
bool ambiguous(int x1, int x2, int x3, int x4) {
	return (~x1) && (~x2) && (~x3) && (~x4);
}

//绘制等值线
void flush(CDC* pDC = NULL) {
	if (pDC == NULL) {
		return;
	}
	//画等值线，单独处理每个网格。
	//对每个网格：
	//若存在二义性，则计算中心点函数值，近似地搞一下；
	//若不存在二义性，只需要顺时针地考虑相邻两边界的连接即可，即考虑=>
	//1. hor[i][j] <--> ver[i][j]|ver[i+1][j]和hor[i][j+1] <--> ver[i][j]|ver[i+1][j]的连接
	//2. hor[i][j] <--> hor[i][j+1] 和 ver[i][j] <--> ver[i+1][j]的连接
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			/* 网格(i,j)，四条边界分别为hor[i][j], ver[i+1][j], hor[i][j+1], ver[i][j] */
			if (ambiguous(hor[i][j][0], ver[i + 1][j][0], hor[i][j + 1][0], ver[i][j][0])) {
				//存在二义性
				//std::cout << "(" << i << ", " << j << ") ";
				//std::cout.flush();
				double value_center = (value[i][j] + value[i + 1][j] + value[i][j + 1] + value[i + 1][j + 1]) * 0.25;
				if ((value_center - CON) * (value[i][j] - CON) > EPS) {
					//中心点和左上角顶点、右下角顶点“同号”，即三者均大于欲求值CON或者均小于CON
					//连接hor[i][j]和ver[i+1][j]，以及hor[i][j+1]和ver[i][j]
					pDC->MoveTo(hor[i][j][0], hor[i][j][1]);
					pDC->LineTo(ver[i + 1][j][0], ver[i + 1][j][1]);
					pDC->MoveTo(hor[i][j + 1][0], hor[i][j + 1][1]);
					pDC->LineTo(ver[i][j][0], ver[i][j][1]);
				} else {
					//中心点和右上角顶点、左下角顶点“同号”
					//连接hor[i][j]和ver[i][j]，以及hor[i][j+1]和ver[i+1][j]
					pDC->MoveTo(hor[i][j][0], hor[i][j][1]);
					pDC->LineTo(ver[i][j][0], ver[i][j][1]);
					pDC->MoveTo(hor[i][j + 1][0], hor[i][j + 1][1]);
					pDC->LineTo(ver[i + 1][j][0], ver[i + 1][j][1]);
				}
			} else {
				//不存在二义性
				int ih, jh, iv, jv;
				for (int idx_hor = 0; idx_hor < 2; ++idx_hor) {
					ih = i + match_hor[idx_hor][0];
					jh = j + match_hor[idx_hor][1];
					if (hor[ih][jh][0] == -1) continue;
					for (int idx_ver = 0; idx_ver < 2; ++idx_ver) {
						iv = i + match_ver[idx_ver][0];
						jv = j + match_ver[idx_ver][1];
						if (ver[iv][jv][0] == -1) continue;
						pDC->MoveTo(hor[ih][jh][0], hor[ih][jh][1]);
						pDC->LineTo(ver[iv][jv][0], ver[iv][jv][1]);
					}
				}
				if ((~hor[i][j][0]) && (~hor[i][j + 1][0])) {
					pDC->MoveTo(hor[i][j][0], hor[i][j][1]);
					pDC->LineTo(hor[i][j + 1][0], hor[i][j + 1][1]);
				}
				if ((~ver[i][j][0]) && (~ver[i + 1][j][0])) {
					pDC->MoveTo(ver[i][j][0], ver[i][j][1]);
					pDC->LineTo(ver[i + 1][j][0], ver[i + 1][j][1]);
				}
			}
		}
	}
}

void calculate(CDC* pDC, double _con) {
	CON = _con;
	//计算各边界的等值点(等值线和网格交点)坐标，映射关系为point=>cordination
	for (int i = 0; i <= GRID_SIZE; ++i) {
		for (int j = 0; j <= GRID_SIZE; ++j) {
			if (i < GRID_SIZE) {
				if (valid(value[i][j], value[i + 1][j])) {
					hor[i][j][0] = pos[i][j][0];
					hor[i][j][1] = pos[i][j][1];
					hor[i][j][0] += (int)(INC_DB * (CON - value[i][j]) / (value[i + 1][j] - value[i][j]));
				} else {
					hor[i][j][0] = hor[i][j][1] = -1;
				}
			}
			if (j < GRID_SIZE) {
				if (valid(value[i][j], value[i][j + 1])) {
					ver[i][j][0] = pos[i][j][0];
					ver[i][j][1] = pos[i][j][1];
					ver[i][j][1] += (int)(INC_DB * (CON - value[i][j]) / (value[i][j + 1] - value[i][j]));
				} else {
					ver[i][j][0] = ver[i][j][1] = -1;
				}
			}
		}
	}
	flush(pDC); //绘制等值线
}

void CPro2_1View::OnDraw(CDC* pDC)
{
	CPro2_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	//add draw code for na	tive data here
	CPen myPen1;
	//myPen1.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	myPen1.CreatePen(PS_SOLID, 1, RGB(25, 193, 242));
	CPen* oldPen = pDC->SelectObject(&myPen1);
	//pDC->SelectObject(oldPen);
		
	//产生网格
	int i, j;
	for (i = 0; i <= GRID_SIZE; ++i) {
		for (j = 0; j <= GRID_SIZE; ++j) {
			pos[i][j][0] = LEFT_TOP_X + INC * i;
			pos[i][j][1] = LEFT_TOP_Y + INC * j;
		}
	}
	for (i = 0; i <= GRID_SIZE; ++i) {
		pDC->MoveTo(LEFT_TOP_X + INC * i, LEFT_TOP_Y);
		pDC->LineTo(LEFT_TOP_X + INC * i, LEFT_TOP_Y + INC * GRID_SIZE);
		pDC->MoveTo(LEFT_TOP_X, LEFT_TOP_Y + INC * i);
		pDC->LineTo(LEFT_TOP_X + INC * GRID_SIZE, LEFT_TOP_Y + INC * i);
	}

	//生成各定点value值
	srand(time(0));
	for (i = 0; i <= GRID_SIZE; ++i) {
		for (j = 0; j <= GRID_SIZE; ++j) {
			value[i][j] = generate(); //各顶点随机赋值[0,1.0]
		}
	}

	//标顶点数值
	/* 显示数字字符的坐标相对对应格点的偏移量，根据显示屏的比例和分辨率可能需要微调RDU_X和RDU_Y */
	/*
	const int RDU_X = 1;
	const int RDU_Y = 1;
	CString str; //用于格式化数字, 转换：integer => QString
	for (i = 0; i <= GRID_SIZE; ++i) {
		for (j = 0; j <= GRID_SIZE; ++j) {
			str.Format(".%.0f", 10.0 * value[i][j]); //此处格式化模式应匹配value的数据类型(int?float?)
			pDC->TextOut(pos[i][j][0] - RDU_X, pos[i][j][1] - RDU_Y, str);
		}
	}
	*/

	//红色画笔
	CPen myPen2;
	myPen2.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	oldPen = pDC->SelectObject(&myPen2);

	calculate(pDC, 0.4); //计算各网格边界等值点，等值为CON=0.4，并绘制等值线

	//蓝色画笔
	CPen myPen3;
	//myPen3.CreatePen(PS_SOLID, 1, RGB(6, 189, 19));
	myPen3.CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	oldPen = pDC->SelectObject(&myPen3);
	
	calculate(pDC, 0.6); //计算各网格等值为CON=0.6的等值点并绘制等值线
}

/////////////////////////////////////////////////////////////////////////////
// CPro2_1View printing

BOOL CPro2_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPro2_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPro2_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPro2_1View diagnostics

#ifdef _DEBUG
void CPro2_1View::AssertValid() const
{
	CView::AssertValid();
}

void CPro2_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPro2_1Doc* CPro2_1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPro2_1Doc)));
	return (CPro2_1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPro2_1View message handlers
