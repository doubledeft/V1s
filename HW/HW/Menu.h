#pragma once

#include <easy2d/easy2d.h>//����easy2dͷ�ļ�
#include<iostream>
using namespace easy2d;//�����ռ�
using namespace std;


//�˵������࣬����ͼƬ�����ı���֮��
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





//�̳ǽ���
class Shop :public Scene
{
public:
	/*Shop();*/
	Shop(int goldNum=100);
	void onUpdate() override;

private:
	void onClick();
	void SceneAdjust();

	int numCommdity;//�趨��ǰ��Ʒ��ʲô
	
	Image* shopBackImg;
	Sprite* backImgGame;

	float scaleBackX;
	float scaleBackY;

	//��ǰӵ�еĽ������
	int goldNum;
	Text* textGoldNum;

	//��Ʒ�йر���
	Sprite* commodity;
	Text* commodityText;
	int commodityOneCost;//��Ʒ���ѽ��
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

	/// <summary>��Ƴ�����ѡ�����
	///��Ҫ���Ҫ�أ�����ѡ���ɫ������ͼƬ�滻
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



	//��¼�Ƿ������ݵ������
	int heroOneClick;
	int heroTwoClick;
	
};

