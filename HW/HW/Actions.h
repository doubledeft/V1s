#pragma once
#include <vector>
#include <easy2d/easy2d.h>
#include "Cheese.h"
#include "Monster.h"
#include "Player.h"
#include "CheeseAnimation.h"
#include <stdlib.h>
#include <time.h>

#define GAP 58.5       //棋格大小
#define LU_X 92        //棋盘左上角
#define LU_Y 180       //棋盘右上角
#define IMAGE_LARGE 50 //棋子大小
#define COLS 8         //列数
#define ROWS 7         //行数
#define ATTACK 0.2
#define RECOVER 0.4
#define ANGER 0.6

using namespace easy2d;
using namespace std;

class BoardActions {
private:
	Scene* sc;
	int SIZE;				//棋子大小
	int** board;			//数字棋盘
	int** comp;				//中间棋盘
	int totalAttack = 0;	//总攻击
	int totalRecover = 0;	//总回复
	int totalAnger = 0;		//总怒气
	int three;				//三消个数
	int four;				//四消个数
	int five;				//五消个数
	int diamond;			//超级消除个数
	vector<vector<myButton*>> cheeses;	//对象棋盘
	CheeseAnimation *ch;	//棋子动画
	bool isInit = true;		//是否在初始化
public:
	BoardActions(Scene* sc, vector<vector<myButton*>>& Cheeses, int** chessboard, double SIZE, int** comp);
	//~Actions();
	//扫描整个棋盘然后把消除的地方全部置0
	float  ScanAllAndDelete(int i, int j);
	//扫描整个棋盘，所有可以自由落体的地方都自由落体
	void FallAmongAll();
	//填充棋盘，给所有空余地方随机生成棋子
	void padding();
	//随机初始化棋盘
	void randomCreate();
	//不断进行删除，下落，删除...的重复操作，直到没有发生消除为止
	int delete_();
	//打印二维数组
	void print(int** matrix, int rows, int cols);
	//根据数字棋盘移除所有child， 刷新对象棋盘
	void refreshBoard();
	//获取当前对象棋盘
	vector<vector<myButton*>> getCheese();
	//获取当前数字棋盘
	int** copyBoard();
	//获取这一轮的总攻击,并置0
	int getTotalAttack();
	//获取这一轮的总回复量,并置0
	int getTotalRecover();
	//获取这一轮的总怒气值,并置0
	int getTotalAnger();
	//改变按钮的选中状态
	void setSelected(int i, int j);
	//取消按钮的选中状态
	void setUnSelected(int i, int j);
	//垂直交换
	void changeV(int s_i, int s_j, int e_i, int e_j);
	//水平交换
	void changeH(int s_i, int s_j, int e_i, int e_j);
	//删除棋子后的填充函数
	void afterDeletePadding();
	//释放所有棋子动作
	void releaseAllAction();
	//显示提示
	void showTip();
	//获取消除次数
	vector<int> getCounts();
	//重新加载棋盘
	void reload(int** a);

private:
	//往下掉落一格
	void FallByOne(int**& chessboard, vector<vector<Button*>>& Cheeses, int row, int col, double SIZE);
	//往上抬一格
	void UperByOne(int**& chessboard, vector<vector<Button*>>& Cheeses, int row, int col, double SIZE);
	//往左移动一格
	void LeftByOne(int**& chessboard, vector<vector<Button*>>& Cheeses, int row, int col, double SIZE);
	//往右移动一格
	void RightByOne(int**& chessboard, vector<vector<Button*>>& Cheeses, int row, int col, double SIZE);
	//自由落体，直到有棋子
	void GraviticallyFall(int row, int col);
	//交换棋子位置，无动画

};

class ActorActions {
private:
	Player *player;					//玩家对象
	monster *mon;					//怪物对象
public:
	ActorActions(Player *player, monster* mon);
	~ActorActions();
	//攻击玩家
	bool attackPlayer(int val);		
	//攻击怪物
	bool attackMonster(int val);
	//玩家回复
	void recoverPlayer(float val);	
	//玩家怒气值积累
	void angerPlayer(int val);	
	//怪物图像抖动
	void shakeMonster();			
};