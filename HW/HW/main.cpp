#include "Menu.h"

#include <easy2d/easy2d.h>

using namespace easy2d;

int main()
{
	if (Game::init())
	{
		Window::setTitle(L"Moving Man");
		Window::setSize(1400, 800);
		// 进入 scene 场景
	/*	new	menuChoose();*/
		auto  menu = gcnew MenuMain();
		SceneManager::enter(menu);
		Game::start();
	// 释放内存

	
	}
	Game::destroy();
	return 0;
}
