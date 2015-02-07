// ColorEnhansementView.cpp : implementation of the CColorEnhansementView class
//

#include "stdafx.h"
#include "ColorEnhansement.h"

#include "ColorEnhansementDoc.h"
#include "ColorEnhansementView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorEnhansementView

IMPLEMENT_DYNCREATE(CColorEnhansementView, CView)

BEGIN_MESSAGE_MAP(CColorEnhansementView, CView)
	//{{AFX_MSG_MAP(CColorEnhansementView)
	ON_COMMAND(ID_EN, OnEn)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorEnhansementView construction/destruction

CColorEnhansementView::CColorEnhansementView()
{
	// TODO: add construction code here

}

CColorEnhansementView::~CColorEnhansementView()
{
}

BOOL CColorEnhansementView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CColorEnhansementView drawing

void CColorEnhansementView::OnDraw(CDC* pDC)
{
	CColorEnhansementDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	if(!(pDoc->m_bFileOpened))
	  {
		  
		  pDC->Rectangle(100,30,100+300,30+200);

	  }
	  else
	  {		
	::StretchDIBits(pDC->m_hDC,
		10,
		10,
		pDoc->m_iBmpWidth,
		pDoc->m_iBmpHeight,
		0,
		0,
		pDoc->m_iBmpWidth,
		pDoc->m_iBmpHeight,
		pDoc->pPixMemory,
		(BITMAPINFO *)(pDoc->pBmpMemory+sizeof(BITMAPFILEHEADER)),
		DIB_RGB_COLORS,
		SRCCOPY);
	  }
	  if(pDoc->m_bPorcessed==true)
	  {
		  ::StretchDIBits(pDC->m_hDC,
		10+pDoc->m_iBmpWidth+20,
		10,
		pDoc->m_iBmpWidth,
		pDoc->m_iBmpHeight,
		0,
		0,
		pDoc->m_iBmpWidth,
		pDoc->m_iBmpHeight,
		pDoc->pProcessingMemory,
		(BITMAPINFO *)(pDoc->pBmpMemory+sizeof(BITMAPFILEHEADER)),
		DIB_RGB_COLORS,
		SRCCOPY);

	  }

}

/////////////////////////////////////////////////////////////////////////////
// CColorEnhansementView printing

BOOL CColorEnhansementView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CColorEnhansementView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CColorEnhansementView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CColorEnhansementView diagnostics

#ifdef _DEBUG
void CColorEnhansementView::AssertValid() const
{
	CView::AssertValid();
}

void CColorEnhansementView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CColorEnhansementDoc* CColorEnhansementView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CColorEnhansementDoc)));
	return (CColorEnhansementDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CColorEnhansementView message handlers



void CColorEnhansementView::OnEn() 
{
	// TODO: Add your command handler code here
	CColorEnhansementDoc* pDoc= GetDocument();
	ASSERT_VALID(pDoc);
    pDoc->linear();
}



