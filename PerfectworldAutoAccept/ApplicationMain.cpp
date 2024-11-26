#include "ApplicationMain.h"

struct V3D
{
	int R, G, B;
};

std::string GetWindowTitle(HWND hwnd)
{
	char title[256];
	GetWindowTextA(hwnd, title, sizeof(title));
	return std::string(title);
}

void PostMouseClick(HWND hwnd, int x, int y)
{
	LPARAM lParam = MAKELPARAM(x, y);
	PostMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, lParam);
	PostMessage(hwnd, WM_LBUTTONUP, 0, lParam);
}

void CheckColorCut(int start, int end)
{
	V3D Color;
	for (int k = start; k < end; k += 2)
	{
		PixColor = GetPixel(ScreenDC, x_point, k);
		Color.R = GetRValue(PixColor);
		Color.G = GetGValue(PixColor);
		Color.B = GetBValue(PixColor);
		if (Color.B-Color.R > THRESHOLD|| Color.B - Color.G > THRESHOLD)
		{
			std::cout << "y_point:" << k << " | bValue:" << Color.B << std::endl;
			PostMouseClick(Wnd, (WndRect.right - WndRect.left) / 2, k - WndRect.top);
		}
	}
}

int main(int argc, char argv[])
{
	while (1)
	{
		Wnd = GetForegroundWindow();
		if (IsWindowVisible(Wnd) && GetWindowTitle(Wnd) == "完美世界竞技平台")
		{
			GetWindowRect(Wnd, &WndRect);
			x_point = WndRect.left + (WndRect.right - WndRect.left) / 2;
			start_point = WndRect.top + (WndRect.bottom - WndRect.top) / 2;
			end_point = WndRect.bottom - (WndRect.bottom - WndRect.top) / 4;
			ScreenDC = GetDC(NULL);
			std::thread th_CheckColorCut(CheckColorCut, start_point, end_point);
			th_CheckColorCut.detach();
		}
		Sleep(WAIT_TIME);
	}
	return 0;
}
