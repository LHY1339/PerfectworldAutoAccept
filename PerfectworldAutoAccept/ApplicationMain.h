#pragma once
#include <Windows.h>
#include <string>
#include <thread>
#include <iostream>

#define WAIT_TIME 2000
#define THRESHOLD 100

HWND Wnd;
RECT WndRect;
HDC ScreenDC;
COLORREF PixColor;
int x_point, start_point, end_point;

std::string GetWindowTitle(HWND hwnd);
void PostMouseClick(HWND hwnd, int x, int y);
int main(int argc, char argv[]);