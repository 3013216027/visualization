// pro1_2.h : main header file for the PRO1_2 application
//

#if !defined(AFX_PRO1_2_H__832E4779_3C82_4B2E_8EB5_7D1E5AB90EB2__INCLUDED_)
#define AFX_PRO1_2_H__832E4779_3C82_4B2E_8EB5_7D1E5AB90EB2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPro1_2App:
// See pro1_2.cpp for the implementation of this class
//

class CPro1_2App : public CWinApp
{
public:
	CPro1_2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPro1_2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPro1_2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRO1_2_H__832E4779_3C82_4B2E_8EB5_7D1E5AB90EB2__INCLUDED_)
