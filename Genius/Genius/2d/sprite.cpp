#include"sprite.h"

//Sprite构造函数
Sprite::Sprite(string p)
{
	this->path=string("D:\\VS2012_projecrs\\Genius\\Genius\\win32\\resource\\")+p;
	size=0;
	img=0;
}

Sprite* Sprite::createSprite(string path)
{
	Sprite *sprite=new Sprite(path);
	if(sprite->init())
	{
		//加入自释放池
		sprite->autorelease();
		return sprite;
	}
	return nullptr;
}


//初始化函数
bool Sprite::init()
{
	//cout<<path.c_str()<<endl;
	//改用编码后，随便修改	
	loadimage(&img, path.c_str());
	size=Vec2(img.getwidth(),img.getheight());
	return true;
}

void Sprite::draw()
{
	//判断是否可见
	if(!getVisable())
		return;

	putimage(position.getX(),position.getY(),&img);
	Node::draw();
}

void Sprite::update(float delta)
{

}

