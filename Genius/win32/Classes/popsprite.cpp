#include"popsprite.h"
PopSprite::PopSprite(int num,int i,int j,int  color,Vec2 size,Vec2 pos):ColorfulSprite(color,size.getY(),size.getX())
{
	setPosition(pos);
	this->i=i;
	this->j=j;
	this->num=num;
}
bool PopSprite::init()
{
	return true;
}

PopSprite* PopSprite::createPopSprite(int num,int i,int j ,int  color,Vec2 size,Vec2 pos)
{
	PopSprite* pop =new PopSprite(num,i,j, color, size, pos);
	if(pop->init())
		return pop;
	else
		return nullptr;
}

void PopSprite::setNum(int n)
{
	this->num=n;  
	switch(n)
	{
	case -1:
		setColor(RGB(200,190,180));
		break;
	case 0:
		setColor(RGB(250,230,40));
		break;
	case 1:
		setColor(RGB(40,180,250));
		break;
	case 2:
		setColor(RGB(130,220,110));
		break;
	case 3:
		setColor(RGB(250,80,130));
		break;
	case 4:
		setColor(RGB(100,50,250));
		break;
	}
}