// ImageViewerView.cpp : implementation of the CImageViewerView class

//

#include "win.h"

#include "stdafx.h"

#include "ImageViewer.h"
#include "ImageViewerDoc.h"
#include "ImageViewerView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE

static char THIS_FILE[] = __FILE__;

#endif
/*

typedef struct tagBITMAPFILEHEADER {

        WORD    bfType;

        DWORD   bfSize;

        WORD    bfReserved1;

        WORD    bfReserved2;

        DWORD   bfOffBits;

} BITMAPFILEHEADER, FAR *LPBITMAPFILEHEADER, *PBITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER{

        DWORD      biSize;

        LONG       biWidth;

        LONG       biHeight;

        WORD       biPlanes;

        WORD       biBitCount;

        DWORD      biCompression;

        DWORD      biSizeImage;

        LONG       biXPelsPerMeter;

        LONG       biYPelsPerMeter;

        DWORD      biClrUsed;

        DWORD      biClrImportant;

} BITMAPINFOHEADER, FAR *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;

*/

////////////////////////////////////////////////////////////////////////////

// CImageViewerView



IMPLEMENT_DYNCREATE(CImageViewerView, CView)



BEGIN_MESSAGE_MAP(CImageViewerView, CView)

	//{{AFX_MSG_MAP(CImageViewerView)
	ON_COMMAND(ID_OPER_OPEN, OnOperOpen)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_OPEN, OnOperOpen)
	//}}AFX_MSG_MAP

	// Standard printing commands

	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)

	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)

	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)

END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////

// CImageViewerView construction/destruction


CImageViewerView::CImageViewerView()

{

	// TODO: add construction code here

	m_pPicture=new LPPICTURE[10];

	m_bToothOpen=false;

	m_bInvalidRect=false;

	m_bMouseDown=false;
	m_bMouseUp=false;

	memdc=new CDC*[10];

	for(int i=0;i<10;i++)

	{
		memdc[i]=NULL;
		m_pPicture[i]=NULL;
	}

	ProperScale.x=500;ProperScale.y=400;

	m_pointStart.x=0;m_pointStart.y=0;

	m_pointEnd.x=0;m_pointEnd.y=0;

	m_ToothPoint.x=550;m_ToothPoint.y=50;

	m_CurrentPoint.x=200;m_CurrentPoint.y=200;



}



CImageViewerView::~CImageViewerView()

{



	for(int i=0;i<10;i++)

	{
		if(m_pPicture[i])

			m_pPicture[i]->Release();
		if(memdc[i])

			delete memdc[i];

	}

}



BOOL CImageViewerView::PreCreateWindow(CREATESTRUCT& cs)

{

	// TODO: Modify the Window class or styles here by modifying

	//  the CREATESTRUCT cs



	return CView::PreCreateWindow(cs);

}



/////////////////////////////////////////////////////////////////////////////

// CImageViewerView drawing



void CImageViewerView::OnDraw(CDC* pDC)

