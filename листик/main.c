#include <stdio.h>
#include <math.h>

#define _WIN32_WINNT 0x0A00

#include <windows.h>

int main()
{
    HWND hwnd = GetDesktopWindow();
    HDC dc = GetDC(hwnd);
    double x = -1;
    int t = 1;

    do
    {

        if (x >= 18.8)
            t = -1;

        if (x <= -1)
            t = 1;

        SelectObject(dc, GetStockObject(DC_BRUSH));
        SetDCBrushColor(dc, RGB(255, 255, 0));
        Sleep(10);
        Ellipse(dc, 0 + x * 100, 540 + sin(x) * 100, 100 + x * 100, 640 + sin(x) * 100);

        if (t == 1)
        {
            x = x + 0.1;
        }

        else
        {
            x = x - 0.1;
        }
}
while (GetKeyState(VK_ESCAPE) >= 0);

return 0;
}
