#pragma once
class hinh
{
public:
	int x1, y1, x2, y2;
	hinh()
	{
		x1 = 0;
		x2 = 0;
		y1 = 0;
		y2 = 0;
	}
	hinh(int mx1, int my1, int mx2, int my2)
	{
		x1 = mx1;
		y1 = my1;
		x2 = mx2;
		y2 = my2;
	}
	void virtual vehinh(CClientDC* pdc)
	{
		return;

	}
	void virtual dichtrai(int d)
	{
		x1 = x1 - d;
		x2 = x2 - d;
	}
	void virtual dichphai(int d)
	{
		x1 = x1 + d;
		x2 = x2 + d;
	}
	void virtual dichlen(int d)
	{
		y1 = y1 - d;
		y2 = y2 - d;
	}
	void virtual dichxuong(int d)
	{
		y1 = y1 + d;
		y2 = y2 + d;
	}

	int virtual kttronghinh(CPoint p)
	{
		if (p.x > x1 && p.x < x2 && p.y > y1 && p.y < y2)
			return 1;
		else
			return 0;
	}
};