{

	CImageViewerDoc* pDoc = GetDocument();

	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here

	if(m_pPicture)

	{		
			if(memdc[0])

		pDC->BitBlt(0,0,SAVEWIDTH,SAVEHEIGHT,memdc[0],0,0,SRCCOPY);

			if(memdc[1])

		pDC->BitBlt(500,0,100,100,memdc[1],0,0,SRCCOPY);

			if(memdc[2])

		pDC->BitBlt(500,100,100,100,memdc[2],0,0,SRCCOPY);

			if(memdc[3])

		pDC->BitBlt(500,200,100,100,memdc[3],0,0,SRCCOPY);

			if(memdc[4])

		pDC->BitBlt(500,300,100,100,memdc[4],0,0,SRCCOPY);

			if(memdc[5])

		pDC->BitBlt(500,400,100,100,memdc[5],0,0,SRCCOPY);

			if(memdc[6])

		pDC->BitBlt(500,500,100,100,memdc[6],0,0,SRCCOPY);

			

	if(m_bInvalidRect)

	{

		pDC->Rectangle(m_pointStart.x,m_pointStart.y,m_pointEnd.x,m_pointEnd.y);
//tooth1
		if(m_ToothPoint.x>500 && m_ToothPoint.y<100 && m_pPicture[1])

		{
			for(int j=0;j<m_pointEnd.x-m_pointStart.x-1;j++)
			{
				for(int i=0;i<m_pointEnd.y-m_pointStart.y-1;i++)
				{
					if(!(memdc[1]->GetPixel(j,i)==0xFF))
						pDC->SetPixel(m_pointStart.x+j,m_pointStart.y+i,memdc[1]->GetPixel(j,i));
					else
						pDC->SetPixel(m_pointStart.x+j,m_pointStart.y+i,memdc[0]->GetPixel(m_pointStart.x+j,m_pointStart.y+i));
				}
			}
			for(j=0;j<m_pointEnd.x-m_pointStart.x;j++)
					pDC->SetPixel(m_pointStart.x+j,m_pointEnd.y-1,memdc[0]->GetPixel(m_pointStart.x+j,m_pointEnd.y-1));
			for(int i=0;i<m_pointEnd.y-m_pointStart.y;i++)
					pDC->SetPixel(m_pointEnd.x-1,m_pointStart.y+i,memdc[0]->GetPixel(m_pointEnd.x-1,m_pointStart.y+i));

//			pDC->BitBlt(m_pointStart.x,m_pointStart.y,m_pointEnd.x-m_pointStart.x,m_pointEnd.y-m_pointStart.y,memdc[1],0,0,SRCCOPY);

		}
		if(m_ToothPoint.x>500 && m_ToothPoint.y>100 && m_ToothPoint.y<200 && m_pPicture[2])
//tooth2
		{
			for(int j=0;j<m_pointEnd.x-m_pointStart.x-1;j++)
			{
				for(int i=0;i<m_pointEnd.y-m_pointStart.y-1;i++)
				{
					if(!(memdc[2]->GetPixel(j,i)==0xFF))
						pDC->SetPixel(m_pointStart.x+j,m_pointStart.y+i,memdc[2]->GetPixel(j,i));
					else
						pDC->SetPixel(m_pointStart.x+j,m_pointStart.y+i,memdc[0]->GetPixel(m_pointStart.x+j,m_pointStart.y+i));
				}
			}
			for(j=0;j<m_pointEnd.x-m_pointStart.x;j++)
					pDC->SetPixel(m_pointStart.x+j,m_pointEnd.y-1,memdc[0]->GetPixel(m_pointStart.x+j,m_pointEnd.y-1));
			for(int i=0;i<m_pointEnd.y-m_pointStart.y;i++)
					pDC->SetPixel(m_pointEnd.x-1,m_pointStart.y+i,memdc[0]->GetPixel(m_pointEnd.x-1,m_pointStart.y+i));

//			pDC->BitBlt(m_pointStart.x,m_pointStart.y,m_pointEnd.x-m_pointStart.x,m_pointEnd.y-m_pointStart.y,memdc[2],0,0,SRCCOPY);

		}
		if(m_ToothPoint.x>500 && m_ToothPoint.y>200 && m_ToothPoint.y<300 && m_pPicture[3])
//tooth3			
		{
			for(int j=0;j<m_pointEnd.x-m_pointStart.x-1;j++)
			{
				for(int i=0;i<m_pointEnd.y-m_pointStart.y-1;i++)
				{
					if(!(memdc[3]->GetPixel(j,i)==0xFF))
						pDC->SetPixel(m_pointStart.x+j,m_pointStart.y+i,memdc[3]->GetPixel(j,i));
					else
						pDC->SetPixel(m_pointStart.x+j,m_pointStart.y+i,memdc[0]->GetPixel(m_pointStart.x+j,m_pointStart.y+i));
				}
			}
			for(j=0;j<m_pointEnd.x-m_pointStart.x;j++)
					pDC->SetPixel(m_pointStart.x+j,m_pointEnd.y-1,memdc[0]->GetPixel(m_pointStart.x+j,m_pointEnd.y-1));
			for(int i=0;i<m_pointEnd.y-m_pointStart.y;i++)
					pDC->SetPixel(m_pointEnd.x-1,m_pointStart.y+i,memdc[0]->GetPixel(m_pointEnd.x-1,m_pointStart.y+i));
			
//			pDC->BitBlt(m_pointStart.x,m_pointStart.y,m_pointEnd.x-m_pointStart.x,m_pointEnd.y-m_pointStart.y,memdc[3],0,0,SRCCOPY);
			
		}
		if(m_ToothPoint.x>500 && m_ToothPoint.y>300 && m_ToothPoint.y<400 && m_pPicture[4])
//tooth4			
		{
			for(int j=0;j<m_pointEnd.x-m_pointStart.x-1;j++)
			{
				for(int i=0;i<m_pointEnd.y-m_pointStart.y-1;i++)
				{
					if(!(memdc[4]->GetPixel(j,i)==0xFF))
						pDC->SetPixel(m_pointStart.x+j,m_pointStart.y+i,memdc[4]->GetPixel(j,i));
					else
						pDC->SetPixel(m_pointStart.x+j,m_pointStart.y+i,memdc[0]->GetPixel(m_pointStart.x+j,m_pointStart.y+i));
				}
			}
			for(j=0;j<m_pointEnd.x-m_pointStart.x;j++)
					pDC->SetPixel(m_pointStart.x+j,m_pointEnd.y-1,memdc[0]->GetPixel(m_pointStart.x+j,m_pointEnd.y-1));
			for(int i=0;i<m_pointEnd.y-m_pointStart.y;i++)
					pDC->SetPixel(m_pointEnd.x-1,m_pointStart.y+i,memdc[0]->GetPixel(m_pointEnd.x-1,m_pointStart.y+i));
			
//			pDC->BitBlt(m_pointStart.x,m_pointStart.y,m_pointEnd.x-m_pointStart.x,m_pointEnd.y-m_pointStart.y,memdc[4],0,0,SRCCOPY);
			
		}
		if(m_ToothPoint.x>500 && m_ToothPoint.y>400 && m_ToothPoint.y<500 && m_pPicture[5])
//tooth5			
		{
			for(int j=0;j<m_pointEnd.x-m_pointStart.x-1;j++)
			{
				for(int i=0;i<m_pointEnd.y-m_pointStart.y-1;i++)
				{
					if(!(memdc[5]->GetPixel(j,i)==0xFF))
						pDC->SetPixel(m_pointStart.x+j,m_pointStart.y+i,memdc[5]->GetPixel(j,i));
					else
						pDC->SetPixel(m_pointStart.x+j,m_pointStart.y+i,memdc[0]->GetPixel(m_pointStart.x+j,m_pointStart.y+i));
				}
			}
			for(j=0;j<m_pointEnd.x-m_pointStart.x;j++)
					pDC->SetPixel(m_pointStart.x+j,m_pointEnd.y-1,memdc[0]->GetPixel(m_pointStart.x+j,m_pointEnd.y-1));
			for(int i=0;i<m_pointEnd.y-m_pointStart.y;i++)
					pDC->SetPixel(m_pointEnd.x-1,m_pointStart.y+i,memdc[0]->GetPixel(m_pointEnd.x-1,m_pointStart.y+i));
			
//			pDC->BitBlt(m_pointStart.x,m_pointStart.y,m_pointEnd.x-m_pointStart.x,m_pointEnd.y-m_pointStart.y,memdc[5],0,0,SRCCOPY);
			
		}
		if(m_ToothPoint.x>500 && m_ToothPoint.y>500 && m_ToothPoint.y<600 && m_pPicture[6])
//tooth6			
		{
			for(int j=0;j<m_pointEnd.x-m_pointStart.x-1;j++)
			{
				for(int i=0;i<m_pointEnd.y-m_pointStart.y-1;i++)
				{
					if(!(memdc[6]->GetPixel(j,i)==0xFF))
						pDC->SetPixel(m_pointStart.x+j,m_pointStart.y+i,memdc[6]->GetPixel(j,i));
					else
						pDC->SetPixel(m_pointStart.x+j,m_pointStart.y+i,memdc[0]->GetPixel(m_pointStart.x+j,m_pointStart.y+i));
				}
			}
			for(j=0;j<m_pointEnd.x-m_pointStart.x;j++)
					pDC->SetPixel(m_pointStart.x+j,m_pointEnd.y-1,memdc[0]->GetPixel(m_pointStart.x+j,m_pointEnd.y-1));
			for(int i=0;i<m_pointEnd.y-m_pointStart.y;i++)
					pDC->SetPixel(m_pointEnd.x-1,m_pointStart.y+i,memdc[0]->GetPixel(m_pointEnd.x-1,m_pointStart.y+i));
//			pDC->BitBlt(m_pointStart.x,m_pointStart.y,m_pointEnd.x-m_pointStart.x,m_pointEnd.y-m_pointStart.y,memdc[5],0,0,SRCCOPY);
						
		}
	}
	CPen RedPen(PS_SOLID,2,RGB(255,0,0));
	pDC->SelectObject(&RedPen);
	pDC->MoveTo(0,0);
	pDC->LineTo(500,0);
	pDC->LineTo(500,600);
	pDC->MoveTo(500,400);
	pDC->LineTo(500,0);
	pDC->MoveTo(500,400);
	pDC->LineTo(0,400);
	pDC->LineTo(0,0);
	pDC->MoveTo(0,0);
	pDC->MoveTo(500,0);
	pDC->LineTo(600,0);
	pDC->MoveTo(500,100);
	pDC->LineTo(600,100);
	pDC->MoveTo(500,200);
	pDC->LineTo(600,200);
	pDC->MoveTo(500,300);
	pDC->LineTo(600,300);
	pDC->MoveTo(500,400);
	pDC->LineTo(600,400);
	pDC->MoveTo(500,500);
	pDC->LineTo(600,500);
	pDC->MoveTo(500,600);
	pDC->LineTo(600,600);
	pDC->LineTo(600,0);
}

}



