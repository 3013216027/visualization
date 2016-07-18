// pro2_2View.cpp : implementation of the CPro2_2View class
//

#include "stdafx.h"
#include "pro2_2.h"

#include "pro2_2Doc.h"
#include "pro2_2View.h"
#include "mainfrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPro2_2View

IMPLEMENT_DYNCREATE(CPro2_2View, CView)

BEGIN_MESSAGE_MAP(CPro2_2View, CView)
	//{{AFX_MSG_MAP(CPro2_2View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPro2_2View construction/destruction

CPro2_2View::CPro2_2View()
{
	// TODO: add construction code here

}

CPro2_2View::~CPro2_2View()
{
}

BOOL CPro2_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPro2_2View drawing

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
static const int match_hor[2][2] = {0,0, 0,1};
static const int match_ver[2][2] = {0,0, 1,0};

/* 单个网格内，四个顶点相对中心点的坐标偏移量 */
static const int dd[4][2] = {0,0, 1,0, 1,1, 0,1};

double value[GRID_SIZE + 1][GRID_SIZE + 1]; //各顶点value值
int hor[GRID_SIZE][GRID_SIZE + 1][2]; //水平线段上的等值点坐标
int ver[GRID_SIZE + 1][GRID_SIZE][2]; //垂直线段上的等值点坐标

/* 三角划分部分 */
int pos_center[GRID_SIZE][GRID_SIZE][2]; //中心点坐标
double value_center[GRID_SIZE][GRID_SIZE]; //中心点函数值
int center[GRID_SIZE][GRID_SIZE][4][2]; //中心点向四个角连线段上的等值点坐标，注意到每个点延伸四条线段

//线段两端点函数值分别为x,y，返回该线段上是否存在等值点
bool valid(double x, double y) {
	return (x - CON) * (y - CON) < EPS;
}

//返回一个范围在[0,1.0]的伪随机小数
double generate() {
	return (rand() % 10) / 9.0;
	//return rand() / RAND_RANGE;
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
	
	//三角划分，计算各中心点函数值和坐标，并保存中心点向四个角连线段上可能的等值点坐标
	/*******************************************************
	 * 坐标偏移量，设中心点为(x,y)，则四个角在pos数组对应下标分别为
	 * 左上(x,y), 右上(x+1,y), 右下(x,y+1), 左下(x+1,y+1)
	 *******************************************************/
	//freopen("error.txt", "w", stdout);
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {	
			/* 计算中心点函数值 */
			value_center[i][j] = 0.0;
			for (int k = 0; k < 4; ++k) {
				value_center[i][j] += value[i + dd[k][0]][j + dd[k][1]]; //四个角求和
			}
			value_center[i][j] *= 0.25;//取四个角平均值
			//std::cout << value_center[i][j] << " ";

			/* 中心点向四个角连线等值点坐标 */
			for (k = 0; k < 4; ++k) {
				if (valid(value_center[i][j], value[i + dd[k][0]][j + dd[k][1]])) {
					//存在等值点
					int dx = pos_center[i][j][0] - pos[i + dd[k][0]][j + dd[k][1]][0];
					int dy = pos_center[i][j][1] - pos[i + dd[k][0]][j + dd[k][1]][1];
					center[i][j][k][0] = pos[i + dd[k][0]][j + dd[k][1]][0];
					center[i][j][k][0] += (int)(dx * (CON - value[i + dd[k][0]][j + dd[k][1]])
						/ (value_center[i][j] - value[i + dd[k][0]][j + dd[k][1]]));
					center[i][j][k][1] = pos[i + dd[k][0]][j + dd[k][1]][1];
					center[i][j][k][1] += (int)(dy * (CON - value[i + dd[k][0]][j + dd[k][1]])
						/ (value_center[i][j] - value[i + dd[k][0]][j + dd[k][1]]));
				} else {
					//不存在等值点
					center[i][j][k][0] = center[i][j][k][1] = -1;
				}
				//std::cout << "center[" << i << "][" << j << "][" << k << "] = " << center[i][j][k][0] << ", " << center[i][j][k][1] << std::endl;
			}
		}
		//std::cout << std::endl;
	}

	/* 画等值线，考虑到任何一段等值线都至少涉及一条斜线段，我们只考虑这4xSIZExSIZE段斜线段 */
	/* 斜线段关联的水平&垂直线段 */
	int con_hor[4][2] = {0,0, 0,0, 0,1, 0,1};
	int con_ver[4][2] = {0,0, 1,0, 1,0, 0,0};
	for (i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			for (int k = 0; k < 4; ++k) {
				if (center[i][j][k][0] == -1) continue;
				if (~center[i][j][(k + 1) % 4][0]) {
					pDC->MoveTo(center[i][j][k][0], center[i][j][k][1]);
					pDC->LineTo(center[i][j][(k+1)%4][0], center[i][j][(k+1)%4][1]);
				}
				int xx = i + con_hor[k][0];
				int yy = j + con_hor[k][1];
				if (~hor[xx][yy][0]) {
					pDC->MoveTo(center[i][j][k][0], center[i][j][k][1]);
					pDC->LineTo(hor[xx][yy][0], hor[xx][yy][1]);
				}
				xx = i + con_ver[k][0];
				yy = j + con_ver[k][1];
				if (~ver[xx][yy][0]) {
					pDC->MoveTo(center[i][j][k][0], center[i][j][k][1]);
					pDC->LineTo(ver[xx][yy][0], ver[xx][yy][1]);
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

void CPro2_2View::OnDraw(CDC* pDC)
{
	CPro2_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	//调整窗口
	//CMainFrame* pMain = (CMainFrame*)AfxGetMainWnd();
	//pMain->ActivateFrame(SW_SHOWMAXIMIZED); //最大化主窗口

	//add draw code for native data here
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
	
	for (i = 0; i < GRID_SIZE; ++i) {
		for (j = 0; j < GRID_SIZE; ++j) {
			/* 计算网格中心点坐标 */
			pos_center[i][j][0] = (pos[i][j][0] + pos[i + 1][j][0]) >> 1;
			pos_center[i][j][1] = (pos[i][j][1] + pos[i][j + 1][1]) >> 1;
			for (int k = 0; k < 4; ++k) {
				pDC->MoveTo(pos_center[i][j][0], pos_center[i][j][1]);
				pDC->LineTo(pos[i+dd[k][0]][j+dd[k][1]][0], pos[i+dd[k][0]][j+dd[k][1]][1]);
			}
		}
	}

	//生成各顶点value值
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
// CPro2_2View printing

BOOL CPro2_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPro2_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPro2_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPro2_2View diagnostics

#ifdef _DEBUG
void CPro2_2View::AssertValid() const
{
	CView::AssertValid();
}

void CPro2_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPro2_2Doc* CPro2_2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPro2_2Doc)));
	return (CPro2_2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPro2_2View message handlers
