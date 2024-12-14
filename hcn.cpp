#include "pch.h"
#include "hcn.h"

void hcn::vehinh(CClientDC* pdc)
{
    // ===== VẼ VIỀN =====
    // Tạo pen để vẽ viền đậm
    CPen penOutline(PS_SOLID, 3, RGB(0, 0, 0));  // Đen, độ dày 3
    pdc->SelectObject(&penOutline);

    // Vẽ lại viền cho hình chữ nhật với pen đậm
    pdc->Rectangle(x1, y1, x2, y2);  // Vẽ viền đậm cho hình chữ nhật
}
