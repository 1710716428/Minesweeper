#include "stdafx.h"
#include "block.h"
#include "tools.h"
#include <iostream>

using namespace std;

void CBlock::SetMine(bool mine)
{
	this->mine = mine;
}

bool CBlock::GetMine()
{
	return mine;
}

bool CBlock::GetFlag()
{
	return print_flag;
}

void CBlock::PrintInit()
{
	SetCursorPosition(x, y);
	SetColor(15);
	cout << "■";
	SetColor(7);
}

void CBlock::Print_Right()
{
	if (print_flag)
	{
		PrintInit();
		print_flag = false;
	}
	else
	{
		SetCursorPosition(x, y);
		SetColor(12);
		cout << "★";
		SetColor(7);
		print_flag = true;
	}
}
void CBlock::PrintMine()
{
	if (mine)
	{
		SetCursorPosition(x, y);
		SetColor(12);
		cout << "●";
		SetColor(7);
	}
}

void CBlock::SetOpenFlag(bool temp) //设置打开标记
{
	open_flag = temp;
}
bool CBlock::GetOpenFlag() //返回打开标记
{
	return open_flag;
}