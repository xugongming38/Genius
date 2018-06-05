#include"sprite.h"

//Sprite���캯��
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
		//�������ͷų�
		sprite->autorelease();
		return sprite;
	}
	return nullptr;
}


//��ʼ������
bool Sprite::init()
{
	//cout<<path.c_str()<<endl;
	//���ñ��������޸�	
	loadimage(&img, path.c_str());
	size=Vec2(img.getwidth(),img.getheight());
	return true;
}

void Sprite::draw()
{
	//�ж��Ƿ�ɼ�
	if(!getVisable())
		return;

	putimage(position.getX(),position.getY(),&img);
	Node::draw();
}

void Sprite::update(float delta)
{

}

