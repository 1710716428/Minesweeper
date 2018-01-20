#pragma once

#include "block.h"

#include <vector>
#include <ctime>

using namespace std;

class CMineFiled
{
public:
	CMineFiled(int width,int height,int number_mine):width(width),height(height), number_mine(number_mine),number_flag(0),fail(false)
	{
		//产生雷区
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				minefiled.emplace_back(CBlock(i, j));
			}
		}
		//分配雷
		int count = 0;
		time_t t;
		srand((unsigned)time(&t));
		while (count<number_mine)
		{
			int x = rand() % width;
			int y = rand() % height;
			if (!GetBlock(x, y)->GetMine())
			{
				GetBlock(x, y)->SetMine(true);
				count++;
			}
		}
	}
	void Print();//打印出雷区的初始状态
	CBlock* GetBlock(int x, int y);//返回坐标(x,y)方块的地址
	int GetFlag();//返回被标记的方块的数量
	void PrintAllMine();//打印出全部的雷
	int GetRoundNumberMine(int x,int y);//打印出周围的雷的数量
	void MouseRight(int x,int y);//对方块的右击
	void MouseLeft(int x, int y);//对方块的左击
	bool Succeed();//是否所有的雷都被找出
	bool Fail();//是否踩到雷
	int GetWidth();//得到雷区的宽
	int GetHeight();//得到雷区的高
	void ShowRemain();//显示剩余雷数

private:
	int width, height, number_mine,number_flag;//雷区的大小,雷的数量和标记数量
	vector <CBlock> minefiled;//定义雷区
	bool fail;
};