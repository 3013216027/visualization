// pro2_1Doc.cpp : implementation of the CPro2_1Doc class
//

#include "stdafx.h"
#include "pro2_1.h"

#include "pro2_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPro2_1Doc

IMPLEMENT_DYNCREATE(CPro2_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CPro2_1Doc, CDocument)
	//{{AFX_MSG_MAP(CPro2_1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPro2_1Doc construction/destruction

CPro2_1Doc::CPro2_1Doc()
{
	// TODO: add one-time construction code here

}

CPro2_1Doc::~CPro2_1Doc()
{
}

BOOL CPro2_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPro2_1Doc serialization

void CPro2_1Doc::Serialize(CArchive& ar)
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
// CPro2_1Doc diagnostics

#ifdef _DEBUG
void CPro2_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPro2_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPro2_1Doc commands