/////////////////////////////////////////////////////////////////////////////

// CImageViewerView printing



BOOL CImageViewerView::OnPreparePrinting(CPrintInfo* pInfo)

{

	// default preparation

	return DoPreparePrinting(pInfo);

}



void CImageViewerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)

{

	// TODO: add extra initialization before printing

}



void CImageViewerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)

{

	// TODO: add cleanup after printing

}



/////////////////////////////////////////////////////////////////////////////

// CImageViewerView diagnostics



#ifdef _DEBUG

void CImageViewerView::AssertValid() const

{

	CView::AssertValid();

}



void CImageViewerView::Dump(CDumpContext& dc) const

{

	CView::Dump(dc);

}



CImageViewerDoc* CImageViewerView::GetDocument() // non-debug version is inline

{

	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageViewerDoc)));

	return (CImageViewerDoc*)m_pDocument;

}

#endif //_DEBUG



/////////////////////////////////////////////////////////////////////////////

// CImageViewerView message handlers



void CImageViewerView::OnOperOpen() 

{

	// TODO: Add your command handler code here

	//save the filename

	TCHAR szFile[MAX_PATH];

	ZeroMemory(szFile,MAX_PATH);

	OPENFILENAME ofn;

	ZeroMemory(&ofn,sizeof(OPENFILENAME));

	ofn.lStructSize=sizeof(OPENFILENAME);

	ofn.Flags=OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST|OFN_HIDEREADONLY;

	ofn.hwndOwner=m_hWnd;

	ofn.lpstrFilter=_T("Supported Files Types(*.bmp;*.gif;*.jpg;*.ico;*.emf;*.wmf)\0*.bmp;*.gif;*.jpg;*.ico;*.emf;*.wmf\0Bitmaps(*.bmp)\0*.bmp\0GIF Files(*.gif)\0*.gif\0JPEG Files(*.jpg)\0*.jpg\0Icons(*.ico)\0*.ico\0Enhanced Metafiles(*.emf)\0*.emf\0Windows Metafiles(*.wmf)\0*.wmf\0\0");

	ofn.lpstrTitle=_T("选择图片");

	ofn.lpstrFile=szFile;

	ofn.nMaxFile=MAX_PATH;

	if(IDOK==GetOpenFileName(&ofn))

		LoadPicture(szFile);

//Load success

	m_bInvalidRect=false;

}

