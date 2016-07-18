// pro2_1Doc.h : interface of the CPro2_1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRO2_1DOC_H__CD2567D1_5B8E_4F4E_BB2F_7037E68BBB88__INCLUDED_)
#define AFX_PRO2_1DOC_H__CD2567D1_5B8E_4F4E_BB2F_7037E68BBB88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPro2_1Doc : public CDocument
{
protected: // create from serialization only
	CPro2_1Doc();
	DECLARE_DYNCREATE(CPro2_1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPro2_1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPro2_1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPro2_1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRO2_1DOC_H__CD2567D1_5B8E_4F4E_BB2F_7037E68BBB88__INCLUDED_)
