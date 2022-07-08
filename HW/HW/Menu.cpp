#include "Menu.h"
#include "BoardScene.h"

MenuMain::MenuMain()
{
numOptionHeightNum =6;
numOptionWidthNum = 1;

//背景
	this->menuBackImg = new Image(L"./img/menuBackImage.png");
	this->backImgGame = gcnew Sprite(menuBackImg);

	//文本
	this->textBeginGame = gcnew Text(L"开始游戏", Font(L"宋体", 30, Font::Weight::Bold));
	this->textContinueGame = gcnew Text(L"继续游戏", Font(L"宋体", 30, Font::Weight::Bold));
	this->textShopGame = gcnew Text(L"游戏商城", Font(L"宋体", 30, Font::Weight::Bold));
	this->textOptionGame = gcnew Text(L"帮助和选项", Font(L"宋体", 30, Font::Weight::Bold));
	this->textQuitGame = gcnew Text(L"退出游戏", Font(L"宋体", 30, Font::Weight::Bold));

	SceneAdjust();

	this->addChild(this->backImgGame);
	this->addChild(this->textBeginGame);
	this->addChild(this->textContinueGame);
	this->addChild(this->textShopGame);
	this->addChild(this->textOptionGame);
	this->addChild(this->textQuitGame);
}

void MenuMain::onUpdate()
{
	if (Input::isRelease(MouseCode::Left)) {
		onClick();
	}else if (Input::isRelease(KeyCode::F1)) {
		auto heroChoose = gcnew HeroChoose();
		SceneManager::enter(heroChoose);
	}
	SceneAdjust();
}

void MenuMain::onClick()
{
	auto point = Input::getMousePos();
	if (this->textBeginGame->containsPoint(point)) {
		// 点击按钮，进入游戏主场景
		BoardScene* bs = new BoardScene(true);
		SceneManager::enter(bs);
	}
	else if (this->textContinueGame->containsPoint(point))
	{

		BoardScene* bs = new BoardScene(false);
		SceneManager::enter(bs);
	}
	else if (this->textShopGame->containsPoint(point))
	{
	
		/*auto shop = gcnew Shop();*/
		auto shop = gcnew Shop(15);//构造函数，拥有15枚金币
		SceneManager::enter(shop);
	}
	else if (this->textOptionGame->containsPoint(point))
	{	
		auto option = gcnew menuOption();
		SceneManager::enter(option);
	}

	else if (this->textQuitGame->containsPoint(point))
	{
		Game::destroy();

	}

}

void MenuMain::SceneAdjust()
{
	//设定位置
	float scaleBackX = Window::getWidth() / this->menuBackImg->getWidth();
	float scaleBackY = Window::getHeight() / this->menuBackImg->getHeight();
	this->backImgGame->setScale(scaleBackX, scaleBackY);
	this->backImgGame->setAnchor(0.5, 0.5);
	this->backImgGame->setPos(Window::getWidth() / 2, Window::getHeight() / 2);

	this->backImgGame->setAnchor(0.5, 0.5);
	this->backImgGame->setPos(Window::getWidth() / 2, Window::getHeight() / 2);
	this->textBeginGame->setAnchor(0.5, 0.5);
	this->textBeginGame->setPos(Window::getWidth() / 2, Window::getHeight() / numOptionHeightNum);
	this->textContinueGame->setAnchor(0.5, 0.5);
	this->textContinueGame->setPos(Window::getWidth() / 2, Window::getHeight() / numOptionHeightNum * 2);
	this->textShopGame->setAnchor(0.5, 0.5);
	this->textShopGame->setPos(Window::getWidth() / 2, Window::getHeight() / numOptionHeightNum * 3);
	this->textOptionGame->setAnchor(0.5, 0.5);
	this->textOptionGame->setPos(Window::getWidth() / 2, Window::getHeight() / numOptionHeightNum * 4);
	this->textQuitGame->setAnchor(0.5, 0.5);
	this->textQuitGame->setPos(Window::getWidth() / 2, Window::getHeight() / numOptionHeightNum * 5);
}





MenuPara::MenuPara() {



	menuBeginImg = new Image(L"./img/menushape.png");
	menuBackImg = new Image(L"./img/menuBackImage.png");
	numMenuObject = 5;
}