void CImageViewerView::LoadPicture(CString strFile) 

{

	//load the picture to LPPICTURE m_pPicture

	HANDLE hFile=CreateFile(strFile,GENERIC_READ,0,NULL,OPEN_EXISTING,0,NULL);

	_ASSERTE(INVALID_HANDLE_VALUE!=hFile);

	DWORD dwFileSize=GetFileSize(hFile,NULL);

	_ASSERTE(-1!=dwFileSize);

	LPVOID pvData =NULL;

	HGLOBAL hGlobal=GlobalAlloc(GMEM_MOVEABLE,dwFileSize);

	_ASSERTE(NULL!=hGlobal);

	pvData=GlobalLock(hGlobal);

	_ASSERTE(NULL!=pvData);

	DWORD dwBytesRead=0;

	BOOL bRead=ReadFile(hFile,pvData,dwFileSize,&dwBytesRead,NULL);

	_ASSERTE(FALSE!=bRead);

	GlobalUnlock(hGlobal);

	CloseHandle(hFile);

	LPSTREAM pstm=NULL;

	HRESULT hr=CreateStreamOnHGlobal(hGlobal,TRUE,&pstm);

	_ASSERTE (SUCCEEDED(hr) && pstm);

	if(m_pPicture[0])

		m_pPicture[0]->Release();

	hr=::OleLoadPicture(pstm,dwFileSize,FALSE,IID_IPicture,(LPVOID *)&m_pPicture[0]);

	_ASSERTE(SUCCEEDED(hr) && m_pPicture[0]);

	pstm->Release();

	//输出宽和高，读入位图到客户区内存

//		CRect rc;

		GetClientRect(&rc);

		CDC *pDC=CDC::FromHandle(::GetDC(NULL));

		m_pPicture[0]->get_Width(&hmWidth);

		m_pPicture[0]->get_Height(&hmHeight);

		nOrigWidth=MulDiv(hmWidth,GetDeviceCaps(pDC->GetSafeHdc(),LOGPIXELSX),HIMETRIC_INCH);

		nOrigHeight=MulDiv(hmHeight,GetDeviceCaps(pDC->GetSafeHdc(),LOGPIXELSY),HIMETRIC_INCH);

		nWidth=nOrigWidth;nHeight=nOrigHeight;

		Proportion1=ProperScale.x/(float)nWidth;

		Proportion2=ProperScale.y/(float)nHeight;

		if(memdc[0])

			delete memdc[0];

		memdc[0]=new CDC;

		memdc[0]->CreateCompatibleDC(pDC);

		CBitmap bmp;

		bmp.CreateCompatibleBitmap(pDC,nWidth,nHeight);

		memdc[0]->SelectObject(bmp);

		::ReleaseDC(::GetDesktopWindow(),pDC->GetSafeHdc());

	//将图片自动缩放到内存DC

	memdc[0]=this->Zoom(&nWidth,&nHeight,SAVEWIDTH,SAVEHEIGHT,memdc[0]);			

	m_pPicture[0]->Render(memdc[0]->GetSafeHdc(),0,0,nWidth,nHeight,0,hmHeight,hmWidth,-hmHeight,&rc);

	Invalidate();
}

