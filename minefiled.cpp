#include "stdafx.h"
#include "minefiled.h"
#include "tools.h"
#include <iostream>

using namespace std;

void CMineFiled::Print() //��ӡ�������ĳ�ʼ״̬
{
	for (auto&block : minefiled)
		block.PrintInit();
}

CBlock* CMineFiled::GetBlock(int x, int y) //��������(x,y)����ĵ�ַ
{
	return &minefiled[x*height + y];
}

int CMineFiled::GetFlag() //���ر���ǵķ��������
{
	int count = 0;
	for (auto&block : minefiled)
		if (block.GetFlag())
			count++;
	return count;
}
void CMineFiled::PrintAllMine() //��ӡ��ȫ������
{
	for (auto&block : minefiled)
		block.PrintMine();
}
int CMineFiled::GetRoundNumberMine(int x,int y) //��ӡ����Χ���׵�����
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

void CMineFiled::MouseRight(int x, int y) //�Է�����һ�
{
	if(!GetBlock(x, y)->GetOpenFlag())
		if(GetFlag()<number_mine)
			GetBlock(x, y)->Print_Right();
}

void CMineFiled::MouseLeft(int x, int y) //�Է�������
{
	if (!GetBlock(x, y)->GetFlag() && !GetBlock(x, y)->GetOpenFlag())
	{
		GetBlock(x, y)->SetOpenFlag(true);
		if (GetBlock(x, y)->GetMine()) //������ף���ӡ��ȫ�����ף�������0��
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
			else //��Χ��������0����ӡ���׵�����
			{
				SetCursorPosition(x, y);
				SetColor(7);
				cout << number;
			}
		}
	}
}

bool CMineFiled::Succeed() //�Ƿ����е��׶����ҳ�,��ͨ������
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

bool CMineFiled::Fail() //�Ƿ�ȵ��� ��ʧ��
{
	return fail;
}

int CMineFiled::GetWidth() //�õ������Ŀ�
{
	return width;
}

int CMineFiled::GetHeight() //�õ������ĸ�
{
	return height;
}

void CMineFiled::ShowRemain() //��ʾʣ������
{
	SetCursorPosition(0, height);
	cout << "                        ";
	SetColor(7);
	SetCursorPosition(0, height);
	cout << "ʣ���׵ĸ�����" << (number_mine - GetFlag());
}