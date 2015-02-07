#if !defined(AFX_DIALOG1_H__21813430_55AD_4608_B22A_67D44862EEE4__INCLUDED_)
#define AFX_DIALOG1_H__21813430_55AD_4608_B22A_67D44862EEE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dialog1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// dialog1 dialog

class dialog1 : public CDialog
{
// Construction
public:
	void OnPaint();
	 bool m_bMoved;
	dialog1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(dialog1)
	enum { IDD = IDD_DIALOG1 };
	CStatic	m_cHistogram;
	int		m_x1;
	int		m_y1;
	int		m_x2;
	int		m_y2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(dialog1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(dialog1)
	afx_msg void OnChangeData();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG1_H__21813430_55AD_4608_B22A_67D44862EEE4__INCLUDED_)
