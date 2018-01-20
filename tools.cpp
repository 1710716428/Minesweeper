#include "stdafx.h"
#include "tools.h"
#include <Windows.h>
#include <stdio.h>

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#define KEY_UP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

void MouseInfo(int &x, int &y, int &status)
{
	status = 0; x = -1; y = -1;
	HWND MyGame_Hwnd = FindWindow("ConsoleWindowClass", NULL);
	HWND Fouce_Hwnd = GetForegroundWindow();
	if (MyGame_Hwnd == Fouce_Hwnd)
	{
		if (KEY_DOWN(VK_LBUTTON))
			while (!KEY_UP(VK_LBUTTON))
				status = 1;
		else if (KEY_DOWN(VK_RBUTTON))
			while (!KEY_UP(VK_RBUTTON))
				status = 2;
		if (status != 0)
		{
			POINT p;
			CONSOLE_FONT_INFO p1;
			GetCursorPos(&p);
			ScreenToClient(FindWindow("ConsoleWindowClass", NULL), &p);
			GetCurrentConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), false, &p1);
			x = p.x / (p1.dwFontSize.X * 2);
			y = p.y / p1.dwFontSize.Y;
			if (p.x < 0 || p.y < 0)
				status = 0;
		}
	}
}

void SetCursorPosition(const int x, const int y) {
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void SetColor(int colorID) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetWindowSize(int cols, int lines) {
	system("title É¨À×");
	char cmd[30];
	sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);
	system(cmd);
}