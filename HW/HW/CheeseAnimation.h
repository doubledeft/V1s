#pragma once
#include "Cheese.h"
#include <vector>
#include <easy2d/easy2d.h>
#include "Windows.h"

using namespace easy2d;
using namespace std;

class CheeseAnimation {
private:
	CheeseAnimation();
	~CheeseAnimation();
public:
	//棋子下落
	void ToFallByN(Button* s, int n, float delay_time);
	void ToUPByN(Button* s, int n, float delay_time);
	//下落一格
	void ToFallByOne(Button* s);
	//上升一格
	void ToUperByOne(Button* s);
	//向左一格
	void ToLeftByOne(Button* s);
	//向右一格
	void ToRightByOne(Button* s);
	//棋子消失
	void Boomb(Button* s);
	//棋子从透明显示回来
	void Recover(Button* s);
	//棋子闪烁
	void shine(Button* s);
};
