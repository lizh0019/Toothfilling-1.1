// ColorEnhansement.h : main header file for the COLORENHANSEMENT application
//

#if !defined(AFX_COLORENHANSEMENT_H__3A0EDB06_CD75_4523_BCE2_81DC9EB01A7B__INCLUDED_)
#define AFX_COLORENHANSEMENT_H__3A0EDB06_CD75_4523_BCE2_81DC9EB01A7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CColorEnhansementApp:
// See ColorEnhansement.cpp for the implementation of this class
//

class CColorEnhansementApp : public CWinApp
{
public:
	CColorEnhansementApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorEnhansementApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CColorEnhansementApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORENHANSEMENT_H__3A0EDB06_CD75_4523_BCE2_81DC9EB01A7B__INCLUDED_)
