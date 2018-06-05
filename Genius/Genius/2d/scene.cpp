#include"scene.h"

//构造与析构
Scene::Scene()
{
}

Scene::~Scene()
{
}


Scene *Scene::create()
{
	Scene *ret = new Scene();
    if (ret && ret->init())
    {
        ret->autorelease();
        return ret;
    }
    else
    {
        Logn("createScene failed!");
        return nullptr;
    }
}

bool Scene::init()
{
	return true;
}