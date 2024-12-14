#pragma once

#include <afxwin.h>  // Thêm thư viện MFC

class Mole {
public:
    bool isVisible;
    int x1, y1, x2, y2;
    COLORREF color;
    CImage moleImage; // Khai báo biến để lưu trữ hình ảnh

    Mole(); // Hàm khởi tạo mặc định
    Mole(int x1, int y1, int x2, int y2, COLORREF color); // Hàm khởi tạo với tham số
    void LoadImage(LPCTSTR fileName);
    void show();
    void hide();
    void draw(CDC* pdc);
    bool kttronghinh(CPoint point);
};
