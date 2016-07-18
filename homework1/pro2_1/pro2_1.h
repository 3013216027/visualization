// pro2_1.h : main header file for the PRO2_1 application
//

#if !defined(AFX_PRO2_1_H__17DD1CF1_5832_4E2E_87D6_08B1FC71AB4C__INCLUDED_)
#define AFX_PRO2_1_H__17DD1CF1_5832_4E2E_87D6_08B1FC71AB4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPro2_1App:
// See pro2_1.cpp for the implementation of this class
//

class CPro2_1App : public CWinApp
{
public:
	CPro2_1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPro2_1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPro2_1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRO2_1_H__17DD1CF1_5832_4E2E_87D6_08B1FC71AB4C__INCLUDED_)
