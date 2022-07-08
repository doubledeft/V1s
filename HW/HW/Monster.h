#pragma once

#include <iostream>
#include <easy2d/easy2d.h>

using namespace easy2d;
using namespace std;

class monster : public Sprite
{
private:
	wstring img_path = L"./img/player1.png";	//图片地址
	float TotalHP = 1000;						//总Hp
	float maxHP = 1000;							//最大Hp
	float attackVal = 10;						//攻击力
	int posx = 800;								//
	int posy = 100;
public:
	monster()
	{
		this->open(img_path);
		this->setPos(posx, posy);
		this->setSize(400, 600);
	}
	//受到攻击
	bool receiveAttack(int val)
	{
		if (TotalHP > val)
		{
			TotalHP -= val;
			return true;
		}
		else
		{
			TotalHP = 0;
			return false;
		}
	}
	//获取Hp
	float getHP()
	{
		return TotalHP;
	}
};