// ScoreBoard.h
#pragma once
#include <afxwin.h>

class ScoreBoard {
public:
    int score;
    int lives;

    ScoreBoard(int score = 0, int lives = 5) : score(score), lives(lives) {}
    void draw(CClientDC* pdc) const;
};

