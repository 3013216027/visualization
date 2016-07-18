// pro1_1Doc.cpp : implementation of the CPro1_1Doc class
//

#include "stdafx.h"
#include "pro1_1.h"

#include "pro1_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPro1_1Doc

IMPLEMENT_DYNCREATE(CPro1_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CPro1_1Doc, CDocument)
	//{{AFX_MSG_MAP(CPro1_1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPro1_1Doc construction/destruction

CPro1_1Doc::CPro1_1Doc()
{
	// TODO: add one-time construction code here

}

CPro1_1Doc::~CPro1_1Doc()
{
}

BOOL CPro1_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPro1_1Doc serialization

void CPro1_1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPro1_1Doc diagnostics

#ifdef _DEBUG
void CPro1_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPro1_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPro1_1Doc commands
