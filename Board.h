// Board.h
#pragma once
#include "hcn.h"

class Board : public hcn {
public:
    Board(int mx1, int my1, int mx2, int my2) : hcn(mx1, my1, mx2, my2) {}
    void draw(CClientDC* pdc); // Loại bỏ từ khóa const
};
