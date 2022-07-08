#pragma once

#include <easy2d/easy2d.h>//包含easy2d头文件
#include<iostream>
using namespace easy2d;//命名空间
using namespace std;


//菜单参数类，设置图片名，文本名之类
class MenuPara
{
public:
	MenuPara();	
	Image* menuBeginImg;
	Image* menuBackImg;
	int	numMenuObject;
};


class MenuMain :public Scene
{
public:
	MenuMain();
	void onUpdate() override;
private:
	void onClick();
	void SceneAdjust();

	int	numOptionHeightNum;
	int 	numOptionWidthNum;

	Image* menuBackImg;
	Sprite* backImgGame;

	Text* textBeginGame;
	Text* textContinueGame;
	Text* textShopGame;
	Text* textOptionGame;
	Text* textQuitGame;
};





//商城界面
class Shop :public Scene
{
public:
	/*Shop();*/
	Shop(int goldNum=100);
	void onUpdate() override;

private:
	void onClick();
	void SceneAdjust();

	int numCommdity;//设定当前商品是什么
	
	Image* shopBackImg;
	Sprite* backImgGame;

	float scaleBackX;
	float scaleBackY;

	//当前拥有的金币总量
	int goldNum;
	Text* textGoldNum;

	//商品有关变量
	Sprite* commodity;
	Text* commodityText;
	int commodityOneCost;//商品花费金币
	int commodityTwoCost;
	wstring wstrCommodityOne;
	wstring wstrCommodityTwo;
	Image* commodityImgOne;
	Image* commodityImgTwo;


};



class menuOption :public Scene
{
public:
	menuOption();
	void onUpdate() override;
private:
	void onClick() ;
	void OptionAdjust();
	

	int	numOptionHeightNum;
	int	numOptionWidthNum;

	Image* menuBackImg;
	Sprite* backImgGame;
	
	Text* textResolutionChange;
	Text* textResolution;
	Text* textBackMenu;
	int resolutionState;

};

	/// <summary>设计出人物选择界面
	///主要设计要素：轮盘选择角色，高亮图片替换
	/// </summary>
class HeroChoose :public Scene
{
public:
	HeroChoose();
	void onUpdate() override;
private:
	void onClick();


	Image* menuBackImg;
	Sprite* backImgGame;


	Sprite* shopIcon;
	Sprite* optionIcon;

	Image* heroOneImg;
	Image* heroOneChooseImg;
	Image* heroTwoImg;
	Image* heroTwoChooseImg;
	
	Sprite* heroOne;
	Sprite* heroTwo;



	//记录是否点击依据点击几次
	int heroOneClick;
	int heroTwoClick;
	
};

