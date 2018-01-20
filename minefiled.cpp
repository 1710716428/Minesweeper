#include "stdafx.h"
#include "minefiled.h"
#include "tools.h"
#include <iostream>

using namespace std;

void CMineFiled::Print() //打印出雷区的初始状态
{
	for (auto&block : minefiled)
		block.PrintInit();
}

CBlock* CMineFiled::GetBlock(int x, int y) //返回坐标(x,y)方块的地址
{
	return &minefiled[x*height + y];
}

int CMineFiled::GetFlag() //返回被标记的方块的数量
{
	int count = 0;
	for (auto&block : minefiled)
		if (block.GetFlag())
			count++;
	return count;
}
void CMineFiled::PrintAllMine() //打印出全部的雷
{
	for (auto&block : minefiled)
		block.PrintMine();
}
int CMineFiled::GetRoundNumberMine(int x,int y) //打印出周围的雷的数量
{
	int count = 0,temp_x,temp_y;
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			temp_x = x + i;
			temp_y = y + j;
			if ((temp_x >= 0 && temp_x < width && temp_y >= 0 && temp_y < height) && !(temp_x == x && temp_y == y))
				if (GetBlock(temp_x, temp_y)->GetMine())
					count++;
		}
	}
	return count;
}

void CMineFiled::MouseRight(int x, int y) //对方块的右击
{
	if(!GetBlock(x, y)->GetOpenFlag())
		if(GetFlag()<number_mine)
			GetBlock(x, y)->Print_Right();
}

void CMineFiled::MouseLeft(int x, int y) //对方块的左击
{
	if (!GetBlock(x, y)->GetFlag() && !GetBlock(x, y)->GetOpenFlag())
	{
		GetBlock(x, y)->SetOpenFlag(true);
		if (GetBlock(x, y)->GetMine()) //如果是雷，打印出全部的雷，并返回0；
		{
			PrintAllMine();
			fail = true;
		}
		else
		{
			int number = GetRoundNumberMine(x, y);
			if (number == 0)
			{
				SetCursorPosition(x, y);
				SetColor(7);
				cout << "  ";
				int temp_x, temp_y;
				for (int i = -1; i < 2; i++)
				{
					for (int j = -1; j < 2; j++)
					{
						temp_x = x + i;
						temp_y = y + j;
						if ((temp_x >= 0 && temp_x < width && temp_y >= 0 && temp_y < height) && !(temp_x == x && temp_y == y))
							MouseLeft(temp_x, temp_y);
					}
				}
			}
			else //周围数量不是0，打印出雷的数量
			{
				SetCursorPosition(x, y);
				SetColor(7);
				cout << number;
			}
		}
	}
}

bool CMineFiled::Succeed() //是否所有的雷都被找出,即通关条件
{
	if (number_mine == GetFlag())
	{
		for (auto&block : minefiled)
			if (block.GetMine() != block.GetFlag())
				return false;
		return true;
	}
	else
	{
		return false;
	}
}

bool CMineFiled::Fail() //是否踩到雷 即失败
{
	return fail;
}

int CMineFiled::GetWidth() //得到雷区的宽
{
	return width;
}

int CMineFiled::GetHeight() //得到雷区的高
{
	return height;
}

void CMineFiled::ShowRemain() //显示剩余雷数
{
	SetCursorPosition(0, height);
	cout << "                        ";
	SetColor(7);
	SetCursorPosition(0, height);
	cout << "剩余雷的个数：" << (number_mine - GetFlag());
}