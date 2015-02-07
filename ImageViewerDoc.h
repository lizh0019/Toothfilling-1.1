// ImageViewerDoc.h : interface of the CImageViewerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGEVIEWERDOC_H__BA697904_1502_4DA4_B31A_38C23F100EBB__INCLUDED_)
#define AFX_IMAGEVIEWERDOC_H__BA697904_1502_4DA4_B31A_38C23F100EBB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CImageViewerDoc : public CDocument
{
protected: // create from serialization only
	CImageViewerDoc();
	DECLARE_DYNCREATE(CImageViewerDoc)

// Attributes
public:
	BOOL m_bScale;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageViewerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	float Proportion2;
	float Proportion1;
	virtual ~CImageViewerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CImageViewerDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEVIEWERDOC_H__BA697904_1502_4DA4_B31A_38C23F100EBB__INCLUDED_)
