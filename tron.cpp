#include "pch.h"
#include "tron.h"

void tron::thietlaptam()
{
	o.x = (x1 + x2) / 2;
	o.y = (y1 + y2) / 2;
	int r1 = (x2 - x1) / 2;
	int r2 = (y2 - y1) / 2;
	if (r1 < r2)
		r = r1;
	else
		r = r2;
}

void tron::vehinh(CClientDC* pdc)
{
	pdc->Ellipse(o.x - r, o.y - r, o.x + r, o.y + r);
}
