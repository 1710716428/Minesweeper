#include "stdafx.h"
#include "controller.h"
#include "tools.h"
#include "minefiled.h"

#include <conio.h>
#include <iostream>

using namespace std;

void CController::Select() //难度选择
{
	SetWindowSize(width, height + 3);
	system("cls");
	SetCursorPosition((width - 5) / 2, height / 2 - 2);
	SetColor(7);
	cout << "请选择难度";
	int keyboard, key = 1;
	while (true)
	{
		switch (key)
		{
		case 1:
			SetCursorPosition((width - 5) / 2 + 1, height / 2);
			SetColor(240);
			cout << "简  单";
			SetColor(7);
			SetCursorPosition((width - 5) / 2 + 1, height / 2 + 1);
			cout << "普  通";
			SetCursorPosition((width - 5) / 2 + 1, height / 2 + 2);
			cout << "困  难";
			break;
		case 2:
			SetCursorPosition((width - 5) / 2 + 1, height / 2);
			cout << "简  单";
			SetCursorPosition((width - 5) / 2 + 1, height / 2 + 1);
			SetColor(240);
			cout << "普  通";
			SetColor(7);
			SetCursorPosition((width - 5) / 2 + 1, height / 2 + 2);
			cout << "困  难";
			break;
		case 3:
			SetCursorPosition((width - 5) / 2 + 1, height / 2);
			cout << "简  单";
			SetCursorPosition((width - 5) / 2 + 1, height / 2 + 1);
			cout << "普  通";
			SetCursorPosition((width - 5) / 2 + 1, height / 2 + 2);
			SetColor(240);
			cout << "困  难";
			SetColor(7);
			break;
		default:
			break;
		}
		keyboard = _getch();
		if (keyboard == 224)
		{
			keyboard = _getch();
			switch (keyboard)
			{
			case 80:
				key = key<3 ? key + 1 : 3;
				break;
			case 72:
				key = key>1 ? key - 1 : 1;
				break;
			default:
				break;
			}
		}
		else if (keyboard = 13)
		{
			switch (key)
			{
			case 1:
				width = EASY_WIDTH;
				height = EASY_HEIGHT;
				number_mine = EASY_MINES;
				break;
			case 2:
				width = NORMAL_WIDTH;
				height = NORMAL_HEIGHT;
				number_mine = NORMAL_MINES;
				break;
			case 3:
				width = HARD_WIDTH;
				height = HARD_HEIGHT;
				number_mine = HARD_MINES;
				break;
			default:
				break;
			}
			break;
		}
	}
}
void CController::Game() //游戏
{
	while (1)
	{
		Select();
		SetWindowSize(width, height + 3);
		CMineFiled MineFiled(width, height, number_mine);
		MineFiled.Print();
		MineFiled.ShowRemain();
		while (1)
		{
			int x, y, status;
			MouseInfo(x, y, status);
			if (x >= 0 && x < MineFiled.GetWidth() && y >= 0 && y < MineFiled.GetHeight())
			{
				if (status == 1)
					MineFiled.MouseLeft(x, y);
				else if (status == 2)
					MineFiled.MouseRight(x, y);
				if (MineFiled.Succeed())
				{
					SetCursorPosition(0, height);
					cout << "恭喜通关成功！按任意键开始新游戏！";
					_getch();
					break;
				}
				if (MineFiled.Fail())
				{
					SetCursorPosition(0, height);
					cout << "通关失败！按任意键开始新游戏！";
					_getch();
					break;
				}
				MineFiled.ShowRemain();
			}
		}
	}
}

//void Menu();//菜单
