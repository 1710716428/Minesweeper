#pragma once

#include "const.h"

class CController
{
public:
	CController():width(EASY_WIDTH),height(EASY_HEIGHT), number_mine(EASY_MINES){}
	void Select();//�Ѷ�ѡ��
	void Game();//��Ϸ
	void Menu();//�˵�

private:
	int width, height,number_mine;//��Ϸ����Ĵ�С
};