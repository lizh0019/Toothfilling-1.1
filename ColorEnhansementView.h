// ColorEnhansementView.h : interface of the CColorEnhansementView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COLORENHANSEMENTVIEW_H__7D350D7C_4A6B_46CB_BE5C_F7A52794016D__INCLUDED_)
#define AFX_COLORENHANSEMENTVIEW_H__7D350D7C_4A6B_46CB_BE5C_F7A52794016D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CColorEnhansementView : public CView
{
protected: // create from serialization only
	CColorEnhansementView();
	DECLARE_DYNCREATE(CColorEnhansementView)

// Attributes
public:
	CColorEnhansementDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorEnhansementView)
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
	virtual ~CColorEnhansementView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CColorEnhansementView)
	afx_msg void Onlinear();
	afx_msg void OnEn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ColorEnhansementView.cpp
inline CColorEnhansementDoc* CColorEnhansementView::GetDocument()
   { return (CColorEnhansementDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORENHANSEMENTVIEW_H__7D350D7C_4A6B_46CB_BE5C_F7A52794016D__INCLUDED_)
