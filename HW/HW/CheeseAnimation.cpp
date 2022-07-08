#include "CheeseAnimation.h"

CheeseAnimation::CheeseAnimation()
{

}

CheeseAnimation::~CheeseAnimation()
{

}


//����һ��:����ʹ��
void CheeseAnimation::ToFallByOne(Button* s)
{
	auto moveTo = gcnew MoveTo(0.5f, Point(s->getPosX(), s->getPosY() + SIze));
	auto sequence = gcnew Sequence({ moveTo});
	s->runAction(sequence);
}

//����һ��
void CheeseAnimation::ToUperByOne(Button* s)
{
	auto moveTo = gcnew MoveTo(0.5f, Point(s->getPosX(), s->getPosY() - SIze));
	s->runAction(moveTo);
}

//����һ��
void CheeseAnimation::ToLeftByOne(Button* s) {
	auto moveTo = gcnew MoveTo(0.5f, Point(s->getPosX() - SIze, s->getPosY()));
	s->runAction(moveTo);
}
//���������ҷ����ӽ���
void CheeseAnimation::ToRightByOne(Button* s) {
	auto moveTo = gcnew MoveTo(0.5f, Point(s->getPosX() + SIze, s->getPosY()));
	s->runAction(moveTo);
}
//������ʧ
void CheeseAnimation::Boomb(Button* s) {
	auto fadeOut = gcnew FadeOut(1);
	s->runAction(fadeOut);
	
	
}

//������ʧ
void CheeseAnimation::Recover(Button* s) {
	auto fadeOut = gcnew FadeIn(2);
	auto delay = gcnew Delay(2.5f);
	auto seq = gcnew Sequence();
	seq->add(delay);
	seq->add(fadeOut);
	s->runAction(seq);
}

//��������
void CheeseAnimation::ToFallByN(Button* s, int n, float delay_time) {

	auto moveTo = gcnew MoveTo(2.5f, Point(s->getPosX(), s->getPosY() + n * SIze));
	auto seq = gcnew Sequence();
	auto delay = gcnew Delay(delay_time);
	seq->add(delay);
	seq->add(moveTo);
	s->runAction(seq);
	//s->setPos(s->getPosX(), s->getPosY() + n * SIze);
}

//��������
void CheeseAnimation::ToUPByN(Button* s, int n, float delay_time) {

	auto moveTo = gcnew MoveTo(2.5f, Point(s->getPosX(), s->getPosY() - n * SIze));
	auto fade = gcnew FadeOut(0);
	auto fade2 = gcnew FadeIn(0);
	auto seq = gcnew Sequence();
	auto delay = gcnew Delay(delay_time);
	seq->add(delay);
	//seq->add(fade);
	seq->add(moveTo);
	//seq->add(fade2);
	s->runAction(seq);
	//s->setPos(s->getPosX(), s->getPosY() + n * SIze);
}

void CheeseAnimation::shine(Button* s)
{
	auto sequence = gcnew Sequence();
	auto fadeOut = gcnew FadeOut(0.5);
	auto fadeIn = gcnew FadeIn(0.5);
	auto fadeOut2 = gcnew FadeOut(0.5);
	auto fadeIn2 = gcnew FadeIn(0.5);
	sequence->add(fadeOut);
	sequence->add(fadeIn);
	sequence->add(fadeOut2);
	sequence->add(fadeIn2);
	s->runAction(sequence);
}