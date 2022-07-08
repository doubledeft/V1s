#ifndef CHEESE_H
#define CHEESE_H

#define SIze 58.5

#include <iostream>
#include <easy2d/easy2d.h>

using namespace easy2d;
using namespace std;


class Sword : public Sprite
{
public:
	Sword()
	{
		// 加载图片
		this->open(L"./img/sword.png");
	}
public:
	wstring img = L"./img/sword.png"; //图片地址
	wstring img2 = L"./img/sword_ch.jpg"; //图片地址
	
private:
	int hurt = 12;              //基础伤害
	int x = 0;                  //图片的x坐标
	int y = 0;                  //图片的y坐标
	int col = 0;                //第几列
	int row = 0;                //第几行
	double lv1 = 1.25;          //二消
	double lv2 = 1.5;           //三消
	double lv3 = 2.0;           //四消
	bool isSelected = false;
};

class Drug : public Sprite
{
public:
	Drug()
	{
		// 加载图片
		this->open(L"./img/drug.png");
	}
	wstring img = L"./img/drug.png";  //图片地址
	wstring img2 = L"./img/drug_ch.jpg";  //图片地址
private:
	int cure = 2;               //基础治疗量
	int x = 0;                  //图片的x坐标
	int y = 0;                  //图片的y坐标
	int col = 0;                //第几列
	int row = 0;                //第几行
	double lv1 = 1.5;           //二消
	double lv2 = 2.0;           //三消
	double lv3 = 2.5;           //四消

};

class Anger : public Sprite
{
public:
	Anger()
	{
		// 加载图片
		this->open(L"./img/anger.png");
	}
	wstring img = L"./img/anger.png"; //图片地址
	wstring img2 = L"./img/anger_ch.jpg"; //图片地址
private:
	int ang = 10;               //基础怒气值
	int x = 0;                  //图片的x坐标
	int y = 0;                  //图片的y坐标
	int col = 0;                //第几列
	int row = 0;                //第几行
	double lv1 = 1.2;           //二消
	double lv2 = 1.4;           //三消
	double lv3 = 1.6;           //四消

};

class null : public Sprite
{
public:
	null()
	{
		// 加载图片
		this->open(L"./img/2.png");
	}
	wstring img = L"./img/2.png"; //图片地址
	wstring img2 = L"./img/2.png"; //图片地址
};

class myButton : public Button
{
private:
	bool selected = false;
	bool boom = false;
	Sprite* sp;
	null* n;
	Sword* sword;
	Drug* drug;
	Anger* anger;

public:
	bool isS = false;
	bool isD = false;
	bool isA = false;
	bool isN = false;
	wstring img1;
	wstring img2;
	Sequence* s = new Sequence();
public:
	myButton(Sprite* s)
	{
		sp = s;
		n = new null();
		sword = new Sword();
		drug = new Drug();
		anger = new Anger();
		img1 = n->img;
		img2 = n->img2;
		sp->setVisible(true);
		sp->setSize(55, 55);
		this->addChild(sp);
	}

	void setUnSelected2()
	{
		selected = false;
		this->onUpdate();
	}

	void setSelected2()
	{
		selected = true;
		this->onUpdate();

	}

	void changeToSword()
	{
		isS = true;
		isD = false;
		isA = false;
		isN = false;
		img1 = sword->img;
		img2 = sword->img2;
		if (!selected)
		{
			sp->open(img1);
		}
		else
		{
			sp->open(img2);
		}
		this->onUpdate();
	}

	void changeToAnger()
	{
		isS = false;
		isD = false;
		isA = true;
		isN = false;
		img1 = anger->img;
		img2 = anger->img2;
		if (!selected)
		{
			sp->open(img1);
		}
		else
		{
			sp->open(img2);
		}
		this->onUpdate();
	}

	void changeToDrug()
	{
		isS = false;
		isD = true;
		isA = false;
		isN = false;
		img1 = drug->img;
		img2 = drug->img2;

		if (!selected)
		{
			sp->open(img1);
		}
		else
		{
			sp->open(img2);
		}
		this->onUpdate();
	}

	void changeToNull()
	{
		isS = false;
		isD = false;
		isA = false;
		isN = true;
		img1 = n->img;
		img2 = n->img2;
		this->onUpdate();
	}

	void fadeIn()
	{
		auto fadein = gcnew FadeIn(2);
		this->runAction(fadein);
	}

	void run()
	{
		this->runAction(s);
	}

	void resetAction()
	{
		s->reset();
	}

	int getID()
	{
		if (isN)
			return 0;
		else if (isS)
			return 1;
		else if (isD)
			return 2;
		else if (isA)
			return 3;

	}

	void setPic(int id)
	{
		if (id == 0)
			changeToNull();
		else if (id == 1)
			changeToSword();
		else if (id == 2)
			changeToDrug();
		else if (id == 3)
			changeToAnger();
	}

private:
	void onUpdate() override
	{
		if (!selected)
		{
			sp->open(img1);
		}
		else
		{
			sp->open(img2);
		}
	}
};


#endif // CHEESE_H
