#include "deadGame.h"

deadGame::deadGame()
{

	numOptionHeight = 3 + 1;
	numOptionWidth = 1;

	this->menuBackImg = new Image(L"./img/deadSceneImage.png");
	this->backImgGame = gcnew Sprite(menuBackImg);

	/*int a = 10;
	wstring gameEnd = L"��Ϸ����";
	gameEnd.append(to_wstring(a));
	this->textDeadGame= gcnew Text(gameEnd, Font(L"����", 100, Font::Weight::Bold));*/

	this->textDeadGame = gcnew Text(L"��Ϸ����", Font(L"����", 100, Font::Weight::Bold));
	this->textDeadGame->setColor(Color::Black);
	this->textRestartGame = gcnew Text(L"���¿�ʼ��Ϸ", Font(L"����", 30, Font::Weight::Bold));
	this->textBackMenu = gcnew Text(L"�������˵�", Font(L"����", 30, Font::Weight::Bold));



	SceneAdjust();

	this->addChild(backImgGame);
	this->addChild(textDeadGame);
	this->addChild(textRestartGame);
	this->addChild(textBackMenu);
}
//���ι��캯���������������������,��������������������������������
deadGame::deadGame(int goldCount, int timesThreeClear, int timesFourClear, int timesFiveClear, int timesSuperClear)
{
	numOptionHeight = 5 + 1;
	numOptionWidth = 2 + 1;

	this->menuBackImg = new Image(L"./img/deadSceneImage.png");
	this->backImgGame = gcnew Sprite(menuBackImg);


	wstring wstrGold = L"��ý�ң�";
	wstrGold.append(to_wstring(goldCount));
	this->TextGold = gcnew Text(wstrGold, Font(L"����", 30, Font::Weight::Bold));
	this->TextGold->setColor(Color::BlueViolet);

	wstring wstrThreeClear = L"��������:";
	wstrThreeClear.append(to_wstring(timesThreeClear));
	wstrThreeClear.append(L"��");
	this->TextThreeClear = gcnew Text(wstrThreeClear, Font(L"����", 30, Font::Weight::Bold));
	this->TextThreeClear->setColor(Color::BlueViolet);

	wstring wstrFourClear = L"��������:";
	wstrFourClear.append(to_wstring(timesFourClear));
	wstrFourClear.append(L"��");
	this->TextFourClear = gcnew Text(wstrFourClear, Font(L"����", 30, Font::Weight::Bold));
	this->TextFourClear->setColor(Color::BlueViolet);

	wstring wstrFiveClear = L"��������:";
	wstrFiveClear.append(to_wstring(timesFiveClear));
	wstrFiveClear.append(L"��");
	this->TextFiveClear = gcnew Text(wstrFiveClear, Font(L"����", 30, Font::Weight::Bold));
	this->TextFiveClear->setColor(Color::BlueViolet);

	wstring wstrSuperClear = L"������������:";
	wstrSuperClear.append(to_wstring(timesSuperClear));
	wstrSuperClear.append(L"��");
	this->TextSuperClear = gcnew Text(wstrSuperClear, Font(L"����", 30, Font::Weight::Bold));
	this->TextSuperClear->setColor(Color::BlueViolet);


	this->textDeadGame = gcnew Text(L"��Ϸ����", Font(L"����", 70, Font::Weight::Bold));
	this->textDeadGame->setColor(Color::Purple);
	this->textRestartGame = gcnew Text(L"���¿�ʼ��Ϸ", Font(L"����", 40, Font::Weight::Bold));
	this->textBackMenu = gcnew Text(L"�������˵�", Font(L"����", 40, Font::Weight::Bold));



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
	//����
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
	//����
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

