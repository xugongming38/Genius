#ifndef __SPRITE_H__
#define __SPRITE_H__

#include"node.h"
#include"../render/render.h"
#include"../util/util.h"

class Sprite:public Node
{
public: 
	//ͼƬ��С
	Vec2 size;
	//ͼƬ
	IMAGE img;
	//ͼƬ·��������ʱ����ʵ��.������string
	//LPCTSTR path; 
	string path;
public:
	//���캯��
	//Sprite(LPCTSTR& path);
	Sprite::Sprite(string path);

	static Sprite* createSprite(string path);
	//����ͼ��С
	Vec2 getSize(){return size;}
	void setSize(Vec2 &p){size=p;}

	//Sprite��ĳ�ʼ������
	virtual bool init();
	virtual void draw();
	virtual void update(float delta);
};

#endif