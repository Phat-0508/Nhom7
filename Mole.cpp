#include "pch.h"
#include "Mole.h"

Mole::Mole() : isVisible(false), x1(0), y1(0), x2(50), y2(50), color(RGB(255, 0, 0)) {
    // Hàm khởi tạo mặc định, thiết lập các giá trị mặ1c định cho các biến
}
Mole::Mole(int x1, int y1, int x2, int y2, COLORREF color) : isVisible(false), x1(x1), y1(y1), x2(x2), y2(y2), color(color) { 
    // Hàm khởi tạo với tham số, thiết lập các giá trị cho các biến 
}

void Mole::LoadImage(LPCTSTR fileName) {
    moleImage.Load(fileName); // Tải hình ảnh từ tệp
}

void Mole::show() {
    isVisible = true;
}

void Mole::hide() {
    isVisible = false;
}

void Mole::draw(CDC* pdc) {

    if (isVisible) {
        if (moleImage) {
            moleImage.Draw(pdc->m_hDC, x1, y1);
        }
        else {
            // Dự phòng nếu hình ảnh không tải được
            CBrush brush(color); // Sử dụng màu sắc cho chuột
            pdc->SelectObject(&brush);
            pdc->Rectangle(x1, y1, x2, y2);
        }
    }
}
bool Mole::kttronghinh(CPoint point) { // Kiểm tra xem điểm có nằm trong hình chữ nhật đại diện cho chuột chũi hay không 
    return (point.x >= x1 && point.x <= x2 && point.y >= y1 && point.y);
}