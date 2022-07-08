#include"deadGame.h"


//传参构造函数，金币数量，三消次数,四消次数，五消次数，超级消除次数
successScene::successScene(int goldCount, int timesThreeClear, int timesFourClear, int timesFiveClear, int timesSuperClear)
{//传参构造函数，金币数量，三消次数,四消次数，五消次数，超级消除次数
	numOptionHeight = 5 + 1;
	numOptionWidth = 2 + 1;

	this->menuBackImg = new Image(L"./img/successSceneImage.png");
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


	this->textSuccessGame = gcnew Text(L"游戏结束", Font(L"宋体", 70, Font::Weight::Bold));
	this->textSuccessGame->setColor(Color::Purple);
	this->textNextGame = gcnew Text(L"开启下一关", Font(L"宋体", 40, Font::Weight::Bold));
	this->textBackMenu = gcnew Text(L"返回主菜单", Font(L"宋体", 40, Font::Weight::Bold));



	SceneAdjust();

	this->addChild(backImgGame);
	this->addChild(textSuccessGame);
	this->addChild(textNextGame);
	this->addChild(textBackMenu);

	this->addChild(TextGold);
	this->addChild(TextThreeClear);
	this->addChild(TextFourClear);
	this->addChild(TextFiveClear);
	this->addChild(TextSuperClear);
}

void successScene::onUpdate()
{
	if (Input::isRelease(MouseCode::Left)) {
		onClick();
	}
}

void successScene::onClick()
{
	auto point = Input::getMousePos();
	if (this->textNextGame->containsPoint(point)) {
		BoardScene* bs = new BoardScene(true);
		SceneManager::enter(bs);
	}
	else if (this->textBackMenu->containsPoint(point)) {

		SceneManager::back();
		SceneManager::back();
	}
}

void successScene::SceneAdjust()
{

	//背景
	float scaleBackX = Window::getWidth() / this->menuBackImg->getWidth();
	float scaleBackY = Window::getHeight() / this->menuBackImg->getHeight();
	this->backImgGame->setScale(scaleBackX, scaleBackY);
	this->backImgGame->setAnchor(0.5, 0.5);
	this->backImgGame->setPos(Window::getWidth() / 2, Window::getHeight() / 2);

	this->textSuccessGame->setAnchor(0.5, 0.5);
	this->textSuccessGame->setPos(Window::getWidth() / numOptionWidth * 2, Window::getHeight() / numOptionHeight * 1);
	this->textNextGame->setAnchor(0.5, 0.5);
	this->textNextGame->setPos(Window::getWidth() / numOptionWidth * 2, Window::getHeight() / numOptionHeight * 3);
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