// PropInput.cpp : implementation file
//

#include "stdafx.h"
#include "ImageViewer.h"
#include "PropInput.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropInput dialog


CPropInput::CPropInput(CWnd* pParent /*=NULL*/)
	: CDialog(CPropInput::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPropInput)
	m_nProportion1 = 1.0f;
	m_nProportion2 = 1.0f;
	//}}AFX_DATA_INIT
}


void CPropInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPropInput)
	DDX_Text(pDX, IDC_EDIT1, m_nProportion1);
	DDX_Text(pDX, IDC_EDIT2, m_nProportion2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPropInput, CDialog)
	//{{AFX_MSG_MAP(CPropInput)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropInput message handlers



void CPropInput::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