void CImageViewerView::OnLButtonDown(UINT nFlags, CPoint point) 

{

	// TODO: Add your message handler code here and/or call default
	m_bMouseUp=false;
	if(point.x<500)

		m_pointStart=point;

	else

	{

		m_ToothPoint=point;

		if(m_bInvalidRect)

		{

			Invalidate();

			if(m_ToothPoint.x>500 && m_ToothPoint.y<100 && memdc[1])

			{
	
			memdc[1]=this->RenderToMemory(m_pPicture[1],memdc[1],m_pointEnd.x-m_pointStart.x,m_pointEnd.y-m_pointStart.y);

			Invalidate();

			}
			if(m_ToothPoint.x>500 && m_ToothPoint.y<200 && m_ToothPoint.y>100 && memdc[2])

			{

			memdc[2]=this->RenderToMemory(m_pPicture[2],memdc[2],m_pointEnd.x-m_pointStart.x,m_pointEnd.y-m_pointStart.y);

			Invalidate();

			}
			if(m_ToothPoint.x>500 && m_ToothPoint.y<300 && m_ToothPoint.y>200 && memdc[3])
				
			{
				
				memdc[3]=this->RenderToMemory(m_pPicture[3],memdc[3],m_pointEnd.x-m_pointStart.x,m_pointEnd.y-m_pointStart.y);
				
				Invalidate();
				
			}
			if(m_ToothPoint.x>500 && m_ToothPoint.y<400 && m_ToothPoint.y>300 && memdc[4])
				
			{
				
				memdc[4]=this->RenderToMemory(m_pPicture[4],memdc[4],m_pointEnd.x-m_pointStart.x,m_pointEnd.y-m_pointStart.y);
				
				Invalidate();
				
			}
			if(m_ToothPoint.x>500 && m_ToothPoint.y<500 && m_ToothPoint.y>400 && memdc[5])
				
			{
				
				memdc[5]=this->RenderToMemory(m_pPicture[5],memdc[5],m_pointEnd.x-m_pointStart.x,m_pointEnd.y-m_pointStart.y);
				
				Invalidate();
				
			}
			if(m_ToothPoint.x>500 && m_ToothPoint.y<600 && m_ToothPoint.y>500 && memdc[6])
				
			{
				
				memdc[6]=this->RenderToMemory(m_pPicture[6],memdc[6],m_pointEnd.x-m_pointStart.x,m_pointEnd.y-m_pointStart.y);
				
				Invalidate();
				
			}
			


		}

//		Invalidate();

	}



	m_bMouseDown=true;



	CView::OnLButtonDown(nFlags, point);

}



void CImageViewerView::OnLButtonUp(UINT nFlags, CPoint point) 

{

	// TODO: Add your message handler code here and/or call default

	m_bMouseDown=false;

	if(point.x<500 && !(m_pointStart.x==0 && m_pointStart.y==0))

	{
		m_bMouseUp=true;
		m_bInvalidRect=true;
		m_pointEnd=point;		
	}
	Invalidate();	

	CView::OnLButtonUp(nFlags, point);
}

void CImageViewerView::OnMouseMove(UINT nFlags, CPoint point) 

