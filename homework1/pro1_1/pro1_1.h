// pro1_1.h : main header file for the PRO1_1 application
//

#if !defined(AFX_PRO1_1_H__23A1C3D3_1C65_45B8_93B8_D7AE47FBDA66__INCLUDED_)
#define AFX_PRO1_1_H__23A1C3D3_1C65_45B8_93B8_D7AE47FBDA66__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPro1_1App:
// See pro1_1.cpp for the implementation of this class
//

class CPro1_1App : public CWinApp
{
public:
	CPro1_1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPro1_1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPro1_1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRO1_1_H__23A1C3D3_1C65_45B8_93B8_D7AE47FBDA66__INCLUDED_)
