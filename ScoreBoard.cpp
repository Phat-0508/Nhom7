// ScoreBoard.cpp
#include "pch.h"
#include "ScoreBoard.h"

void ScoreBoard::draw(CClientDC* pdc) const {
    CString strScore;
    strScore.Format(_T("Score: %d"), score);
    pdc->TextOutW(360, 60, strScore);

    CString strLives;
    strLives.Format(_T("Lives: %d"), lives);
    pdc->TextOutW(360, 80, strLives);
}
