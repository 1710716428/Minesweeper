#pragma once

class CBlock
{
public:
	CBlock(int x,int y,bool mine):x(x),y(y),mine(mine),print_flag(false),open_flag(false){}
	CBlock(int x,int y):x(x),y(y),mine(false), print_flag(false), open_flag(false) {}
	void SetMine(bool mine);//设置是否为雷
	bool GetMine();//返回是否是雷
	bool GetFlag();//返回是否被标记是雷
	void PrintInit();//打印初始状态
	void Print_Right();//鼠标右击显示
	void PrintMine();//打印出雷
	void SetOpenFlag(bool temp);//设置打开标记
	bool GetOpenFlag();//返回打开标记
private:
	int x, y;//坐标
	bool mine;//是否是雷
	bool print_flag;//是否被标记为雷
	bool open_flag;//方块是否被打开
};