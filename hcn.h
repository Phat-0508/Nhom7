#pragma once
#include "hinh.h"
class hcn :
    public hinh
{
public:
    hcn() :hinh()
    {}
    hcn(int mx1, int my1, int mx2, int my2) :hinh(mx1, my1, mx2, my2) {}
    void vehinh(CClientDC* pdc);
};

