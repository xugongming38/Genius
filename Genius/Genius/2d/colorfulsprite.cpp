#include"colorfulsprite.h"

//ColorfulSprite���캯��
ColorfulSprite::ColorfulSprite(int  color,int height,int width)
{
	this->color=color;
	size=Vec2(height,width);
}

ColorfulSprite* ColorfulSprite::createColorfulSprite(int  color,int height,int width)
{
	ColorfulSprite *sprite=new ColorfulSprite(color,height,width);
	if(sprite->init())
	{
		//�������ͷų�
		sprite->autorelease();
		return sprite;
	}
	return nullptr;
}


//��ʼ������
bool ColorfulSprite::init()
{
	return true;
}

void ColorfulSprite::draw()
{
	//�ж��Ƿ�ɼ�
	if(!getVisable())
		return;
	Vec2 pos=getPosition();
	setfillcolor(color);
	solidrectangle(pos.getX(),pos.getY(),pos.getX()+size.getX(),pos.getY()+size.getY());
	//putimage(position.getX(),position.getY(),&img);
	Node::draw();
}

void ColorfulSprite::update(float delta)
{

}

