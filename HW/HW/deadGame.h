#pragma once
#pragma once
#include <easy2d/easy2d.h>//包含easy2d头文件
#include<iostream>
using namespace easy2d;//命名空间
using namespace std;

#include"BoardScene.h"

//游戏内死亡界面
class deadGame :public Scene
{
public:
	deadGame();
	deadGame(int goldCount, int timesThreeClear, int timesFourClear, int timesFiveClear, int timesSuperClear);
	void onUpdate() override;
private:
	void onClick();
	void SceneAdjust();
	void SceneAdjustTwo();
	int 	numOptionHeight;
	int 	numOptionWidth;

	Image* menuBackImg;
	Sprite* backImgGame;

	Text* textDeadGame;//游戏结束

	Text* TextGold;
	Text* TextThreeClear;
	Text* TextFourClear;
	Text* TextFiveClear;
	Text* TextSuperClear;

	Text* textRestartGame;//重新开始游戏
	Text* textBackMenu;//返回主菜单


};
//游戏获胜界面
class successScene :public Scene
{
public:
	//successScene();
	successScene(int goldCount, int timesThreeClear, int timesFourClear, int timesFiveClear, int timesSuperClear);
	void onUpdate() override;

private:
	void onClick();
	void SceneAdjust();
	int 	numOptionHeight;
	int 	numOptionWidth;
	Image* menuBackImg;
	Sprite* backImgGame;

	Text* textSuccessGame;//游戏获胜

	Text* TextGold;
	Text* TextThreeClear;
	Text* TextFourClear;
	Text* TextFiveClear;
	Text* TextSuperClear;

	Text* textNextGame;//开启下一关
	Text* textBackMenu;//返回主菜单
};

