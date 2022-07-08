#include "Attributes.h"



EnemyHealthPoint::EnemyHealthPoint(float inithp)
{	
	

	Image* img = new Image(L"./img/hpShape.png");
	this->open(img);
	this->inithp = inithp;
	this->hp = inithp;
	this->php = this->hp / this->inithp;

	this->scalex = inithp/2000 * php;

	this->imgWidth = img->getWidth();
	this->picWidth = this->imgWidth * scalex;

	int interval = 20;//ÑªÁ¿²ÛÀëÆÁÄ»±ß¼ä¸ô
	int posy = interval;
	int posx = Window::getWidth() - interval - this->picWidth;

	this->setPos(posx, posy);


	this->setScale(this->scalex, 1);



	//ÉèÖÃÑªÁ¿µ×Ìõ
	//´ýÐÞ¸´
	Image* img2 = new Image(L"./img/hpShapeGray.png");
	auto hpGray = new Sprite();
	hpGray->open(img2);
	hpGray->setPos(996, 20);
	hpGray->setSize(383.5, this->getHeight());
}

void EnemyHealthPoint::onUpdate()
{
	
	/*if (Input::isDown(KeyCode::W))
	{
		setHp(20);
		this->setScale(this->scalex, 1);
	}
	else if (Input::isDown(KeyCode::S))
	{

		setHp(120);
		this->setScale(0.5*0.9, 1);
		
	}*/
	
	this->setScale(this->scalex, 1);
	this->setPos( Window::getWidth() - 20 - this->picWidth, 20 );
	
}


void EnemyHealthPoint::setHp(float hp)
{
	this->hp = hp;
	this->php = this->hp /this-> inithp;
	
	this->scalex = 0.5 * php;

	this->picWidth = this->imgWidth * scalex;

}



HeroHealthPoint::HeroHealthPoint(float inithp)
{
	Image* img = new Image(L"./img/hpShape.png");
	this->open(img);
	this->inithp = inithp;
	this->hp = inithp;
	this->php = this->hp / this->inithp;
	
	//Í¼Æ¬ºáÏòËõ·Å±ÈÀý
	this->scalex = this->inithp / 2000 * php;
	this->imgWidth = img->getWidth();
	this->imgHeight = img->getHeight();
	//Í¼ÐÎ¿í¶È
	this->picWidth = this->imgWidth * scalex;

	int posy = Window::getHeight()- (20 + this->imgHeight )* 2;
	int posx = 20;
	this->setPos(posx, posy);
	this->setScale(this->scalex, 1);

}

void HeroHealthPoint::onUpdate()
{
	/*if (Input::isDown(KeyCode::W))
	{
		setHp(2000);
	}
	else if (Input::isDown(KeyCode::S))
	{
		setHp(800);
	}*/
	this->setScale(this->scalex, 1);
	this->setPos( 20, Window::getHeight() - (20 + this->imgHeight) * 2);
}

void HeroHealthPoint::setHp(float hp)
{

	this->hp = hp;
	this->php = this->hp / this->inithp;

	this->scalex = this->inithp / 2000 * php;
	this->picWidth = this->imgWidth * scalex;
}







HeroMagicPoint::HeroMagicPoint(float initmp) {

	Image* img = new Image(L"./img/mpShape.png");
	this->open(img);
	this->initmp = initmp;
	this->mp = initmp;
	this->pmp = this->mp / this->initmp;
	this->scalex = initmp / 2000 * pmp;

	this->imgWidth = img->getWidth();
	this->imgHeight = img->getHeight();
	this->picWidth = this->imgWidth * scalex;

	int posy = Window::getHeight() - (20 + img->getHeight());
	int posx = 20;
	this->setPos(posx, posy);
	this->setScale(this->scalex, 1);

}

void HeroMagicPoint::onUpdate()
{
	//if (Input::isDown(KeyCode::W))
	//{
	//	setMp(2000);
	//}
	//else if (Input::isDown(KeyCode::S))
	//{
	//	setMp(800);
	//}
	this->setScale(this->scalex, 1);
	this->setPos(20, Window::getHeight() - (20 + this->imgHeight));
}

void HeroMagicPoint::setMp(float mp)
{
	this->mp= mp;
	this->pmp = this->mp / this->initmp;

	this->scalex = this->initmp / 2000 * pmp;
	this->picWidth = this->imgWidth * scalex;
}

pointEdge::pointEdge(float posx, float posy, float scalex)
{
	Image* img = new Image(L"./img/hpShapeGray.png");
	this->open(img);
	this->setPos(posx, posy);
	this->setScale(scalex, 1);
}
