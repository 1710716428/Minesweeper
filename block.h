#pragma once

class CBlock
{
public:
	CBlock(int x,int y,bool mine):x(x),y(y),mine(mine),print_flag(false),open_flag(false){}
	CBlock(int x,int y):x(x),y(y),mine(false), print_flag(false), open_flag(false) {}
	void SetMine(bool mine);//�����Ƿ�Ϊ��
	bool GetMine();//�����Ƿ�����
	bool GetFlag();//�����Ƿ񱻱������
	void PrintInit();//��ӡ��ʼ״̬
	void Print_Right();//����һ���ʾ
	void PrintMine();//��ӡ����
	void SetOpenFlag(bool temp);//���ô򿪱��
	bool GetOpenFlag();//���ش򿪱��
private:
	int x, y;//����
	bool mine;//�Ƿ�����
	bool print_flag;//�Ƿ񱻱��Ϊ��
	bool open_flag;//�����Ƿ񱻴�
};