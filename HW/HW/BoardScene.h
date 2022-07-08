#ifndef UI_H
#define UI_H

#define GAP 58.5       //棋格大小
#define LU_X 92        //棋盘左上角
#define LU_Y 180       //棋盘右上角
#define IMAGE_LARGE 50 //棋子大小
#define COLS 8         //列数
#define ROWS 7         //行数

#include "Cheese.h"
#include "Actions.h"
#include "Monster.h"
#include "Player.h"
#include <Windows.h>
#include <iostream>
#include <vector>
#include <easy2d/easy2d.h>
#include "Attributes.h"
#include <chrono>
#include <thread>
#include"PauseScene.h"
#include "deadGame.h"
#include <fstream> 

using namespace easy2d;
using namespace std;

class BoardScene: public Scene
{
public:
    BoardScene(bool isNew);
    ~BoardScene();

private:
	BoardScene* ui;
	Sprite* swords = gcnew Sprite;              //攻击棋子
	Sprite* drugs = gcnew Sprite;               //回复棋子
	Sprite* angers = gcnew Sprite;              //怒气棋子
	int** chessboard = new int* [7];            //棋盘中方块种类的分布，用于消除判断
	int** comp = new int* [7];                  //中间量，记录哪些方块需要被消除并置为0，等棋子全部判断完后赋给chessboard
	int** tempboard = new int* [7];				//保存交换前的棋盘，如果不符合消去的条件就回滚
	vector<vector<myButton*>> Cheeses;          //棋盘每个位置对应的棋子(QLabel)
	BoardActions* action;						//棋子动作
	ActorActions* aaction;						//角色动作
	monster* mon;								//怪物对象
	Player* player;								//玩家对象
	EnemyHealthPoint* enemyhp;					//怪物血条
	HeroHealthPoint* herohp;					//玩家血条
	HeroMagicPoint* heromp;						//玩家血条
	bool _mouseDoubleClick = false;				// 鼠标左右键同时点击
	char _userInput = 0;						// 储存用户输入
	bool _gameover = false;						//游戏是否结束
	bool first_choose = false;					//是否第一次点击棋子
	int s_i;									//需要交换棋子位置横坐标
	int s_j;									//需要交换棋子位置纵坐标
	int e_i;									//被交换棋子的横坐标
	int e_j;									//被交换妻子的纵坐标
	int turn = 0;								//回合数
	Button* tip;								//提示的按钮
	Button* tipp;								//提示文本
	Button* ddd;								//下落按钮
	Sprite* playerimg;							//玩家图片
	Sprite* s1;									//道具1
	Sprite* s2;									//道具2
	Sprite* sk1;								//道具1
	Sprite* sk2;								//道具2
	bool clickTip = false;						//是否点击提示
	int tipCount = 0;							//提示次数
	Text* leftCount;							//剩余下落次数
	Text* leftCount_pre;						//提示字
	int lcount = 50;							//剩下的次数
	bool turn_recover = false;					//是否使用回合回血道具
	int turn_recover_letf_count = 3;			//吸血剩余次数
	int skill1;									//技能1种类
	int skill2;									//技能2种类
	bool isSuck = false;						//吸血技能
	bool isAngry = false;						//暴怒技能
	int suckcount = 3;							//吸血剩余次数
	int angrycount = 2;							//暴怒剩余次数
private:
    void init();    
	//新游戏
	void newGame();
	//处理用户点击
	void onClick(int button);
	//获取用户按键
	void onUpdate() override;
	//获取鼠标位置的方块下标，若鼠标不在方块上则返回 -1
	Point getPointInBlock(const Point& point);
	//显示提示
	void showTip();
	//添加道具
	void addTakes();
	//添加技能
	void addSkills();
	//保存游戏
	void saveGame();
	//载入游戏
	//载入游戏
	void reloadGame();
};
#endif // MAINWINDOW_H
