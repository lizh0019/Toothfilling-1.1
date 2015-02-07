// ColorEnhansementDoc.h : interface of the CColorEnhansementDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COLORENHANSEMENTDOC_H__3A912512_0A98_49BA_820A_0D9D6866326C__INCLUDED_)
#define AFX_COLORENHANSEMENTDOC_H__3A912512_0A98_49BA_820A_0D9D6866326C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "dialog1.h"

class CColorEnhansementDoc : public CDocument
{
protected: // create from serialization only
	CColorEnhansementDoc();
	DECLARE_DYNCREATE(CColorEnhansementDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorEnhansementDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	void linear();
	int m_iBmpWidth,nX1,nX2,nY1,nY2;
	unsigned char *pBmpMemory;
	bool m_bFileOpened;   ///图像是否打开 
	int m_iBmpHeight;    //height
	int m_iBmpLength;
	int m_iBmpBfts; ///
	int bymap[256];
	unsigned char *pPixMemory;  //图像像素首地址
	unsigned char *pProcessingMemory;  //处理后的像素内存首地质
	bool m_bPorcessed;      //	是否完成图像处理
	virtual ~CColorEnhansementDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CColorEnhansementDoc)
	afx_msg void OnEnhan();
	afx_msg void OnUpdateEnhan(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEn(CCmdUI* pCmdUI);
	afx_msg void OnDisplayhistogram();
	afx_msg void OnUpdateDisplayhistogram(CCmdUI* pCmdUI);
	afx_msg void OnTransform();
	afx_msg void OnUpdateTransform(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORENHANSEMENTDOC_H__3A912512_0A98_49BA_820A_0D9D6866326C__INCLUDED_)
