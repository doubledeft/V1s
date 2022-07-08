#pragma once
#include <easy2d/easy2d.h>//包含easy2d头文件
#include<iostream>
using namespace easy2d;//命名空间
using namespace std;

#include"Menu.h"
//#include"BoardScene.h"
//游戏内暂停界面
class pauseGame :public Scene
{
public:
	pauseGame();
	void onUpdate() override;

private:
	void onClick();
	Image* menuBackImg;
	Sprite* backImgGame;


	//游戏暂停界面
	Text* textContinuGame;//继续
	Text* textOption;	//帮助和选项
	Text* textBackMenu;//返回主菜单

};


