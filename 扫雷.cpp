// 扫雷.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "controller.h"
#include "tools.h"

using namespace std;

int main()
{
	//隐藏光标
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态

	CController c;
	c.Game();
	while (true)
	{
		/*
		int x, y, status;
		MouseInfo(x, y, status);
		if (status != 0)
			cout << status << " " << x << " " << y << endl;
		*/
	}
    return 0;
}

