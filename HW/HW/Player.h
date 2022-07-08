#pragma once

#include <iostream>
#include <easy2d/easy2d.h>

using namespace easy2d;
using namespace std;
class Player 
{
private:
	float TotalHP = 1000;	//������
	float maxHP = 1000;		//�������
	int TotalAnger = 0;		//��ŭ��
	int maxAnger = 1000;	//���ŭ��
	int take1;				//����1
	int take2;				//����2
	int skill1;				//����1
	int skill2;				//����2
	int coins = 1000;		//���
	string name;			//�������
public:
	Player()
	{
	}
	//�ܵ�����
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
	//�ظ�
	void receiveRecover(float val)
	{
		if (TotalHP + val < maxHP)
			TotalHP += val;
		else
			TotalHP = maxHP;
	}
	//ŭ������
	void receiveAnger(int val)
	{
		if (TotalAnger + val < maxAnger)
			TotalAnger += val;
		else
			TotalAnger = maxAnger;
	}
	//����ŭ��
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
	//��ȡHp
	int getHp()
	{
		return TotalHP;
	}
	//��ȡMp
	int getMp()
	{
		return TotalAnger;
	}
	//ʹ�õ���1
	void useTake1()
	{
		take1 = 0;
	}
	//��ȡ����1
	int getTake1()
	{
		return take1;
	}
	//ʹ�õ���2
	void useTake2()
	{
		take2 = 0;
	}
	//��ȡ����2
	int getTake2()
	{
		return take2;
	}
	//���ѽ��
	bool spendCoins(int val)
	{
		if (coins - val >= 0)
		{
			coins -= val;
			return true;
		}
		return false;
	}
	//��ӽ��
	void addCoins(int val)
	{
		coins += val;
	}
	//��ȡ���
	int getCoins()
	{
		return coins;
	}
	//���õ���1
	void setTake1(int id)
	{
		take1 = id;
	}
	//���õ���2
	void setTake2(int id)
	{
		take2 = id;
	}
	//�����������
	void setName(string n)
	{
		name = n;
	}
	//��ȡ�������
	string getName()
	{
		return name;
	}
	//���ü���1
	void setSkill1(int id)
	{
		skill1 = id;
	}
	//��ȡ����1
	int getSkill1()
	{
		return skill1;
	}
	//���ü���2
	void setSkill2(int id)
	{

		skill2 = id;
	}
	//��ȡ����2
	int getSkill2()
	{
		return skill2;
	}

};
