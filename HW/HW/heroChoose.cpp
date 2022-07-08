#include"Menu.h"

HeroChoose::HeroChoose() {

	this->heroOneClick = 0;
	this->heroTwoClick = 0;

	this->menuBackImg = new Image(L"./img/heroChoose/backImg.png");
	this->backImgGame = gcnew Sprite(menuBackImg);

	//设定位置
	float scaleBackX = Window::getWidth() / this->menuBackImg->getWidth();
	float scaleBackY = Window::getHeight() / this->menuBackImg->getHeight();
	this->backImgGame->setScale(scaleBackX, scaleBackY);
	this->backImgGame->setAnchor(0.5, 0.5);
	this->backImgGame->setPos(Window::getWidth() / 2, Window::getHeight() / 2);


	this->heroOneImg = new Image(L"./img/heroChoose/heroOne.png");
	this->heroOneChooseImg = new Image(L"./img/heroChoose/heroOneChoose.png");
	this->heroTwoImg= new Image(L"./img/heroChoose/heroTwo.png");
	this->heroTwoChooseImg= new Image(L"./img/heroChoose/heroTwoChoose.png");
	Image* shopIconImg= new Image(L"./img/heroChoose/shopIcon.png");
	this->shopIcon = gcnew Sprite(shopIconImg);
	Image* optionIconImg = new Image(L"./img/heroChoose/optionIcon.png");
	this->optionIcon = gcnew Sprite(optionIconImg);


	this->heroOne = gcnew Sprite(heroOneImg);
	this->heroTwo = gcnew Sprite(heroTwoImg);

	heroOne->setScale(scaleBackX, scaleBackY);
	heroOne->setPos(Window::getWidth() * 589 / 1920, Window::getHeight() * 311 / 1080);
	heroTwo->setScale(scaleBackX, scaleBackY);
	heroTwo->setPos(Window::getWidth() * 704 / 1920, Window::getHeight() * 431 / 1080);
	shopIcon->setScale(scaleBackX, scaleBackY);
	shopIcon->setPos(Window::getWidth() * 1710 / 1920, Window::getHeight() * 32 / 1080);
	optionIcon->setScale(scaleBackX, scaleBackY);
	optionIcon->setPos(Window::getWidth() * 1811 / 1920, Window::getHeight() * 27 / 1080);

	this->addChild(this->backImgGame);
	this->addChild(this->heroOne);
	this->addChild(this->heroTwo);
	this->addChild(this->shopIcon);
	this->addChild(this->optionIcon);
}
void HeroChoose::onUpdate() {

	
	if (Input::isRelease(MouseCode::Left)) {
		onClick();
	}
	

}
void HeroChoose::onClick() {
	auto point = Input::getMousePos();
	
	if (this->heroOne->containsPoint(point)) {
		//点击一次高亮，点击两次选择英雄

		if (heroTwoClick == 1) {
			heroTwoClick = 0;
			this->heroTwo->open(this->heroTwoImg);
		}

	
		if (heroOneClick == 0) {
			this->heroOne->open(this->heroOneChooseImg);
			heroOneClick++;
		}
		else if(heroOneClick==1)
		{
			//进入下一界面
			//调用下一界面函数

			
			this->heroOne->open(this->heroOneImg);
			heroOneClick = 0;
		}

	}
	else if (this->heroTwo->containsPoint(point))
	{
		if (heroOneClick == 1) {
			heroOneClick = 0;
			this->heroOne->open(this->heroOneImg);
		}

		

		if (heroTwoClick == 0) {
			this->heroTwo->open(this->heroTwoChooseImg);
			heroTwoClick++;
		}
		else if (heroTwoClick == 1)
		{
			this->heroTwo->open(this->heroTwoImg);
			heroTwoClick=0;
			//进入下一界面
	
		}

	}
	else if (this->shopIcon->containsPoint(point)) {

		//进入商店

		//auto shop = gcnew Shop();//构造函数，默认
		//SceneManager::enter(shop);
	}
	else if (this->optionIcon->containsPoint(point)) {
		//进入设置

		//auto option = gcnew menuOption();
		//SceneManager::enter(option);
	}
}