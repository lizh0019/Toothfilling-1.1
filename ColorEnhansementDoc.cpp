// ColorEnhansementDoc.cpp : implementation of the CColorEnhansementDoc class
//

#include "stdafx.h"
#include "ColorEnhansement.h"
#include"math.h"
#include "ColorEnhansementDoc.h"
#include"DialogHistogramDis.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorEnhansementDoc

IMPLEMENT_DYNCREATE(CColorEnhansementDoc, CDocument)

BEGIN_MESSAGE_MAP(CColorEnhansementDoc, CDocument)
	//{{AFX_MSG_MAP(CColorEnhansementDoc)
	ON_COMMAND(ID_ENHAN, OnEnhan)
	ON_UPDATE_COMMAND_UI(ID_ENHAN, OnUpdateEnhan)
	ON_UPDATE_COMMAND_UI(ID_EN, OnUpdateEn)
	ON_COMMAND(ID_DISPLAYHISTOGRAM, OnDisplayhistogram)
	ON_UPDATE_COMMAND_UI(ID_DISPLAYHISTOGRAM, OnUpdateDisplayhistogram)
	ON_COMMAND(DISPLAY_TRANSFORM, OnTransform)
	ON_UPDATE_COMMAND_UI(DISPLAY_TRANSFORM, OnUpdateTransform)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorEnhansementDoc construction/destruction

CColorEnhansementDoc::CColorEnhansementDoc()
{
	// TODO: add one-time construction code here
	m_bFileOpened=false;
	m_bPorcessed=false;

}

CColorEnhansementDoc::~CColorEnhansementDoc()
{
	if(this->m_bFileOpened)
	{
		delete[]pBmpMemory;
		delete[]this->pProcessingMemory;
	}

}

BOOL CColorEnhansementDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CColorEnhansementDoc serialization

void CColorEnhansementDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CColorEnhansementDoc diagnostics

#ifdef _DEBUG
void CColorEnhansementDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CColorEnhansementDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CColorEnhansementDoc commands

BOOL CColorEnhansementDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	m_bPorcessed=false;//m_bPorcessed:图像是否经过处理标志
	CFile bmpfile;
	if(bmpfile.Open(lpszPathName,CFile::modeRead,NULL)==NULL)
	{
		MessageBox(NULL," Open file error","system information",MB_OK);
		return true;
	}
	if (this->m_bFileOpened==true)
	{
		delete[]pBmpMemory;
	}
	this->m_iBmpLength=bmpfile.GetLength();
	pBmpMemory=new unsigned char[m_iBmpLength];//开辟内存,
	this->pProcessingMemory=new unsigned char[m_iBmpLength];//开辟内存
	m_bFileOpened=true;    ///file opened 
	bmpfile.Read(pBmpMemory,m_iBmpLength);
	LPBITMAPFILEHEADER bitfile;
    LPBITMAPINFOHEADER bitinfo;
	bitfile=(LPBITMAPFILEHEADER)pBmpMemory;
	bitinfo=(LPBITMAPINFOHEADER)(pBmpMemory+sizeof(BITMAPFILEHEADER));
	this->m_iBmpBfts=bitfile->bfOffBits;
	this->m_iBmpHeight=bitinfo->biHeight;
	this->m_iBmpWidth=bitinfo->biWidth;
	if (bitinfo->biBitCount!=8)
	{
		MessageBox(NULL,"This bmp is not 8 bits","system information",MB_OK);
		delete[]pBmpMemory;
		this->m_bFileOpened=false;
		return true;

	}
	pPixMemory=pBmpMemory+this->m_iBmpBfts;
	return TRUE;
}

void CColorEnhansementDoc::OnEnhan() 
{
	// TODO: Add your command handler code here
	if (!this->m_bFileOpened) 
	{
		MessageBox(NULL,"error","system information",MB_OK);
		return ;

	}
	for(int i=0;i<this->m_iBmpHeight;i++)
		for(int j=0;j<this->m_iBmpWidth;j++)
		{
			if(*(pPixMemory+i*m_iBmpWidth+j)<128)
				*(pProcessingMemory+i*m_iBmpWidth+j)=0;
			else 
				*(pProcessingMemory+i*m_iBmpWidth+j)=255;
		}
		this->m_bPorcessed=true;
	UpdateAllViews(NULL);
}

