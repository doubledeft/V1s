#pragma once
#include <easy2d/easy2d.h>//����easy2dͷ�ļ�
#include<iostream>
using namespace easy2d;//�����ռ�
using namespace std;

#include"Menu.h"
//#include"BoardScene.h"
//��Ϸ����ͣ����
class pauseGame :public Scene
{
public:
	pauseGame();
	void onUpdate() override;

private:
	void onClick();
	Image* menuBackImg;
	Sprite* backImgGame;


	//��Ϸ��ͣ����
	Text* textContinuGame;//����
	Text* textOption;	//������ѡ��
	Text* textBackMenu;//�������˵�

};


