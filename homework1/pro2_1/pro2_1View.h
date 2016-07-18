// pro2_1View.h : interface of the CPro2_1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRO2_1VIEW_H__135638B9_F03A_46C7_9E93_98E13140DC4F__INCLUDED_)
#define AFX_PRO2_1VIEW_H__135638B9_F03A_46C7_9E93_98E13140DC4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPro2_1View : public CView
{
protected: // create from serialization only
	CPro2_1View();
	DECLARE_DYNCREATE(CPro2_1View)

// Attributes
public:
	CPro2_1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPro2_1View)
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
	virtual ~CPro2_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPro2_1View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in pro2_1View.cpp
inline CPro2_1Doc* CPro2_1View::GetDocument()
   { return (CPro2_1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRO2_1VIEW_H__135638B9_F03A_46C7_9E93_98E13140DC4F__INCLUDED_)
