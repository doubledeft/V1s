#include "BoardScene.h"

#define MOUSE_RIGHT (0x1 >> 0)
#define MOUSE_LEFT (0x1 >> 1)

//构造函数，完成初始化
BoardScene::BoardScene(bool isNew)
{

	init();
	this->setAutoUpdate(true);
	if (isNew)
		newGame();
	else
		reloadGame();
}

//析构函数
BoardScene::~BoardScene()
{
	delete ui;
}

//初始化数字棋盘，中间棋盘和对象棋盘
//ret: void
void BoardScene::init()
{

	//数字棋盘分配空间
	for (int i = 0; i < ROWS; i++)
		chessboard[i] = new int[COLS];
	//中间棋盘分配空间
	for (int i = 0; i < ROWS; i++)
		comp[i] = new int[COLS];
	//历史棋盘分配空间
	for (int i = 0; i < ROWS; i++)
		tempboard[i] = new int[COLS];

	// 把精灵变成一个按钮，并设置点击按钮后的回调函数
	for (int i = 0; i < ROWS; i++) {
		vector<myButton*> v;
		Cheeses.push_back(v);
		for (int j = 0; j < COLS; j++) {
			chessboard[i][j] = 0;
			auto q1 = gcnew null;
			auto button = gcnew myButton(q1);
			button->setPos(LU_X + GAP * j, LU_Y + GAP * i);
			q1->setSize(IMAGE_LARGE, IMAGE_LARGE);
			Cheeses.at(i).push_back(button);
			button->setName(to_wstring(i) + to_wstring(j));
			this->addChild(button);
		}
	}

	//变量初始化
	player = new Player();
	mon = new monster();
	action = new BoardActions(this, Cheeses, chessboard, GAP, comp);
	aaction = new ActorActions(player, mon);

	//人物
	player->setTake1(1);
	player->setTake2(2);
	player->setSkill1(1);
	player->setSkill2(2);
	player->setName("default");

	//提示图
	Image* tipImg = new Image(L"./img/tip.png");
	auto stip = gcnew Sprite(tipImg);
	tip = new Button(stip);
	tip->setPos(200, 50);

	//落下
	Image* d = new Image(L"./img/re.png");
	auto down = gcnew Sprite(d);
	ddd = new Button(down);
	ddd->setPos(400, 50);

	//用户头像
	playerimg = new Sprite(L"./img/player1.png");
	playerimg->setSize(160, 160);
	playerimg->setPos(450, 630);

	//背景图片
	Image* menuBackImg = new Image(L"./img/menuBackImage.png");
	auto backImgGame = gcnew Sprite(menuBackImg);
	float scaleBackX = Window::getWidth() / menuBackImg->getWidth();
	float scaleBackY = Window::getHeight() / menuBackImg->getHeight();
	backImgGame->setScale(scaleBackX, scaleBackY);
	backImgGame->setAnchor(0.5, 0.5);
	backImgGame->setPos(Window::getWidth() / 2, Window::getHeight() / 2);

	//倒计数
	leftCount = gcnew Text(L"50");
	leftCount->setSize(60, 60);
	leftCount->setPos(50, 50);

	leftCount_pre = gcnew Text(L"Remain: ");
	leftCount_pre->setSize(60, 60);
	leftCount_pre->setPos(20, 20);

	//血条
	//实现血条，初始血量为100，调用setup函数，设定为0-100的值，血条长短会变化
	enemyhp = gcnew EnemyHealthPoint();
	auto enemyHpEdge = gcnew pointEdge(enemyhp->getPosX(), enemyhp->getPosY(), enemyhp->getScaleX());
	herohp = gcnew HeroHealthPoint();
	auto heroHpEdge = gcnew  pointEdge(herohp->getPosX(), herohp->getPosY(), herohp->getScaleX());
	heromp = gcnew HeroMagicPoint();
	auto heroMpEdge = gcnew pointEdge(heromp->getPosX(), heromp->getPosY(), herohp->getScaleX());

	//棋盘背景
	Image* img_bk = new Image(L"./img/bk.png");
	Sprite* bk = new Sprite();
	bk->open(img_bk);
	bk->setPos(45, 138);

	//添加进场景
	this->addChild(backImgGame);
	//this->addChild(grayhp);
	this->addChild(enemyHpEdge);
	this->addChild(enemyhp);
	this->addChild(heroHpEdge);
	this->addChild(herohp);
	this->addChild(heroMpEdge);
	this->addChild(heromp);
	this->addChild(bk);
	this->addChild(mon);
	this->addChild(playerimg);
	this->addChild(tip);
	this->addChild(ddd);
	this->addChild(leftCount);
	this->addChild(leftCount_pre);
}

