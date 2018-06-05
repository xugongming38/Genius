#ifndef __BULLET_H__
#define __BULLET_H__

#include"../../Genius/Genius.h"
#include"animation.h"
class Bullet:public Sprite
{
public:
	Vec2 target;
	float times;
	int speed;
	float arc;
	int arcSpeed;
	Bullet(string name,Vec2 target);
	static Bullet* create(string name,Vec2 target);
	virtual bool init();
	virtual void update(float delta);
	void move(float delta);
};


class BulletManager
{
public:
	static vector<Animation*> vBullet;
};

#endif