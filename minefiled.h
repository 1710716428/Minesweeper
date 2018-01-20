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
		//��������
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				minefiled.emplace_back(CBlock(i, j));
			}
		}
		//������
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
	void Print();//��ӡ�������ĳ�ʼ״̬
	CBlock* GetBlock(int x, int y);//��������(x,y)����ĵ�ַ
	int GetFlag();//���ر���ǵķ��������
	void PrintAllMine();//��ӡ��ȫ������
	int GetRoundNumberMine(int x,int y);//��ӡ����Χ���׵�����
	void MouseRight(int x,int y);//�Է�����һ�
	void MouseLeft(int x, int y);//�Է�������
	bool Succeed();//�Ƿ����е��׶����ҳ�
	bool Fail();//�Ƿ�ȵ���
	int GetWidth();//�õ������Ŀ�
	int GetHeight();//�õ������ĸ�
	void ShowRemain();//��ʾʣ������

private:
	int width, height, number_mine,number_flag;//�����Ĵ�С,�׵������ͱ������
	vector <CBlock> minefiled;//��������
	bool fail;
};