//根据鼠标点击坐标判断点的是哪个方块
//@param const Point& point: 点击的点
//ret: Point 点击棋子所在的行和列组成的点
Point BoardScene::getPointInBlock(const Point& point)
{
	//需要重新获取对象棋盘,因为已经刷新
	vector<vector<myButton*>> ches;
	ches = action->getCheese();
	for (int i = 0; i < ches.size(); i++)
	{
		for (int j = 0; j < ches.at(i).size(); j++)
		{
			if (abs(point.x - ches[i][j]->getPosX()) < GAP && abs(point.y - ches[i][j]->getPosY()) < GAP)
			{
				Point p = Point(i, j);
				return p;
			}
		}
	}
	//点击提示
	if (abs(point.x - tip->getPosX()) < 60 && abs(point.y - tip->getPosY()) < 60 )
	{
		if (tipCount < 3)
		{
			showTip();
			tipCount++;
			if (tipCount == 3)
			{
				Image* tipImg2 = new Image(L"./img/tip_pro.png");
				auto stip = gcnew Sprite(tipImg2);
				tipp = new Button(stip);
				tipp->setPos(200, 50);
				this->addChild(tipp);
			}
		}
		
		
	}

	//点击下落
	if (abs(point.x - ddd->getPosX()) < 60 && abs(point.y - ddd->getPosY()) < 60)
	{
		action->afterDeletePadding();
		action->afterDeletePadding();
		action->afterDeletePadding();
		action->afterDeletePadding();
		action->afterDeletePadding();
		action->afterDeletePadding();
		action->afterDeletePadding();
		while (action->delete_() > 0)
		{
			action->afterDeletePadding();
			action->afterDeletePadding();
			action->afterDeletePadding();
			action->afterDeletePadding();
			action->afterDeletePadding();
			action->afterDeletePadding();
			action->afterDeletePadding();
		}
		
		lcount--;
		leftCount->setText(to_wstring(lcount));
		if (lcount == 0)
		{
			_gameover = true;
			SceneManager::back();
		}
	}

	//使用道具1
	if (s1->containsPoint(point) && player->getTake1()>0)
	{
		lcount += 15;
		s1->open(L"./img/t1_gray.png");
		s1->setSize(80, 80);
		s1->setPos(220, 615);
		leftCount->setText(to_wstring(lcount));
		player->useTake1();
	}
	//使用道具2
	if (s2->containsPoint(point) && player->getTake2() > 0)
	{
		s2->open(L"./img/t2_gray.png");
		s2->setSize(80, 80);
		s2->setPos(320, 615);
		player->useTake2();
		turn_recover = true;
	}

	//使用技能1
	if (sk1->containsPoint(point))
	{
		if (player->minusMp(600))
		{
			heromp->setMp(player->getMp());
			suckcount = 3;
			isSuck = true;
			auto delay = gcnew Delay(0.01);
			auto moveTo = gcnew MoveTo(0.01f, Point(sk1->getPosX() + 5, sk1->getPosY()));
			auto moveTo2 = gcnew MoveTo(0.01f, Point(sk1->getPosX() - 5, sk1->getPosY()));
			auto moveTo3 = gcnew MoveTo(0.01f, Point(sk1->getPosX(), sk1->getPosY()));
			auto sequence = gcnew Sequence({ moveTo, delay, moveTo2, delay, moveTo3 });
			auto loop = gcnew Loop(sequence, 5);
			sk1->runAction(loop);
		}
			
	}
	//使用技能2
		if (sk2->containsPoint(point))
		{
			if (player->minusMp(400))
			{
				heromp->setMp(player->getMp());
				auto delay = gcnew Delay(0.01);
				angrycount = 2;
				isAngry = true;
				auto moveTo = gcnew MoveTo(0.01f, Point(sk2->getPosX() + 5, sk2->getPosY()));
				auto moveTo2 = gcnew MoveTo(0.01f, Point(sk2->getPosX() - 5, sk2->getPosY()));
				auto moveTo3 = gcnew MoveTo(0.01f, Point(sk2->getPosX(), sk2->getPosY()));
				auto sequence = gcnew Sequence({ moveTo, delay, moveTo2, delay, moveTo3 });
				auto loop = gcnew Loop(sequence, 5);
				sk2->runAction(loop);
			}
		
	}
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
	//每点击任何棋子则返回一个负数
	return Point(-1, -1);
}

