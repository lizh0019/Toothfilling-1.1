#if !defined(AFX_DIALOGHISTOGRAMDIS_H__1287D39C_54A2_4825_B124_2F41146912DE__INCLUDED_)
#define AFX_DIALOGHISTOGRAMDIS_H__1287D39C_54A2_4825_B124_2F41146912DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogHistogramDis.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogHistogramDis dialog

class CDialogHistogramDis : public CDialog
{
// Construction
public:
	double histogram[256];
	CDialogHistogramDis(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialogHistogramDis)
	enum { IDD = IDD_HISTOGRAMDISPLAY };
	CStatic	m_cHistogramDis;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogHistogramDis)
	public:
	virtual int DoModal();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogHistogramDis)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGHISTOGRAMDIS_H__1287D39C_54A2_4825_B124_2F41146912DE__INCLUDED_)
