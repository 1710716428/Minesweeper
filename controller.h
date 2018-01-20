#pragma once

#include "const.h"

class CController
{
public:
	CController():width(EASY_WIDTH),height(EASY_HEIGHT), number_mine(EASY_MINES){}
	void Select();//难度选择
	void Game();//游戏
	void Menu();//菜单

private:
	int width, height,number_mine;//游戏界面的大小
};