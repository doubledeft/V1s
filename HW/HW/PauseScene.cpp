#include "PauseScene.h"
pauseGame::pauseGame()
{

	int 	numOptionHeightNum = 3 + 1;
	int 	numOptionWidthNum = 1;

	this->menuBackImg = new Image(L"./img/menuBackImage.png");
	this->backImgGame = gcnew Sprite(menuBackImg);

	//文本
	this->textContinuGame = gcnew Text(L"继续游戏", Font(L"宋体", 30, Font::Weight::Bold)); 
		this->textOption = gcnew Text(L"帮助和选项", Font(L"宋体", 30, Font::Weight::Bold));
	this->textBackMenu = gcnew Text(L"返回主菜单", Font(L"宋体", 30, Font::Weight::Bold));


	//位置
	this->textContinuGame->setAnchor(0.5, 0.5);
	this->textOption->setAnchor(0.5, 0.5);
	this->textBackMenu->setAnchor(0.5, 0.5);
	this->textContinuGame->setPos(Window::getWidth() / 2, Window::getHeight() / numOptionHeightNum * 1);
	this->textOption->setPos(Window::getWidth() / 2, Window::getHeight() / numOptionHeightNum * 2);
	this->textBackMenu->setPos(Window::getWidth() / 2, Window::getHeight() / numOptionHeightNum * 3);


	this->addChild(backImgGame);
	this->addChild(textContinuGame);
	this->addChild(textOption);
	this->addChild(textBackMenu);
}

void pauseGame::onUpdate()
{
	if (Input::isRelease(MouseCode::Left)) {
		onClick();
	}
}

void pauseGame::onClick()
{
	auto point = Input::getMousePos();
	if (this->textContinuGame->containsPoint(point)) {
		SceneManager::back();
	}
	else if (this->textOption->containsPoint(point)) {
		auto optionScene = gcnew menuOption();
		SceneManager::enter(optionScene);
	}
	else if (this->textBackMenu->containsPoint(point)) {
	/*	SceneManager::clear();*/
	/*	auto  menu = gcnew MenuMain();
		SceneManager::enter(menu);*/

		SceneManager::back();
		SceneManager::back();
	}
}