/*void CColorEnhansementDoc::GrayLinear()
{
for(i=0;i<=nX1,i++)
{
	if(nX1>0)
	{
		byMap[i]=(int)nY1*i/nX1;
	}
	else
	{
		byMap[i]=0;
	}
}
for(;i<=nX2;i++)
{
	if(nX2!=nX1)
	{
		byMap[i]=nY1+(int)((nY2-nY1)*(i-nX1)/(nX2-nX1));
	}
	else
	{
		byMap[i]=nY1;
	}
}
for(;i<=255;i++)
{
	if(nX2!=255)
	{
		byMap[i]=nY2+(int)((255-nY2)*(i-nX2)/(255-nX2));
	}
	else
	{
		byMap[i]=255;
	}
}



  





}
*/
void CColorEnhansementDoc::linear()
{

dialog1 dlg;
dlg.DoModal();
int nX1,nY1,nX2,nY2,byMap[256];
nX1=dlg.m_x1;
nY1=dlg.m_y1;
nX1=dlg.m_x2;
nY1=dlg.m_y2;
for(int i=0;i<=nX1;i++)
{
	if(nX1>0)
	{
		byMap[i]=(int)nY1*i/nX1;
	}
	else
	{
		byMap[i]=0;
	}
}
for(;i<=nX2;i++)
{
	if(nX2!=nX1)
	{
		byMap[i]=nY1+(int)((nY2-nY1)*(i-nX1)/(nX2-nX1));
	}
	else
	{
		byMap[i]=nY1;
	}
}
for(;i<=255;i++)
{
	if(nX2!=255)
	{
		byMap[i]=nY2+(int)((255-nY2)*(i-nX2)/(255-nX2));
	}
	else
	{
		byMap[i]=255;
	}
}

	for(i=0;i<this->m_iBmpHeight;i++)
		for(int j=0;j<this->m_iBmpWidth;j++)
		*(pProcessingMemory+i*m_iBmpWidth+j)=byMap[*(pPixMemory+i*m_iBmpWidth+j)];

		m_bPorcessed=true;//经过处理
		UpdateAllViews(NULL);
}

void CColorEnhansementDoc::OnUpdateEnhan(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(this->m_bFileOpened==false)
		pCmdUI->Enable(false);
	else
	pCmdUI->Enable(true);
}

void CColorEnhansementDoc::OnUpdateEn(CCmdUI* pCmdUI) 
{
	if(this->m_bFileOpened==false)
		pCmdUI->Enable(false);
	else
	pCmdUI->Enable(true);	
}

void CColorEnhansementDoc::OnDisplayhistogram() 
{
	// TODO: Add your command handler code here
	double  histogram[256];
	int i,j;
	for(i=0;i<256;i++)
		histogram[i]=0;
	for(i=0;i<m_iBmpHeight;i++)
		for(j=0;j<m_iBmpWidth;j++)
		histogram[*(pPixMemory+i*m_iBmpWidth+j)]=histogram[*(pPixMemory+i*m_iBmpWidth+j)]+1;
	int max=histogram[0];
	for(i=0;i<255;i++)
	{
		if(max<histogram[i])
			max=histogram[i];	
	}
	for(i=0;i<256;i++)
		histogram[i]=histogram[i]/max*255;
	CDialogHistogramDis display;
	for(i=0;i<256;i++)
		display.histogram[i]=histogram[i];
	display.DoModal();


	
}

void CColorEnhansementDoc::OnUpdateDisplayhistogram(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		if(this->m_bFileOpened==false)
		pCmdUI->Enable(false);
		else
		pCmdUI->Enable(true);
	
}

void CColorEnhansementDoc::OnTransform() 
{
	// TODO: Add your command handler code here
	double  histogram[256];
	int i,j;
	for(i=0;i<256;i++)
		histogram[i]=0;
	for(i=0;i<m_iBmpHeight;i++)
		for(j=0;j<m_iBmpWidth;j++)
		histogram[*(pProcessingMemory+i*m_iBmpWidth+j)]=histogram[*(pProcessingMemory+i*m_iBmpWidth+j)]+1;
	int max=histogram[0];
	for(i=0;i<255;i++)
	{
		if(max<histogram[i])
			max=histogram[i];	
	}
	for(i=0;i<256;i++)
		histogram[i]=histogram[i]/max*255;
	CDialogHistogramDis display;
	for(i=0;i<256;i++)
		display.histogram[i]=histogram[i];
	display.DoModal();	
}

void CColorEnhansementDoc::OnUpdateTransform(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		if(this->m_bFileOpened==false||this->m_bPorcessed==false)
		pCmdUI->Enable(false);
		else
		pCmdUI->Enable(true);
}
