#pragma once

#include <iostream>
#include <easy2d/easy2d.h>

using namespace easy2d;
using namespace std;
class Player 
{
private:
	float TotalHP = 1000;	//总生命
	float maxHP = 1000;		//最大生命
	int TotalAnger = 0;		//总怒气
	int maxAnger = 1000;	//最大怒气
	int take1;				//道具1
	int take2;				//道具2
	int skill1;				//技能1
	int skill2;				//技能2
	int coins = 1000;		//金币
	string name;			//玩家姓名
public:
	Player()
	{
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
	//回复
	void receiveRecover(float val)
	{
		if (TotalHP + val < maxHP)
			TotalHP += val;
		else
			TotalHP = maxHP;
	}
	//怒气积累
	void receiveAnger(int val)
	{
		if (TotalAnger + val < maxAnger)
			TotalAnger += val;
		else
			TotalAnger = maxAnger;
	}
	//消耗怒气
	bool minusMp(int val)
	{
		if (TotalAnger - val >= 0)
		{
			TotalAnger -= val;
			return true;
		}
		else
			return false;
	}
	//获取Hp
	int getHp()
	{
		return TotalHP;
	}
	//获取Mp
	int getMp()
	{
		return TotalAnger;
	}
	//使用道具1
	void useTake1()
	{
		take1 = 0;
	}
	//获取道具1
	int getTake1()
	{
		return take1;
	}
	//使用道具2
	void useTake2()
	{
		take2 = 0;
	}
	//获取道具2
	int getTake2()
	{
		return take2;
	}
	//消费金币
	bool spendCoins(int val)
	{
		if (coins - val >= 0)
		{
			coins -= val;
			return true;
		}
		return false;
	}
	//添加金币
	void addCoins(int val)
	{
		coins += val;
	}
	//获取金币
	int getCoins()
	{
		return coins;
	}
	//设置道具1
	void setTake1(int id)
	{
		take1 = id;
	}
	//设置道具2
	void setTake2(int id)
	{
		take2 = id;
	}
	//设置玩家姓名
	void setName(string n)
	{
		name = n;
	}
	//获取玩家姓名
	string getName()
	{
		return name;
	}
	//设置技能1
	void setSkill1(int id)
	{
		skill1 = id;
	}
	//获取技能1
	int getSkill1()
	{
		return skill1;
	}
	//设置技能2
	void setSkill2(int id)
	{

		skill2 = id;
	}
	//获取技能2
	int getSkill2()
	{
		return skill2;
	}

};