//点击事件响应
//@param int button: 
//ret: Point 点击棋子所在的行和列组成的点
void BoardScene::onClick(int button)
{
	//未点击棋子返回
	Point index = getPointInBlock(Input::getMousePos());
	if (index.x == -1)
	{
		action->setUnSelected(e_i, e_j);
		action->setUnSelected(s_i, s_j);
		return;
	}
	//左键按下
	if (button == 0)
	{

		//第一次点击
		if (!first_choose)
		{
			action->setSelected(index.x, index.y);
			s_i = index.x;
			s_j = index.y;
			first_choose = true;
		}
		//第二次点击，并交换
		else
		{
			e_i = index.x;
			e_j = index.y;
			action->setUnSelected(s_i, s_j);
			if (abs(s_i - e_i) == 1 && s_j - e_j == 0)
			{
				action->changeV(s_i, s_j, e_i, e_j);
				if (action->delete_() > 0)
				{
					action->delete_();
					action->delete_();
					turn++;
				}
				else
				{
					action->changeV(e_i, e_j, s_i, s_j);
				}
			}
			else if (abs(s_j - e_j) == 1 && s_i - e_i == 0)
			{
				action->changeH(s_i, s_j, e_i, e_j);
				if (action->delete_() > 0)
				{
					action->delete_();
					action->delete_();
					turn++;
				}
				else
				{
					action->changeH(e_i, e_j, s_i, s_j);
				}
			}
			if (turn % 3 == 0)
			{
				//action->shakeBoard();
				aaction->attackPlayer(500);
				auto moveTo = gcnew MoveTo(0.01f, Point(herohp->getPosX() + 5, herohp->getPosY()));
				auto moveTo2 = gcnew MoveTo(0.01f, Point(herohp->getPosX() - 5, herohp->getPosY()));
				auto moveTo3 = gcnew MoveTo(0.01f, Point(herohp->getPosX(), herohp->getPosY()));
				auto sequence = gcnew Sequence({ moveTo, moveTo2, moveTo3 });
				auto loop = gcnew Loop(sequence, 5);
				herohp->runAction(loop);
				herohp->setHp(player->getHp());
				//玩家被打败，游戏
				if (player->getHp() == 0)
				{
					_gameover = true;
					deadGame *d = gcnew deadGame();
					SceneManager::enter(d);
				}
			}
			//计算收到的总攻击
			int attacked = action->getTotalAttack();
			//如果没有扣到0，就更新血条
			if ( attacked >= 0)
			{
				if (isAngry && angrycount > 0)
				{
					aaction->attackMonster(attacked * 1.5);
					angrycount--;
				}
				else if (isSuck && suckcount > 0)
				{
					aaction->attackMonster(attacked * 1.1);
					aaction->recoverPlayer(attacked * 0.2);
					herohp->setHp(player->getHp());
					angrycount--;
				}
				else
				{
					aaction->attackMonster(attacked );
				}
				
				if (attacked > 0)
					aaction->shakeMonster();
				enemyhp->setHp(mon->getHP());
			}
			//打败怪物，游戏退出
			else
			{
				_gameover = true;
				SceneManager::back();
			}
			//棋子回复
			int recovered = action->getTotalRecover();
			aaction->recoverPlayer(recovered);
			herohp->setHp(player->getHp());
			//吸血
			if (turn_recover && turn_recover_letf_count > 0)
			{
				aaction->recoverPlayer(1000 * 0.15);
				herohp->setHp(player->getHp());
				turn_recover_letf_count--;
			}
			//更新怒气条
			int angerd = action->getTotalAnger();
			aaction->angerPlayer(angerd);
			heromp->setMp(player->getMp());
			first_choose = false;
			//action->shakeBoard();
		}
	}
}

