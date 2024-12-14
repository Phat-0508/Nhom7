// Game.cpp
#include "pch.h"
#include "Game.h"
#pragma comment(lib, "winmm.lib")
#include<mmsystem.h>
#include <windows.h>

Game::Game() : score(0), lives(5), highScore(0), board(nullptr) {}

Game::~Game() {
    delete board;
}

void Game::init() {
    PlayBackgroundMusic();
    board = new Board(50, 50, 350, 350); // Khởi tạo bảng chơi

    // Tạo các ô vuông cho chuột với màu sắc khác nhau
    COLORREF colors[9] = { RGB(255, 0, 0), RGB(0, 255, 0), RGB(0, 0, 255), RGB(255, 255, 0), RGB(255, 0, 255), RGB(0, 255, 255), RGB(128, 0, 128), RGB(255, 165, 0), RGB(0, 128, 128) };
    int colorIndex = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            moles.push_back(Mole(60 + j * 90, 60 + i * 90, 140 + j * 90, 140 + i * 90, colors[colorIndex++]));
        }
    }
}

void Game::PlayBackgroundMusic()
{
    mciSendString(L"open \"res\\nhacnen.wav\" type mpegvideo alias bgm", NULL, 0, NULL);// phát nhạc nền trong suốt trò chơi
    mciSendString(L"play bgm repeat", NULL, 0, NULL);
}


void Game::draw(CClientDC* pdc) {
    board->draw(pdc); // Vẽ bảng chơi

    for (auto& mole : moles) {
        mole.draw(pdc);
    }

    CString strScore;
    strScore.Format(_T("Score: %d"), score);
    pdc->TextOutW(360, 60, strScore);

    CString strLives;
    strLives.Format(_T("Lives: %d"), lives);
    pdc->TextOutW(360, 80, strLives);

    CString strHighScore;
    strHighScore.Format(_T("High Score: %d"), highScore);
    pdc->TextOutW(360, 100, strHighScore);

    if (isGameOver()) {
        CString strGameOver = _T("Game Over! Press SPACE to restart.");
        PlaySound(_T("res\\gameover.wav"), NULL, SND_FILENAME | SND_ASYNC);
        pdc->TextOutW(400, 250, strGameOver);
    }
}

void Game::handleMouseClick(CPoint point) {
    bool hit = false;
    for (auto& mole : moles) {
        if (mole.isVisible && mole.kttronghinh(point)) {
            mole.hide();
            score++;
            PlaySound(_T("res\\anmoi_1.wav"), NULL, SND_FILENAME | SND_ASYNC);
            hit = true;
            break;
        }
    }
    if (!hit) {
        lives--;
    }
}

void Game::update() {
    // Ngẫu nhiên hiển thị hoặc ẩn chuột
    for (auto& mole : moles) {
        if (rand() % 2 == 0) {
            mole.show();
        }
        else {
            mole.hide();
        }
    }
}

bool Game::isGameOver() const {
    return lives <= 0;
}

void Game::resetGame() {
    saveHighScore(); // Lưu điểm cao nhất khi trò chơi kết thúc
    score = 0;
    lives = 5;
    for (auto& mole : moles) {
        mole.hide();
    }
}

void Game::saveHighScore() {
    if (score > highScore) {
        highScore = score;
    }
}// CO CHAY DC DAU

void Game::OnDraw(CDC* pDC) {

    Mole myMole; // Tạo đối tượng Mole mà không truyền đối số
    myMole.LoadImage((_T("path_to_your_mole_image.bmp"))); // Đường dẫn tới hình ảnh chuột chũi
    myMole.show();
    myMole.draw(pDC); // Vẽ chuột chũi lên cửa sổ
}
`