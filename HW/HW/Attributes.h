#pragma once
#include <easy2d/easy2d.h>
using namespace easy2d;
#include<iostream>
using namespace std;
//������
//�������������ʾ��

class EnemyHealthPoint :public Sprite
{

public:

	EnemyHealthPoint(float inithp=1000);
	void onUpdate();
	//��ֵ����
	void setHp(float hp);

private:
	////��ֵ����
	float inithp;//��ʼѪ��
	float hp;//��ǰѪ������Ҫ�Ķ�����
	float php;//Ѫ���ٷֱȣ�percent hp
	//	//ͼ�β���
	////Ѫ��ê�������Ͻ�
	//int widthHp;//Ѫ�۳���,��100Ѫ��ռ��Ļ1/6����Ϊ��׼������Ѫ����С�趨ѧ�۳���
	//int heightHp;//Ѫ�۸߶ȣ�Ĭ��Ϊ20��һ���ܿ���ĸ߶�
	//int posx;//Ѫ������λ��
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
	//��ֵ����
	void setHp(float hp);
private:
	float inithp;//��ʼѪ��
	float hp;//��ǰѪ������Ҫ�Ķ�����
	float php;//Ѫ���ٷֱȣ�percent hp
	float imgWidth;
	float imgHeight;
	float scalex;
	float picWidth;
};

class HeroMagicPoint :public Sprite
{
public:
	//����ҲĬ��Ϊ1000��
	HeroMagicPoint(float intimp=100);
	void onUpdate();
	//��ֵ����
	void setMp(float mp);

private:
	float initmp;//��ʼѪ��
	float mp;//��ǰѪ������Ҫ�Ķ�����
	float pmp;//Ѫ���ٷֱȣ�percent hp
	float imgWidth;
	float imgHeight;
	float scalex;
	float picWidth;
};
