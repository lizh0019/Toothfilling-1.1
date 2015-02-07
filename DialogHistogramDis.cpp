// DialogHistogramDis.cpp : implementation file
//

#include "stdafx.h"
#include "ColorEnhansement.h"
#include "DialogHistogramDis.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogHistogramDis dialog


CDialogHistogramDis::CDialogHistogramDis(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogHistogramDis::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogHistogramDis)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDialogHistogramDis::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogHistogramDis)
	DDX_Control(pDX, IDC_HISTOGRAMDIS, m_cHistogramDis);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogHistogramDis, CDialog)
	//{{AFX_MSG_MAP(CDialogHistogramDis)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogHistogramDis message handlers

int CDialogHistogramDis::DoModal() 
{
	// TODO: Add your specialized code here and/or call the base class
//	MessageBox("ijvepir");

	return CDialog::DoModal();
}

void CDialogHistogramDis::OnOK() 
{
	// TODO: Add extra validation here
	CDC *pDC=this->m_cHistogramDis.GetDC();
	m_cHistogramDis.MoveWindow(50,20,255,255);
	pDC->Rectangle(0,0,255,255);
	int o_x=0,o_y=255;
//	pDC->MoveTo(o_x,o_y);
//	pDC->LineTo(o_x+255,o_y-255);
	for(int i=0;i<256;i++)
	{	
		pDC->MoveTo(o_x+i,o_y);
		pDC->LineTo(o_x+i,o_y-histogram[i]);	
	}
	m_cHistogramDis.UpdateWindow();
//	CDialog::OnOK();
}
