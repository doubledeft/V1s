#pragma once
#include <easy2d/easy2d.h>
using namespace easy2d;
#include<iostream>
using namespace std;
//属性类
//包含多个属性显示类

class EnemyHealthPoint :public Sprite
{

public:

	EnemyHealthPoint(float inithp=1000);
	void onUpdate();
	//数值函数
	void setHp(float hp);

private:
	////数值参数
	float inithp;//初始血量
	float hp;//当前血量，主要改动属性
	float php;//血量百分比，percent hp
	//	//图形参数
	////血槽锚点在左上角
	//int widthHp;//血槽长度,以100血量占屏幕1/6长度为基准，根据血量大小设定学槽长度
	//int heightHp;//血槽高度，默认为20，一个能看清的高度
	//int posx;//血槽所处位置
	//int posy;
	float imgWidth;
	float scalex;
	float picWidth;
};
class pointEdge :public Sprite
{
public:
	pointEdge(float posx,float posy,float scalex);
private:
	float imgWidth;
	float imgHeight;
	float scalex;
	float picWidth;
};



class HeroHealthPoint :public Sprite
{
public:
	HeroHealthPoint(float inithp = 1000);
	void onUpdate();
	//数值函数
	void setHp(float hp);
private:
	float inithp;//初始血量
	float hp;//当前血量，主要改动属性
	float php;//血量百分比，percent hp
	float imgWidth;
	float imgHeight;
	float scalex;
	float picWidth;
};

class HeroMagicPoint :public Sprite
{
public:
	//蓝条也默认为1000了
	HeroMagicPoint(float intimp=100);
	void onUpdate();
	//数值函数
	void setMp(float mp);

private:
	float initmp;//初始血量
	float mp;//当前血量，主要改动属性
	float pmp;//血量百分比，percent hp
	float imgWidth;
	float imgHeight;
	float scalex;
	float picWidth;
};