{

	// TODO: Add your message handler code here and/or call default
	m_CurrentPoint=point;
	if(point.x<500 && !m_bMouseUp)
		m_pointEnd=point;
	if(m_bMouseDown && !m_bMouseUp) 
	{
		m_bInvalidRect=true;
	}
	else
		m_bInvalidRect=false;
	if(m_bMouseUp)
		m_bInvalidRect=true;
	if(m_bMouseDown)
		Invalidate();

	CView::OnMouseMove(nFlags, point);
}



CDC* CImageViewerView::CreateNewBitmap(int width, int height)

{

	CDC* pDesktopDC=CDC::FromHandle(::GetDC(NULL));

	CDC* ptempDC=new CDC;

	ptempDC->CreateCompatibleDC(pDesktopDC);

	CBitmap bmp;

	bmp.CreateCompatibleBitmap(pDesktopDC,width,height);

	ptempDC->SelectObject(bmp);

	::ReleaseDC(::GetDesktopWindow(),pDesktopDC->GetSafeHdc());

	return ptempDC;

}



CDC* CImageViewerView::Zoom(int* nWidth, int* nHeight, 

	int ProperScalex, int ProperScaley, CDC* memdc)

{

	float Proportion1=ProperScalex/(float)*nWidth;

	float Proportion2=ProperScaley/(float)*nHeight;

		CDC* pNewDC=this->CreateNewBitmap((int)(*nWidth*Proportion1),(int)(*nHeight*Proportion2));

		for(int i=0;i<(int)(*nHeight*Proportion2);i++)

		{

			for(int j=0;j<(int)(*nWidth*Proportion1);j++)

			pNewDC->SetPixel(j,i,memdc->GetPixel((int)(j/Proportion1),(int)(i/Proportion2)));

		}

		*nWidth=(int)(*nWidth*Proportion1);

		*nHeight=(int)(*nHeight*Proportion2);

		delete memdc;

		memdc=pNewDC;

		return memdc;

}



void CImageViewerView::OnLButtonDblClk(UINT nFlags, CPoint point) 

{

	m_PointDouble=point;



	//tooth1
	if(point.x<500 && point.y<400)
		this->OnOperOpen();
	if(point.x>500 && point.y<100)

	{	

		m_OrigPoint.x=500;m_OrigPoint.y=0;

		ProperScale.x=100;ProperScale.y=100;

		m_pPicture[1]=this->LoadToothName(m_pPicture[1]);

		memdc[1]=this->RenderToMemory(m_pPicture[1],memdc[1]);

		Invalidate();

	}





	//tooth2

	else if(point.x>500 && point.y<200 && point.y>=100)

	{

		m_OrigPoint.x=500;m_OrigPoint.y=100;

		ProperScale.x=100;ProperScale.y=100;

		m_pPicture[2]=this->LoadToothName(m_pPicture[2]);

		memdc[2]=this->RenderToMemory(m_pPicture[2],memdc[2]);

		Invalidate();

	}



		//tooth3

	else if(point.x>500 && point.y<300 && point.y>=200)

	{

		m_OrigPoint.x=500;m_OrigPoint.y=200;

		ProperScale.x=100;ProperScale.y=100;

		m_pPicture[3]=this->LoadToothName(m_pPicture[3]);

		memdc[3]=this->RenderToMemory(m_pPicture[3],memdc[3]);

		Invalidate();

	}



		//tooth4

	else if(point.x>500 && point.y<400 && point.y>=300)

	{

		m_OrigPoint.x=500;m_OrigPoint.y=300;

		ProperScale.x=100;ProperScale.y=100;

		m_pPicture[4]=this->LoadToothName(m_pPicture[4]);

		memdc[4]=this->RenderToMemory(m_pPicture[4],memdc[4]);

		Invalidate();

	}



		//tooth5

	else if(point.x>500 && point.y<500 && point.y>=400)

	{

		m_OrigPoint.x=500;m_OrigPoint.y=400;

		ProperScale.x=100;ProperScale.y=100;

		m_pPicture[5]=this->LoadToothName(m_pPicture[5]);

		memdc[5]=this->RenderToMemory(m_pPicture[5],memdc[5]);

		Invalidate();

	}



		//tooth6

	else if(point.x>500 && point.y<600 && point.y>=500)

	{

		m_OrigPoint.x=500;m_OrigPoint.y=500;

		ProperScale.x=100;ProperScale.y=100;

		m_pPicture[6]=this->LoadToothName(m_pPicture[6]);

		memdc[6]=this->RenderToMemory(m_pPicture[6],memdc[6]);

		Invalidate();

	}

	else

//		Invalidate();



	CView::OnLButtonDblClk(nFlags, point);

}



