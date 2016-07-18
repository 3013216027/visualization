// pro1_1View.h : interface of the CPro1_1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRO1_1VIEW_H__7EE6414F_61D7_4BFB_9A0E_22ADE74634E5__INCLUDED_)
#define AFX_PRO1_1VIEW_H__7EE6414F_61D7_4BFB_9A0E_22ADE74634E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPro1_1View : public CView
{
protected: // create from serialization only
	CPro1_1View();
	DECLARE_DYNCREATE(CPro1_1View)

// Attributes
public:
	CPro1_1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPro1_1View)
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
	virtual ~CPro1_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPro1_1View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in pro1_1View.cpp
inline CPro1_1Doc* CPro1_1View::GetDocument()
   { return (CPro1_1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRO1_1VIEW_H__7EE6414F_61D7_4BFB_9A0E_22ADE74634E5__INCLUDED_)
