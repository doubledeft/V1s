#include "deadGame.h"

deadGame::deadGame()
{

	numOptionHeight = 3 + 1;
	numOptionWidth = 1;

	this->menuBackImg = new Image(L"./img/deadSceneImage.png");
	this->backImgGame = gcnew Sprite(menuBackImg);

	/*int a = 10;
	wstring gameEnd = L"游戏结束";
	gameEnd.append(to_wstring(a));
	this->textDeadGame= gcnew Text(gameEnd, Font(L"黑体", 100, Font::Weight::Bold));*/

	this->textDeadGame = gcnew Text(L"游戏结束", Font(L"黑体", 100, Font::Weight::Bold));
	this->textDeadGame->setColor(Color::Black);
	this->textRestartGame = gcnew Text(L"重新开始游戏", Font(L"宋体", 30, Font::Weight::Bold));
	this->textBackMenu = gcnew Text(L"返回主菜单", Font(L"宋体", 30, Font::Weight::Bold));



	SceneAdjust();

	this->addChild(backImgGame);
	this->addChild(textDeadGame);
	this->addChild(textRestartGame);
	this->addChild(textBackMenu);
}
//传参构造函数，金币数量，三消次数,四消次数，五消次数，超级消除次数
deadGame::deadGame(int goldCount, int timesThreeClear, int timesFourClear, int timesFiveClear, int timesSuperClear)
{
	numOptionHeight = 5 + 1;
	numOptionWidth = 2 + 1;

	this->menuBackImg = new Image(L"./img/deadSceneImage.png");
	this->backImgGame = gcnew Sprite(menuBackImg);


	wstring wstrGold = L"获得金币：";
	wstrGold.append(to_wstring(goldCount));
	this->TextGold = gcnew Text(wstrGold, Font(L"宋体", 30, Font::Weight::Bold));
	this->TextGold->setColor(Color::BlueViolet);

	wstring wstrThreeClear = L"三消次数:";
	wstrThreeClear.append(to_wstring(timesThreeClear));
	wstrThreeClear.append(L"次");
	this->TextThreeClear = gcnew Text(wstrThreeClear, Font(L"宋体", 30, Font::Weight::Bold));
	this->TextThreeClear->setColor(Color::BlueViolet);

	wstring wstrFourClear = L"四消次数:";
	wstrFourClear.append(to_wstring(timesFourClear));
	wstrFourClear.append(L"次");
	this->TextFourClear = gcnew Text(wstrFourClear, Font(L"宋体", 30, Font::Weight::Bold));
	this->TextFourClear->setColor(Color::BlueViolet);

	wstring wstrFiveClear = L"五消次数:";
	wstrFiveClear.append(to_wstring(timesFiveClear));
	wstrFiveClear.append(L"次");
	this->TextFiveClear = gcnew Text(wstrFiveClear, Font(L"宋体", 30, Font::Weight::Bold));
	this->TextFiveClear->setColor(Color::BlueViolet);

	wstring wstrSuperClear = L"超级消除次数:";
	wstrSuperClear.append(to_wstring(timesSuperClear));
	wstrSuperClear.append(L"次");
	this->TextSuperClear = gcnew Text(wstrSuperClear, Font(L"宋体", 30, Font::Weight::Bold));
	this->TextSuperClear->setColor(Color::BlueViolet);


	this->textDeadGame = gcnew Text(L"游戏结束", Font(L"宋体", 70, Font::Weight::Bold));
	this->textDeadGame->setColor(Color::Purple);
	this->textRestartGame = gcnew Text(L"重新开始游戏", Font(L"宋体", 40, Font::Weight::Bold));
	this->textBackMenu = gcnew Text(L"返回主菜单", Font(L"宋体", 40, Font::Weight::Bold));



	SceneAdjustTwo();

	this->addChild(backImgGame);
	this->addChild(textDeadGame);
	this->addChild(textRestartGame);
	this->addChild(textBackMenu);

	this->addChild(TextGold);
	this->addChild(TextThreeClear);
	this->addChild(TextFourClear);
	this->addChild(TextFiveClear);
	this->addChild(TextSuperClear);
}




