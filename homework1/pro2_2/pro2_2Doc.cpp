// pro2_2Doc.cpp : implementation of the CPro2_2Doc class
//

#include "stdafx.h"
#include "pro2_2.h"

#include "pro2_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPro2_2Doc

IMPLEMENT_DYNCREATE(CPro2_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CPro2_2Doc, CDocument)
	//{{AFX_MSG_MAP(CPro2_2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPro2_2Doc construction/destruction

CPro2_2Doc::CPro2_2Doc()
{
	// TODO: add one-time construction code here

}

CPro2_2Doc::~CPro2_2Doc()
{
}

BOOL CPro2_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPro2_2Doc serialization

void CPro2_2Doc::Serialize(CArchive& ar)
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
// CPro2_2Doc diagnostics

#ifdef _DEBUG
void CPro2_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPro2_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPro2_2Doc commands
