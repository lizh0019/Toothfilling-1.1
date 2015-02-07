// ImageViewerView.h : interface of the CImageViewerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGEVIEWERVIEW_H__AA31376D_D533_4FD4_A2D1_BD879AF9C5B8__INCLUDED_)
#define AFX_IMAGEVIEWERVIEW_H__AA31376D_D533_4FD4_A2D1_BD879AF9C5B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define HIMETRIC_INCH 2540
#define SAVEWIDTH 500
#define SAVEHEIGHT 400
class CImageViewerView : public CView
{
protected: // create from serialization only
	CImageViewerView();
	DECLARE_DYNCREATE(CImageViewerView)

// Attributes
public:
	CImageViewerDoc* GetDocument();
	void LoadPicture(CString strFile);
// Operations
public:
	LPPICTURE *m_pPicture;
	BOOL m_bScale;
	CPoint m_pointStart,m_pointEnd;
	bool m_bInvalidRect;     ///
	bool m_bMouseDown;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageViewerView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	bool m_bMouseUp;
	bool SaveBmpFile(int width,int height,char *pdata);
	CPoint m_CurrentPoint;
	CDC* RenderToMemory(LPPICTURE m_pPicture,CDC* memdc,int ProperScalex,int ProperScaley);
	CPoint m_ToothPoint;
	CDC* RenderToMemory(LPPICTURE m_pPicture,CDC*);
	bool m_bToothOpen;
	LPPICTURE LoadToothName(LPPICTURE m_pPicture);
	CRect rc;
	CPoint ProperScale;
	CPoint m_OrigPoint;
	CPoint m_PointDouble;
	int nOrigHeight;
	int nOrigWidth;
	int nHeight;
	int nWidth;
	long hmHeight;
	long hmWidth;
	CDC **memdc;
	CDC* Zoom(int* nWidth,int* nHeight,int ProporScalex,int ProporScaley,CDC* memdc);
	CDC* CreateNewBitmap(int width,int height);
	float Proportion2;
	float Proportion1;
	virtual ~CImageViewerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
private:	
protected:
	char B;
	char G;
	char R;
	long pixel;
	//{{AFX_MSG(CImageViewerView)
	afx_msg void OnOperOpen();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnFileSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ImageViewerView.cpp
inline CImageViewerDoc* CImageViewerView::GetDocument()
   { return (CImageViewerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEVIEWERVIEW_H__AA31376D_D533_4FD4_A2D1_BD879AF9C5B8__INCLUDED_)
