#include"firstscene.h"
#include"../../Genius/2d/layer.h"
#include"../../Genius/2d/colorfullayout.h"
#include"firstlayer.h"
//此处scene layer 容易产生头文件循环依赖

bool FirstScene::init()
{
		//初始化父级init
	if ( !Scene::init() )
    {
        return false;
    }


	//auto colorLayer= ColorfulLayer::create(RGB(241,124,103));
	//addChild(colorLayer);

	auto bgsprite=Sprite::createSprite("prebg.jpg");
	addChild(bgsprite);

	auto fistlayer =FirstLayer::create();
	addChild(fistlayer);
	return true;
}

FirstScene* FirstScene::create()
{
	auto scene = new FirstScene();
	if(scene->init())
	{
		return scene;
	}
	return nullptr;
}

