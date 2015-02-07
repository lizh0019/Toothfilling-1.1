// ImageViewerDoc.cpp : implementation of the CImageViewerDoc class
//

#include "stdafx.h"
#include "ImageViewer.h"
#include "PropInput.h"
#include "ImageViewerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImageViewerDoc

IMPLEMENT_DYNCREATE(CImageViewerDoc, CDocument)

BEGIN_MESSAGE_MAP(CImageViewerDoc, CDocument)
	//{{AFX_MSG_MAP(CImageViewerDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageViewerDoc construction/destruction

CImageViewerDoc::CImageViewerDoc()
{
	// TODO: add one-time construction code here
	m_bScale=FALSE;
}

CImageViewerDoc::~CImageViewerDoc()
{
}

BOOL CImageViewerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	Proportion1=1.0;
	Proportion2=1.0;
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CImageViewerDoc serialization

void CImageViewerDoc::Serialize(CArchive& ar)
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
// CImageViewerDoc diagnostics

#ifdef _DEBUG
void CImageViewerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImageViewerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CImageViewerDoc commands