void deadGame::onUpdate()
{
	if (Input::isRelease(MouseCode::Left)) {
		onClick();
	}
}

void deadGame::onClick()
{
	auto point = Input::getMousePos();
	if (this->textRestartGame->containsPoint(point)) {
		BoardScene* bs = new BoardScene(true);
		SceneManager::enter(bs);
	}
	else if (this->textBackMenu->containsPoint(point)) {
		/*auto menu = gcnew MenuMain();
		SceneManager::enter(menu);*/

		SceneManager::back();
		SceneManager::back();
	}

}

void deadGame::SceneAdjust()
{
	//背景
	float scaleBackX = Window::getWidth() / this->menuBackImg->getWidth();
	float scaleBackY = Window::getHeight() / this->menuBackImg->getHeight();
	this->backImgGame->setScale(scaleBackX, scaleBackY);
	this->backImgGame->setAnchor(0.5, 0.5);
	this->backImgGame->setPos(Window::getWidth() / 2, Window::getHeight() / 2);

	this->textDeadGame->setAnchor(0.5, 0.5);
	this->textDeadGame->setPos(Window::getWidth() / 2, Window::getHeight() / numOptionHeight * 1);
	this->textRestartGame->setAnchor(0.5, 0.5);
	this->textRestartGame->setPos(Window::getWidth() / 2, Window::getHeight() / numOptionHeight * 2);
	this->textBackMenu->setAnchor(0.5, 0.5);
	this->textBackMenu->setPos(Window::getWidth() / 2, Window::getHeight() / numOptionHeight * 3);



}

void deadGame::SceneAdjustTwo()
{
	//背景
	float scaleBackX = Window::getWidth() / this->menuBackImg->getWidth();
	float scaleBackY = Window::getHeight() / this->menuBackImg->getHeight();
	this->backImgGame->setScale(scaleBackX, scaleBackY);
	this->backImgGame->setAnchor(0.5, 0.5);
	this->backImgGame->setPos(Window::getWidth() / 2, Window::getHeight() / 2);

	this->textDeadGame->setAnchor(0.5, 0.5);
	this->textDeadGame->setPos(Window::getWidth() / numOptionWidth * 2, Window::getHeight() / numOptionHeight * 1);
	this->textRestartGame->setAnchor(0.5, 0.5);
	this->textRestartGame->setPos(Window::getWidth() / numOptionWidth * 2, Window::getHeight() / numOptionHeight * 3);
	this->textBackMenu->setAnchor(0.5, 0.5);
	this->textBackMenu->setPos(Window::getWidth() / numOptionWidth * 2, Window::getHeight() / numOptionHeight * 5);

	this->TextGold->setAnchor(0.5, 0.5);
	this->TextGold->setPos(Window::getWidth() / numOptionWidth * 1, Window::getHeight() / numOptionHeight * 1);
	this->TextThreeClear->setAnchor(0.5, 0.5);
	this->TextThreeClear->setPos(Window::getWidth() / numOptionWidth * 1, Window::getHeight() / numOptionHeight * 2);
	this->TextFourClear->setAnchor(0.5, 0.5);
	this->TextFourClear->setPos(Window::getWidth() / numOptionWidth * 1, Window::getHeight() / numOptionHeight * 3);
	this->TextFiveClear->setAnchor(0.5, 0.5);
	this->TextFiveClear->setPos(Window::getWidth() / numOptionWidth * 1, Window::getHeight() / numOptionHeight * 4);
	this->TextSuperClear->setAnchor(0.5, 0.5);
	this->TextSuperClear->setPos(Window::getWidth() / numOptionWidth * 1, Window::getHeight() / numOptionHeight * 5);
}

