#include"colorfullayout.h"

 ColorfulLayer* ColorfulLayer::create(int color)
 {
	 ColorfulLayer *layer =new ColorfulLayer(color);
	 if(layer->init())
	 {
		//�������ͷų�
		layer->autorelease();
		return layer;
	 }
	 return nullptr;
 }
 ColorfulLayer::ColorfulLayer(int color)
 {
		this->color=color;
 }
 bool ColorfulLayer::init()
 {
	 //��ʼ�����ӽڵ�
	 return true;
 }

void ColorfulLayer::setColor(int color)
{
	this->color=color;
}
int ColorfulLayer::getColor()
{
	return color;
}
void ColorfulLayer::draw()
{
	setfillcolor(color);
	solidrectangle(0,0,Macros::screenSize.getX(),Macros::screenSize.getY());
	//putimage(position.getX(),position.getY(),&img);
	Node::draw();
}

