#pragma once
#pragma once
#include <easy2d/easy2d.h>//����easy2dͷ�ļ�
#include<iostream>
using namespace easy2d;//�����ռ�
using namespace std;

#include"BoardScene.h"

//��Ϸ����������
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

	Text* textDeadGame;//��Ϸ����

	Text* TextGold;
	Text* TextThreeClear;
	Text* TextFourClear;
	Text* TextFiveClear;
	Text* TextSuperClear;

	Text* textRestartGame;//���¿�ʼ��Ϸ
	Text* textBackMenu;//�������˵�


};
//��Ϸ��ʤ����
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

	Text* textSuccessGame;//��Ϸ��ʤ

	Text* TextGold;
	Text* TextThreeClear;
	Text* TextFourClear;
	Text* TextFiveClear;
	Text* TextSuperClear;

	Text* textNextGame;//������һ��
	Text* textBackMenu;//�������˵�
};

