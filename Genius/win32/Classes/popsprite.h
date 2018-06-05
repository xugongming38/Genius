#ifndef __POPSRITE_H__
#define __POPSRITE_H__
#include"../../Genius/Genius.h"

class PopSprite:public ColorfulSprite
{
public:
	int i,j;
	int getI(){return i;}
	int getJ(){return j;}
	int num;
	int getNum(){return num;}
	void setNum(int n);
	PopSprite(int num,int i,int j,int  color,Vec2 size,Vec2 pos);
	virtual bool init();

	static PopSprite* createPopSprite(int num,int i,int j,int  color,Vec2 size,Vec2 pos);
};

#endif