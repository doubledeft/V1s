#include"Menu.h"
//Shop::Shop()
//{
//	//����
//	this->shopBackImg = new Image(L"./img/shopBackImage.png");
//	this->backImgGame = gcnew Sprite(this->shopBackImg);
//
//	this->scaleBackX = Window::getWidth() / this->shopBackImg->getWidth();
//	this->scaleBackY = Window::getHeight() / this->shopBackImg->getHeight();
//	this->backImgGame->setScale(scaleBackX, scaleBackY);
//	this->backImgGame->setAnchor(0.5, 0.5);
//	this->backImgGame->setPos(Window::getWidth() / 2, Window::getHeight() / 2);
//
//	this->commodityImgOne = new Image(L"./img/comodity1.png");
//	this->commodityImgTwo= new Image(L"./img/comodity2.png");
//	this->numCommdity = 1;
//
//	this->commodity=gcnew Sprite(this->commodityImgOne);
//	this->commodity->setScale(scaleBackX, scaleBackY);
//	this->commodity->setAnchor(0.5, 0.5);
//	this->commodity->setPos( Window::getWidth()*325 /1920 , Window::getHeight()* 435 / 1080);//λ��
//
//	this->wstrCommodityOne = L"ʱ�������\n���Ӷ���Ļغ���\n���ѣ�4���";
//	this->wstrCommodityTwo = L"��ʿ��\n����Ѫ������\n���ѣ�2���";
//
//		this->commodityText=gcnew Text(wstrCommodityOne, Font(L"����", 30, Font::Weight::Bold));
//	this->commodityText->setAnchor(0.5, 0.5);
//	this->commodityText->setPos(Window::getWidth() * 500 / 1920, Window::getHeight() * 850 / 1080);
//
//
//	this->addChild(backImgGame);
//	this->addChild(commodity);
//
//	this->addChild(commodityText);
//}

Shop::Shop(int goldNum)
{	

	//shop�����������
	//����
	this->shopBackImg = new Image(L"./img/shopBackImage.png");
	this->backImgGame = gcnew Sprite(this->shopBackImg);

	this->scaleBackX = Window::getWidth() / this->shopBackImg->getWidth();
	this->scaleBackY = Window::getHeight() / this->shopBackImg->getHeight();
	this->backImgGame->setScale(scaleBackX, scaleBackY);
	this->backImgGame->setAnchor(0.5, 0.5);
	this->backImgGame->setPos(Window::getWidth() / 2, Window::getHeight() / 2);

	this->commodityImgOne = new Image(L"./img/comodity1.png");
	this->commodityImgTwo = new Image(L"./img/comodity2.png");
	this->numCommdity = 1;

	this->commodity = gcnew Sprite(this->commodityImgOne);
	this->commodity->setScale(scaleBackX, scaleBackY);
	this->commodity->setAnchor(0.5, 0.5);
	this->commodity->setPos(Window::getWidth() * 325 / 1920, Window::getHeight() * 435 / 1080);//λ��

	//��Ʒ���Ѽ۸�
	this->commodityOneCost = 4;
	this->commodityTwoCost = 2;
	this->wstrCommodityOne = L"ʱ�������\n���Ӷ���Ļغ���\n����:";
	this->wstrCommodityOne.append(to_wstring(this->commodityOneCost)+L"���");
	this->wstrCommodityTwo = L"��ʿ��\n����Ѫ������\n���ѣ�";
	this->wstrCommodityTwo.append(to_wstring(this->commodityTwoCost) + L"���");


	this->commodityText = gcnew Text(wstrCommodityOne, Font(L"����", 30, Font::Weight::Bold));
	this->commodityText->setAnchor(0.5, 0.5);
	this->commodityText->setPos(Window::getWidth() * 500 / 1920, Window::getHeight() * 850 / 1080);

	this->addChild(backImgGame);
	this->addChild(commodity);
	this->addChild(commodityText);

	//�����ʾ
	this->goldNum = goldNum;
	this->textGoldNum = gcnew Text(to_wstring(this->goldNum), Font(L"����", 60, Font::Weight::Bold));
	this->textGoldNum->setColor(Color::Gold);
	this->textGoldNum->setAnchor(0.5, 0.5);
	this->textGoldNum->setPos(Window::getWidth() * 175 / 1920, Window::getHeight() * 80/ 1080);
	this->addChild(textGoldNum);

}

void Shop::onUpdate()
{
	if (Input::isRelease(MouseCode::Left)) {
		onClick();

	}
	else if (Input::isRelease(KeyCode::A)) {
		if (numCommdity == 1) {
			this->commodity->open(commodityImgTwo);
			this->commodityText->setText(this->wstrCommodityTwo);
			numCommdity = 2;
		}
		else if(numCommdity == 2){
			this->commodity->open(commodityImgOne);
			this->commodityText->setText(this->wstrCommodityOne);
			numCommdity = 1;
		}
	}
	else if (Input::isRelease(KeyCode::D)) {
		if (numCommdity == 1) {
			this->commodity->open(commodityImgTwo);
			this->commodityText->setText(this->wstrCommodityTwo);
			numCommdity = 2;
		}
		else if (numCommdity == 2) {
			this->commodity->open(commodityImgOne);
			this->commodityText->setText(this->wstrCommodityOne);
			numCommdity = 1;
		}
	}

	if (Input::isRelease(KeyCode::Enter)) {
		//���س���������Ʒ�����ú���
		if (numCommdity == 1) {
			this->goldNum -= this->commodityOneCost;
			this->textGoldNum->setText(to_wstring(goldNum));
		}
		else if (numCommdity == 2) {
			this->goldNum -= this->commodityTwoCost;
			this->textGoldNum->setText(to_wstring(goldNum));
		}
	}
	else if(Input::isRelease(KeyCode::Esc))
	{
		SceneManager::back();
	}
}

void Shop::onClick()
{
}