LPPICTURE CImageViewerView::LoadToothName(LPPICTURE m_pPicture)

{//load the single tooth picture to LPPICTURE m_pPicture

	TCHAR szFile[MAX_PATH];

	ZeroMemory(szFile,MAX_PATH);

	OPENFILENAME ofn;

	ZeroMemory(&ofn,sizeof(OPENFILENAME));

	ofn.lStructSize=sizeof(OPENFILENAME);

	ofn.Flags=OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST|OFN_HIDEREADONLY;

	ofn.hwndOwner=m_hWnd;

	ofn.lpstrFilter=_T("Supported Files Types(*.bmp;*.gif;*.jpg;*.ico;*.emf;*.wmf)\0*.bmp;*.gif;*.jpg;*.ico;*.emf;*.wmf\0Bitmaps(*.bmp)\0*.bmp\0GIF Files(*.gif)\0*.gif\0JPEG Files(*.jpg)\0*.jpg\0Icons(*.ico)\0*.ico\0Enhanced Metafiles(*.emf)\0*.emf\0Windows Metafiles(*.wmf)\0*.wmf\0\0");

	ofn.lpstrTitle=_T("选择图片");

	ofn.lpstrFile=szFile;

	ofn.nMaxFile=MAX_PATH;

	m_bInvalidRect=false;

	if(IDOK==GetOpenFileName(&ofn))

	{

	HANDLE hFile=CreateFile(szFile,GENERIC_READ,0,NULL,OPEN_EXISTING,0,NULL);

	_ASSERTE(INVALID_HANDLE_VALUE!=hFile);

	DWORD dwFileSize=GetFileSize(hFile,NULL);

	_ASSERTE(-1!=dwFileSize);

	LPVOID pvData =NULL;

	HGLOBAL hGlobal=GlobalAlloc(GMEM_MOVEABLE,dwFileSize);

	_ASSERTE(NULL!=hGlobal);

	pvData=GlobalLock(hGlobal);

	_ASSERTE(NULL!=pvData);

	DWORD dwBytesRead=0;

	BOOL bRead=ReadFile(hFile,pvData,dwFileSize,&dwBytesRead,NULL);

	_ASSERTE(FALSE!=bRead);

	GlobalUnlock(hGlobal);

	CloseHandle(hFile);

	LPSTREAM pstm=NULL;

	HRESULT hr=CreateStreamOnHGlobal(hGlobal,TRUE,&pstm);

	_ASSERTE (SUCCEEDED(hr) && pstm);

	if(m_pPicture)

		m_pPicture->Release();

	hr=::OleLoadPicture(pstm,dwFileSize,FALSE,IID_IPicture,(LPVOID *)&m_pPicture);

	_ASSERTE(SUCCEEDED(hr) && m_pPicture);

	pstm->Release();

	if(m_pPicture)

		m_bToothOpen=true;

	}
	return m_pPicture;
}



CDC* CImageViewerView::RenderToMemory(LPPICTURE m_pPicture,CDC* memdc)

{

	if(m_bToothOpen)

		{

		GetClientRect(&rc);

		CDC *pDC=CDC::FromHandle(::GetDC(NULL));

		m_pPicture->get_Width(&hmWidth);

		m_pPicture->get_Height(&hmHeight);

		nOrigWidth=MulDiv(hmWidth,GetDeviceCaps(pDC->GetSafeHdc(),LOGPIXELSX),HIMETRIC_INCH);

		nOrigHeight=MulDiv(hmHeight,GetDeviceCaps(pDC->GetSafeHdc(),LOGPIXELSY),HIMETRIC_INCH);

		nWidth=nOrigWidth;nHeight=nOrigHeight;

		Proportion1=ProperScale.x/(float)nWidth;

		Proportion2=ProperScale.y/(float)nHeight;
		//the above get the tooth width,height,and zoom proportion

		if(memdc)

			delete memdc;

		memdc=new CDC;

		memdc->CreateCompatibleDC(pDC);

		CBitmap bmp;

		bmp.CreateCompatibleBitmap(pDC,nWidth,nHeight);

		memdc->SelectObject(bmp);

		::ReleaseDC(::GetDesktopWindow(),pDC->GetSafeHdc());

	memdc=this->Zoom(&nWidth,&nHeight,ProperScale.x,ProperScale.y,memdc);			

	m_pPicture->Render(memdc->GetSafeHdc(),0,0,nWidth,nHeight,0,hmHeight,hmWidth,-hmHeight,&rc);

//	m_bToothOpen=false;

	}

	return memdc;

}



CDC* CImageViewerView::RenderToMemory(LPPICTURE m_pPicture,CDC *memdc, int ProperScalex, int ProperScaley)

