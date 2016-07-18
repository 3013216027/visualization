// pro2_2View.h : interface of the CPro2_2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRO2_2VIEW_H__B774FDDB_4C4B_4F62_AB34_053BBFBD3AE7__INCLUDED_)
#define AFX_PRO2_2VIEW_H__B774FDDB_4C4B_4F62_AB34_053BBFBD3AE7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPro2_2View : public CView
{
protected: // create from serialization only
	CPro2_2View();
	DECLARE_DYNCREATE(CPro2_2View)

// Attributes
public:
	CPro2_2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPro2_2View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPro2_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPro2_2View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in pro2_2View.cpp
inline CPro2_2Doc* CPro2_2View::GetDocument()
   { return (CPro2_2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRO2_2VIEW_H__B774FDDB_4C4B_4F62_AB34_053BBFBD3AE7__INCLUDED_)
