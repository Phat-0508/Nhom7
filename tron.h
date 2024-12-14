#pragma once
#include "hinh.h"
class tron :
    public hinh
{
public:
    int r;
    CPoint o;
    tron() :hinh() {
        r = 0;
        o.x = 0;
        o.y = 0;
    }
    tron(int mx1, int my1, int mx2, int my2) :hinh(mx1, my1, mx2, my2) {
        thietlaptam();
    }
    void thietlaptam();
    void vehinh(CClientDC* pdc);
};