{

		if(m_bToothOpen)

		{

		GetClientRect(&rc);

		CDC *pDC=CDC::FromHandle(::GetDC(NULL));

		m_pPicture->get_Width(&hmWidth);

		m_pPicture->get_Height(&hmHeight);

		nOrigWidth=MulDiv(hmWidth,GetDeviceCaps(pDC->GetSafeHdc(),LOGPIXELSX),HIMETRIC_INCH);

		nOrigHeight=MulDiv(hmHeight,GetDeviceCaps(pDC->GetSafeHdc(),LOGPIXELSY),HIMETRIC_INCH);

		nWidth=nOrigWidth;nHeight=nOrigHeight;

		Proportion1=ProperScalex/(float)nWidth;

		Proportion2=ProperScaley/(float)nHeight;

		if(memdc)

			delete memdc;

		memdc=new CDC;

		memdc->CreateCompatibleDC(pDC);

		CBitmap bmp;

		bmp.CreateCompatibleBitmap(pDC,nWidth,nHeight);

		memdc->SelectObject(bmp);

		::ReleaseDC(::GetDesktopWindow(),pDC->GetSafeHdc());

	memdc=this->Zoom(&nWidth,&nHeight,ProperScalex,ProperScaley,memdc);			
	m_pPicture->Render(memdc->GetSafeHdc(),0,0,nWidth,nHeight,0,hmHeight,hmWidth,-hmHeight,&rc);
		}

	return memdc;
}
bool CImageViewerView::SaveBmpFile(int width,int height,char *pdata)  //save rgb 

{	
	CFile cfile;
	char BASED_CODE szFilter[]="Bitmap Files(*.bmp)|*.bmp|JPG Files(*.jpg)|*.jpg|Text files(*.txt)|*.txt||";
	CFileDialog m_ldFile(false,"*.bmp",NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,szFilter);
	if(m_ldFile.DoModal()!=IDOK)
	{
		return false;
	}
	if(cfile.Open(m_ldFile.GetPathName(),CFile::modeCreate|CFile::modeReadWrite ,NULL)==NULL)
	{
		return false;
	}
	BITMAPFILEHEADER bitfile;  //file head
	BITMAPINFOHEADER bitinfo;  //infor head 
	//	    LPBITMAPFILEHEADER bitfile;
	//  LPBITMAPINFOHEADER bitinfo;
	bitfile.bfOffBits=54;
	bitfile.bfReserved1=0;
	bitfile.bfReserved2=0;
	bitfile.bfSize=54+width*height*3;
	bitfile.bfType=0x4d42;
	
	bitinfo.biBitCount=24;
	bitinfo.biXPelsPerMeter=0;
	bitinfo.biYPelsPerMeter=0;
	bitinfo.biSize=40;
	bitinfo.biPlanes=1;
	bitinfo.biSizeImage=54+width*height*3;
	bitinfo.biClrUsed=0;
	bitinfo.biCompression=0;
	bitinfo.biHeight=height;
	bitinfo.biWidth=width;
	bitinfo.biClrImportant=0;
	cfile.Write((char*)&bitfile,sizeof(BITMAPFILEHEADER));
	cfile.Seek(14,CFile::begin);
	cfile.Write((char*)&bitinfo,sizeof(BITMAPINFOHEADER));
	cfile.Seek(54,CFile::begin);
	cfile.Write(pdata,height*width*3);
	return true;	
}


void CImageViewerView::OnFileSave() 
{
	// TODO: Add your command handler code here

	CDC *mycdc;
	mycdc=this->GetDC();// get ClientDC
	
	COLORREF color;//#define RGB(r,g,b)  ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
	char *pdata=new char[SAVEWIDTH*SAVEHEIGHT*3];
	for(int i=0;i<SAVEHEIGHT;i++)
	{
		for(int j=0;j<SAVEWIDTH;j++)
		{
			color=mycdc->GetPixel(j,i);
			R=((BYTE)(color))&(0xFF);
			G=((BYTE)(color>>8))&(0xFF);
			B=((BYTE)(color>>16))&(0xFF);

			*(pdata+(SAVEHEIGHT-i-1)*SAVEWIDTH*3+j*3+0)=B;
			*(pdata+(SAVEHEIGHT-i-1)*SAVEWIDTH*3+j*3+1)=G;
			*(pdata+(SAVEHEIGHT-i-1)*SAVEWIDTH*3+j*3+2)=R;
		}
	}

	this->SaveBmpFile(SAVEWIDTH,SAVEHEIGHT,pdata);
	delete []pdata;	
}
