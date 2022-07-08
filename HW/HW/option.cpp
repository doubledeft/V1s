#include"Menu.h"
menuOption::menuOption()
{
	numOptionHeightNum = 1;
	numOptionWidthNum = 2;

	resolutionState = 0;//�ֱ���״̬����ʼ

//����
	this->menuBackImg = new Image(L"./img/menuBackImage.png");
	this->backImgGame = gcnew Sprite(menuBackImg);




	//�ı�
	//��������ֱ���
	this->textResolution = gcnew Text(L"�ֱ���", Font(L"����", 30, Font::Weight::Bold));
	this->textResolutionChange = gcnew Text(L"1080��600 [14:8]", Font(L"����", 30, Font::Weight::Bold));
	//�����ı�
	this->textBackMenu = gcnew Text(L"ESC ����", Font(L"����", 20, Font::Weight::Bold));
	//����λ��
	OptionAdjust();

	//������ݵ���Ļ��
	this->addChild(backImgGame);
	this->addChild(textResolution);
	this->addChild(this->textResolutionChange);
	this->addChild(textBackMenu);

}

void menuOption::onUpdate()
{
	if (Input::isRelease(MouseCode::Left)) {
		onClick();
	}
	else if (Input::isRelease(KeyCode::Esc)) {
		SceneManager::back();
	}

}

void menuOption::onClick()
{
	auto point = Input::getMousePos();
	if (this->textResolutionChange->containsPoint(point)) {
		if (resolutionState == 0) {
			textResolutionChange->setText(L"1680��1050 [16:10]");
			Window::setSize(1600, 960);
			Game::reset();
			OptionAdjust();
			resolutionState = 1;
		}
		else if (resolutionState == 1) {
			textResolutionChange->setText(L"1400��800 [14:8]");
			Window::setSize(1400, 800);
			Game::reset();
			OptionAdjust();
			resolutionState = 0;
		}

	}
}

void menuOption::OptionAdjust()
{

	//����
	//float scaleBackX = Window::getWidth() / this->menuBackImg->getWidth();
	//float scaleBackY = Window::getHeight() / this->menuBackImg->getHeight();
	//this->backImgGame->setScale(scaleBackX, scaleBackY);
	this->backImgGame->setAnchor(0.5, 0.5);
	this->backImgGame->setPos(Window::getWidth() / 2, Window::getHeight() / 2);

	//�ı�
	this->textResolution->setAnchor(0.5, 0.5);
	this->textResolution->setPos(Window::getWidth() / (numOptionWidthNum + 1) * 1, Window::getHeight() / (numOptionHeightNum + 1));
	this->textResolutionChange->setAnchor(0.5, 0.5);
	this->textResolutionChange->setPos(Window::getWidth() / (numOptionWidthNum + 1) * 2, Window::getHeight() / (numOptionHeightNum + 1));

	this->textBackMenu->setAnchor(0.5, 0.5);
	this->textBackMenu->setPos(Window::getWidth() / 2, Window::getHeight() - 20);
}

