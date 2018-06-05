#include"firstscene.h"
#include"../../Genius/2d/layer.h"
#include"../../Genius/2d/colorfullayout.h"
#include"firstlayer.h"
//�˴�scene layer ���ײ���ͷ�ļ�ѭ������

bool FirstScene::init()
{
		//��ʼ������init
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

