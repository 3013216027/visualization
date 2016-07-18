// pro1_1Doc.h : interface of the CPro1_1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRO1_1DOC_H__7D3D1F8A_8A65_49DF_BD52_6B9768A690A2__INCLUDED_)
#define AFX_PRO1_1DOC_H__7D3D1F8A_8A65_49DF_BD52_6B9768A690A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPro1_1Doc : public CDocument
{
protected: // create from serialization only
	CPro1_1Doc();
	DECLARE_DYNCREATE(CPro1_1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPro1_1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPro1_1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPro1_1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRO1_1DOC_H__7D3D1F8A_8A65_49DF_BD52_6B9768A690A2__INCLUDED_)
