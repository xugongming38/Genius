#ifndef __SPRITE_H__
#define __SPRITE_H__

#include"node.h"
#include"../render/render.h"
#include"../util/util.h"

class Sprite:public Node
{
public: 
	//图片大小
	Vec2 size;
	//图片
	IMAGE img;
	//图片路径。。暂时这样实现.不能用string
	//LPCTSTR path; 
	string path;
public:
	//构造函数
	//Sprite(LPCTSTR& path);
	Sprite::Sprite(string path);

	static Sprite* createSprite(string path);
	//设置图大小
	Vec2 getSize(){return size;}
	void setSize(Vec2 &p){size=p;}

	//Sprite类的初始化函数
	virtual bool init();
	virtual void draw();
	virtual void update(float delta);
};

#endif