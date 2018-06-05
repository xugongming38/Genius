#ifndef __ANIMATION_H__
#define __ANIMATION_H__
#include"../../Genius/Genius.h"

class Animation:public Node
{
public:
	//ʱ������ ����͵��˲��������ļ�
	bool isAI;//��־
	//�����Ƿ�Ϊ����
	void setAI(bool isActor){this->isAI=isActor;}
	bool getAI(){return isAI; }

	//��������
	bool hasTarget;

	//AI����Ŀ��
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

	//��ǰ���ŵ���һ֡
	int index;

	int len;
	//�������
	float interval;
	//�ܵļ�ʱ��
	float times;
	virtual void update(float delta);
	virtual bool init();
	virtual void draw();

	void AI(float delta);
	void Actor(float delta);
	
};

#endif