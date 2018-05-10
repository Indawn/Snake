// SNAKEView.h : interface of the CSNAKEView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SNAKEVIEW_H__BDCF5796_9A1A_4EC6_B84B_ED3A5E411A3A__INCLUDED_)
#define AFX_SNAKEVIEW_H__BDCF5796_9A1A_4EC6_B84B_ED3A5E411A3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSNAKEView : public CView
{
protected: // create from serialization only
	CSNAKEView();
	DECLARE_DYNCREATE(CSNAKEView)

// Attributes
public:
	CSNAKEDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSNAKEView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void Oninit();
	virtual ~CSNAKEView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSNAKEView)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnGameStart();
	afx_msg void OnGamePause();
	afx_msg void OnGameContinue();
	afx_msg void OnGameExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SNAKEView.cpp
inline CSNAKEDoc* CSNAKEView::GetDocument()
   { return (CSNAKEDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNAKEVIEW_H__BDCF5796_9A1A_4EC6_B84B_ED3A5E411A3A__INCLUDED_)
