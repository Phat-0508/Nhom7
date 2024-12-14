// Game.h
#pragma once
#include <afxwin.h>
#include "Mole.h"
#include "Board.h"
#include <vector>

class Game {
public:
    std::vector<Mole> moles;
    Board* board;
    int PlaySound = 0;
    int score;
    int lives;
    int highScore; // Thêm biến lưu điểm cao nhất
    void OnDraw(CDC* pDC); // Ghi đè hàm OnDraw
    Game();
    ~Game();
    void init();
    void PlayBackgroundMusic();
    void draw(CClientDC* pdc);
    void handleMouseClick(CPoint point);
    void update();
    bool isGameOver() const;
    void resetGame();
    void saveHighScore(); // Thêm phương thức lưu điểm cao nhất
};