//重载的刷新函数，有待和陈叠鑫的融合
//ret: void
void BoardScene::onUpdate()
{
	if (_gameover)
		return;

	if (Input::isPress(MouseCode::Left))
	{
		cout << "pressed" << endl;
		onClick(0);
	}
	else if (Input::isRelease(KeyCode::Esc)) {
		auto pauseGameScene = gcnew pauseGame();
		saveGame();
		SceneManager::enter(pauseGameScene);
	}
	else if (Input::isRelease(KeyCode::F1)) {
		auto deadGameScene = gcnew deadGame(20, 10, 5, 7, 6);
		SceneManager::enter(deadGameScene);
	}
	else if (Input::isRelease(KeyCode::F2)) {
		auto successGameScene = gcnew successScene(1,2,1,3,1);
		SceneManager::enter(successGameScene);
	}
}

void BoardScene::showTip()
{
	action->showTip();
}

void BoardScene::newGame()
{
	addTakes();
	addSkills();
	action->randomCreate();

}

//添加道具
void BoardScene::addTakes()
{
	if (player->getTake1() == 1)
	{
		s1 = new Sprite(L"./img/t1.png");
		s1->setSize(80, 80);
		s1->setPos(220, 615);
		this->addChild(s1);
	}
	else if (player->getTake1() == 2)
	{
		s1 = new Sprite(L"./img/t2.png");
		s1->setSize(80, 80);
		s1->setPos(220, 615);
		this->addChild(s1);
	}

	if (player->getTake2() == 1)
	{
		s2 = new Sprite(L"./img/t1.png");
		s2->setSize(80, 80);
		s2->setPos(320, 615);
		this->addChild(s2);
	}
	else if (player->getTake2() == 2)
	{
		s2 = new Sprite(L"./img/t2.png");
		s2->setSize(80, 80);
		s2->setPos(320, 615);
		this->addChild(s2);
	}
}

//添加技能
void BoardScene::addSkills()
{
	if (player->getSkill1() == 1)
	{
		sk1 = new Sprite(L"./img/skill1.png");
		sk1->setSize(80, 80);
		sk1->setPos(20, 615);
		cout << "this" << endl;
		this->addChild(sk1);
	}
	else if (player->getSkill1() == 2)
	{
		sk1 = new Sprite(L"./img/skill2.png");
		sk1->setSize(80, 80);
		sk1->setPos(20, 615);
		this->addChild(sk1);
	}

	if (player->getSkill2() == 1)
	{
		sk2 = new Sprite(L"./img/skill1.png");
		sk2->setSize(80, 80);
		sk2->setPos(120, 615);
		this->addChild(sk2);
	}
	else if (player->getSkill2() == 2)
	{
		sk2 = new Sprite(L"./img/skill2.png");
		sk2->setSize(80, 80);
		sk2->setPos(120, 615);
		this->addChild(sk2);
	}
}


//当按esc的时候，保存棋盘
void BoardScene::saveGame()
{
	int **a = action->copyBoard();
	string path = player->getName() + "_record.txt";
	ofstream outfile(path);
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{

			outfile << a[i][j] << " ";
		}
		outfile << endl;
	}
	/*vector<int> v = action->getCounts();
	for (int i = 0; i < v.size(); i++)
	{
		outfile << v.at(i) << endl;
	}*/
	outfile << lcount << endl;
	outfile << player->getHp() << endl;
	outfile << player->getMp() << endl;
	outfile << mon->getHP() << endl;
	outfile << player->getTake1() << endl;
	outfile << player->getTake2() << endl;
	

}

//从文件中依次读取信息
void BoardScene::reloadGame()
{
	string path = player->getName() + "_record.txt";
	ifstream myfile(path);
	for (int i = 0; i < ROWS; i++)
	{
		string line;
		getline(myfile, line);
		
		for (int j = 0; j < COLS; j++)
		{
			int num = line[2 * j] - 48;
			chessboard[i][j] = num;
		}
	}
	string temp;
	getline(myfile, temp);
	lcount = stoi(temp);
	getline(myfile, temp);
	herohp->setHp(stoi(temp));
	getline(myfile, temp);
	heromp->setMp(stoi(temp));
	getline(myfile, temp);
	enemyhp->setHp(stoi(temp));
	getline(myfile, temp);
	player->setTake1(stoi(temp));
	getline(myfile, temp);
	player->setTake2(stoi(temp));
	addTakes();
	addSkills();
	action->reload(chessboard);
	leftCount->setText(to_wstring(lcount));
}