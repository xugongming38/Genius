#ifndef __ANIMATION_H__
#define __ANIMATION_H__
#include"../../Genius/Genius.h"

class Animation:public Node
{
public:
	//时间有限 人物和敌人不在另起文件
	bool isAI;//标志
	//设置是否为人物
	void setAI(bool isActor){this->isAI=isActor;}
	bool getAI(){return isAI; }

	//留给人物
	bool hasTarget;

	//AI必有目标
	Vec2 target;
	void setTarget(Vec2 target){this->target=target;}
	Vec2 getTarget(){return target;}

	int speed;
	void setSpeed(int speed){this->speed =speed;}
	int getSpeed(){return speed;}

	Animation(int N,IMAGE img[][2] ,float interval=0.12f);
	~Animation();
	static Animation *create(int N,IMAGE  img[][2],float interval=0.12f);
	IMAGE *Imgages1;
	IMAGE *Imgages2;

	//当前播放到哪一帧
	int index;

	int len;
	//动画间隔
	float interval;
	//总的计时器
	float times;
	virtual void update(float delta);
	virtual bool init();
	virtual void draw();

	void AI(float delta);
	void Actor(float delta);
	
};

#endif