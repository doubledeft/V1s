#pragma once
#include <vector>
#include <easy2d/easy2d.h>
#include "Cheese.h"
#include "Monster.h"
#include "Player.h"
#include "CheeseAnimation.h"
#include <stdlib.h>
#include <time.h>

#define GAP 58.5       //����С
#define LU_X 92        //�������Ͻ�
#define LU_Y 180       //�������Ͻ�
#define IMAGE_LARGE 50 //���Ӵ�С
#define COLS 8         //����
#define ROWS 7         //����
#define ATTACK 0.2
#define RECOVER 0.4
#define ANGER 0.6

using namespace easy2d;
using namespace std;

class BoardActions {
private:
	Scene* sc;
	int SIZE;				//���Ӵ�С
	int** board;			//��������
	int** comp;				//�м�����
	int totalAttack = 0;	//�ܹ���
	int totalRecover = 0;	//�ܻظ�
	int totalAnger = 0;		//��ŭ��
	int three;				//��������
	int four;				//��������
	int five;				//��������
	int diamond;			//������������
	vector<vector<myButton*>> cheeses;	//��������
	CheeseAnimation *ch;	//���Ӷ���
	bool isInit = true;		//�Ƿ��ڳ�ʼ��
public:
	BoardActions(Scene* sc, vector<vector<myButton*>>& Cheeses, int** chessboard, double SIZE, int** comp);
	//~Actions();
	//ɨ����������Ȼ��������ĵط�ȫ����0
	float  ScanAllAndDelete(int i, int j);
	//ɨ���������̣����п�����������ĵط�����������
	void FallAmongAll();
	//������̣������п���ط������������
	void padding();
	//�����ʼ������
	void randomCreate();
	//���Ͻ���ɾ�������䣬ɾ��...���ظ�������ֱ��û�з�������Ϊֹ
	int delete_();
	//��ӡ��ά����
	void print(int** matrix, int rows, int cols);
	//�������������Ƴ�����child�� ˢ�¶�������
	void refreshBoard();
	//��ȡ��ǰ��������
	vector<vector<myButton*>> getCheese();
	//��ȡ��ǰ��������
	int** copyBoard();
	//��ȡ��һ�ֵ��ܹ���,����0
	int getTotalAttack();
	//��ȡ��һ�ֵ��ܻظ���,����0
	int getTotalRecover();
	//��ȡ��һ�ֵ���ŭ��ֵ,����0
	int getTotalAnger();
	//�ı䰴ť��ѡ��״̬
	void setSelected(int i, int j);
	//ȡ����ť��ѡ��״̬
	void setUnSelected(int i, int j);
	//��ֱ����
	void changeV(int s_i, int s_j, int e_i, int e_j);
	//ˮƽ����
	void changeH(int s_i, int s_j, int e_i, int e_j);
	//ɾ�����Ӻ����亯��
	void afterDeletePadding();
	//�ͷ��������Ӷ���
	void releaseAllAction();
	//��ʾ��ʾ
	void showTip();
	//��ȡ��������
	vector<int> getCounts();
	//���¼�������
	void reload(int** a);

private:
	//���µ���һ��
	void FallByOne(int**& chessboard, vector<vector<Button*>>& Cheeses, int row, int col, double SIZE);
	//����̧һ��
	void UperByOne(int**& chessboard, vector<vector<Button*>>& Cheeses, int row, int col, double SIZE);
	//�����ƶ�һ��
	void LeftByOne(int**& chessboard, vector<vector<Button*>>& Cheeses, int row, int col, double SIZE);
	//�����ƶ�һ��
	void RightByOne(int**& chessboard, vector<vector<Button*>>& Cheeses, int row, int col, double SIZE);
	//�������壬ֱ��������
	void GraviticallyFall(int row, int col);
	//��������λ�ã��޶���

};

class ActorActions {
private:
	Player *player;					//��Ҷ���
	monster *mon;					//�������
public:
	ActorActions(Player *player, monster* mon);
	~ActorActions();
	//�������
	bool attackPlayer(int val);		
	//��������
	bool attackMonster(int val);
	//��һظ�
	void recoverPlayer(float val);	
	//���ŭ��ֵ����
	void angerPlayer(int val);	
	//����ͼ�񶶶�
	void shakeMonster();			
};