#include"App.h"
#include"firstlayer.h"
#include"firstscene.h"
bool App::init()
{
	auto director = Director::getInstance();
	//Macros::screenSize=Vec2(1280,960);
	Macros::screenSize=Vec2(1200,800);
	//auto scene = FirstLayer::createScene();
	auto scene = FirstScene::create();
	//scene->addChild(FirstLayer::create());
	//scene->head->listChild();
	director->runWithScene(scene);
	return true;
}