#if !defined(AFX_PROPINPUT_H__2307F7F0_05AA_4898_8411_208D86CEA0C1__INCLUDED_)
#define AFX_PROPINPUT_H__2307F7F0_05AA_4898_8411_208D86CEA0C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PropInput.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPropInput dialog

class CPropInput : public CDialog
{
// Construction
public:
	CPropInput(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPropInput)
	enum { IDD = IDD_DIALOG1 };
	float	m_nProportion1;
	float   m_nProportion2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPropInput)
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPINPUT_H__2307F7F0_05AA_4898_8411_208D86CEA0C1__INCLUDED_)
