#ifndef __COLORFULSPRITE_H__
#define __COLORFULSPRITE_H__

#include"node.h"
#include"../render/render.h"
#include"../util/util.h"

class ColorfulSprite:public Node
{
public: 
	//ͼƬ��С
	Vec2 size;
	//ͼƬ
	int color;
	//ͼƬ·��������ʱ����ʵ��.������string
	//LPCTSTR path; 
public:
	//���캯��
	//Sprite(LPCTSTR& path);
	ColorfulSprite::ColorfulSprite(int  color,int height,int width);

	static ColorfulSprite* createColorfulSprite(int  color,int height=0,int width=0);
	//����ͼ��С
	Vec2 getSize(){return size;}
	void setSize(Vec2 &p){size=p;}

	void setColor(int color){this->color=color;}
	int getColor(){return color;}
	//Sprite��ĳ�ʼ������
	virtual bool init();
	virtual void draw();
	virtual void update(float delta);
};

#endif