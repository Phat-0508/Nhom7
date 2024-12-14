// WhackAMoleView.h : interface of the CWhackAMoleView class
//

#pragma once
#include <afxwin.h>
#include "Game.h"

class CWhackAMoleView : public CView {
protected:
    CWhackAMoleView() noexcept;
    DECLARE_DYNCREATE(CWhackAMoleView)

public:
    Game game;

    virtual void OnDraw(CDC* pDC);
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    virtual void OnInitialUpdate();

protected:
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    DECLARE_MESSAGE_MAP()

public:
    virtual ~CWhackAMoleView();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
    CWhackAMoleDoc* GetDocument() const;
#endif
};

#ifndef _DEBUG  // debug version in WhackAMoleView.cpp
inline CWhackAMoleDoc* CWhackAMoleView::GetDocument() const
{
    return reinterpret_cast<CWhackAMoleDoc*>(m_pDocument);
}
#endif
