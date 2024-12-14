// WhackAMoleView.cpp : implementation of the CWhackAMoleView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "WhackAMole.h"
#endif

#include "WhackAMoleDoc.h"
#include "WhackAMoleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CWhackAMoleView

IMPLEMENT_DYNCREATE(CWhackAMoleView, CView)

BEGIN_MESSAGE_MAP(CWhackAMoleView, CView)
    ON_WM_LBUTTONDOWN()
    ON_WM_KEYDOWN()
    ON_WM_TIMER()
END_MESSAGE_MAP()

// CWhackAMoleView construction/destruction

CWhackAMoleView::CWhackAMoleView() noexcept {
    game.init();
}

void CWhackAMoleView::OnInitialUpdate() {
    CView::OnInitialUpdate();
    SetTimer(1, 1000, NULL); // Đặt bộ đếm thời gian để cập nhật trò chơi
}

CWhackAMoleView::~CWhackAMoleView() {
}

BOOL CWhackAMoleView::PreCreateWindow(CREATESTRUCT& cs) {
    return CView::PreCreateWindow(cs);
}

// CWhackAMoleView drawing

void CWhackAMoleView::OnDraw(CDC* /*pDC*/) {
    CClientDC pdc(this);
    game.draw(&pdc);

    // Vẽ bảng điểm lớn hơn bên cạnh bảng chơi
    CRect scoreBoardRect(360, 50, 500, 200);
    CBrush whiteBrush(RGB(255, 255, 255)); // Màu trắng
    pdc.FillRect(scoreBoardRect, &whiteBrush);
    pdc.Rectangle(scoreBoardRect);

    // In tên game "Whack A Mole" vào trong bảng điểm
    CString strGameName = _T("Whack A Mole");
    pdc.TextOutW(370, 60, strGameName);

    CString strScore;
    strScore.Format(_T("Score: %d"), game.score);
    pdc.TextOutW(370, 80, strScore);

    CString strLives;
    strLives.Format(_T("Lives: %d"), game.lives);
    pdc.TextOutW(370, 100, strLives);

    CString strHighScore;
    strHighScore.Format(_T("High Score: %d"), game.highScore);
    pdc.TextOutW(370, 120, strHighScore);

    if (game.isGameOver()) {
        CString strGameOver = _T("Game Over! Press SPACE to restart.");
        pdc.TextOutW(300, 250, strGameOver); // Hiển thị thông báo "Game Over" dưới bảng điểm
    }
}

// CWhackAMoleView message handlers

void CWhackAMoleView::OnLButtonDown(UINT nFlags, CPoint point) {
    if (!game.isGameOver()) {
        game.handleMouseClick(point);
        Invalidate();
    }
    CView::OnLButtonDown(nFlags, point);
}

void CWhackAMoleView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
    if (nChar == VK_SPACE) {
        if (game.isGameOver()) {
            game.resetGame();
        }
        Invalidate();
    }
    CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CWhackAMoleView::OnTimer(UINT_PTR nIDEvent) {
    if (!game.isGameOver()) {
        game.update();
        Invalidate();
    }
    CView::OnTimer(nIDEvent);
}

// CWhackAMoleView diagnostics

#ifdef _DEBUG
void CWhackAMoleView::AssertValid() const {
    CView::AssertValid();
}

void CWhackAMoleView::Dump(CDumpContext& dc) const {
    CView::Dump(dc);
}

CWhackAMoleDoc* CWhackAMoleView::GetDocument() const // non-debug version is inline
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWhackAMoleDoc)));
    return (CWhackAMoleDoc*)m_pDocument;
}
#endif //_DEBUG
