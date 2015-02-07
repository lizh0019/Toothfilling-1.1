// dialog1.cpp : implementation file
//

#include "stdafx.h"
#include "ColorEnhansement.h"
#include "dialog1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// dialog1 dialog


dialog1::dialog1(CWnd* pParent /*=NULL*/)
	: CDialog(dialog1::IDD, pParent)
{
	//{{AFX_DATA_INIT(dialog1)
	m_x1 = 10;
	m_y1 = 10;
	m_x2 = 100;
	m_y2 = 100;
	m_bMoved=false;
	//}}AFX_DATA_INIT
}


void dialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(dialog1)
	DDX_Control(pDX, IDC_HISTOGRAM, m_cHistogram);
	DDX_Text(pDX, IDC_EDIT1, m_x1);
	DDV_MinMaxInt(pDX, m_x1, 0, 255);
	DDX_Text(pDX, IDC_EDIT2, m_y1);
	DDV_MinMaxInt(pDX, m_y1, 0, 255);
	DDX_Text(pDX, IDC_EDIT3, m_x2);
	DDV_MinMaxInt(pDX, m_x2, 0, 255);
	DDX_Text(pDX, IDC_EDIT4, m_y2);
	DDV_MinMaxInt(pDX, m_y2, 0, 255);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(dialog1, CDialog)
	//{{AFX_MSG_MAP(dialog1)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeData)
	ON_EN_CHANGE(IDC_EDIT2, OnChangeData)
	ON_EN_CHANGE(IDC_EDIT3, OnChangeData)
	ON_EN_CHANGE(IDC_EDIT4, OnChangeData)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// dialog1 message handlers

void dialog1::OnChangeData() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here

//MessageBox("dj9ifejiop");

	this->OnPaint();

	
}

BOOL dialog1::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::OnNotify(wParam, lParam, pResult);
}

void dialog1::OnPaint()
{
		if(m_bMoved==false)
	{
		m_cHistogram.MoveWindow(280,55,260,260);
		m_bMoved=true;
	}
	UpdateData(true);
	CDC *pDC=this->m_cHistogram.GetDC();
	pDC->Rectangle(0,0,260,260);
	int o_x=0,o_y=260;

	pDC->MoveTo(o_x,o_y);
	pDC->LineTo(o_x+m_x1,o_y-m_y1);
//	pDC->TextOut(o_x+m_x1+10,o_y-m_y1-10,"djfi");
	pDC->LineTo(o_x+m_x2,o_y-m_y2);
	pDC->LineTo(o_x+255,o_y-255);
	m_cHistogram.UpdateWindow();

}
