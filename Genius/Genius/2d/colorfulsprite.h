#ifndef __COLORFULSPRITE_H__
#define __COLORFULSPRITE_H__

#include"node.h"
#include"../render/render.h"
#include"../util/util.h"

class ColorfulSprite:public Node
{
public: 
	//图片大小
	Vec2 size;
	//图片
	int color;
	//图片路径。。暂时这样实现.不能用string
	//LPCTSTR path; 
public:
	//构造函数
	//Sprite(LPCTSTR& path);
	ColorfulSprite::ColorfulSprite(int  color,int height,int width);

	static ColorfulSprite* createColorfulSprite(int  color,int height=0,int width=0);
	//设置图大小
	Vec2 getSize(){return size;}
	void setSize(Vec2 &p){size=p;}

	void setColor(int color){this->color=color;}
	int getColor(){return color;}
	//Sprite类的初始化函数
	virtual bool init();
	virtual void draw();
	virtual void update(float delta);
};

#endif