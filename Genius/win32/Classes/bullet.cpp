#include"bullet.h"

Bullet::Bullet(string name,Vec2 target):Sprite(name)
{
	this->target=target;
	times=0;
	speed=60;
	arc=0;
	arcSpeed=10;
}

Bullet* Bullet::create(string name,Vec2 target)
{
	Bullet* bullet =new Bullet(name,target);
	if(bullet&&bullet->init())
	{
		return bullet;
	}
	return nullptr;
}
bool Bullet::init()
{
	if(!Sprite::init())
		return false;

	scheduleUpdate();
	return true;
}
void Bullet::update(float delta)
{
	//times+=delta;
	/*
	arc+=delta*arcSpeed;
	if(arc>6.28)
		arc-=6.28;
	rotateimage(&img, &img, arc);
	*/
	move(delta);

}
void Bullet::move(float delta)
{
	Vec2 pos =getPosition();
	//暂定精确度为25
	if(PointDistance(pos,target)<=100)
	{
		//cout<<"$$$$$$$$$"<<BulletManager:: vBullet.size()<<endl;
		for(auto iter=BulletManager::vBullet.begin();iter!=BulletManager::vBullet.end();)
		{
			//Rect r=Rect((*iter)->getPosition(),v.getX(),v.getY());
			//Rect r(target,100,100);
			Vec2 p((*iter)->getPosition());
			//if(r.containPoint(p))
			if(PointDistance(pos,p)<=400)
			{
				(*iter)->setVisible(false);
				(*iter)->removeFromParent();		
				iter=BulletManager::vBullet.erase(iter);
			}
			else
				++iter;

		}
		//
		//setVisible(false);
		removeFromParent();
	}
	else
	{
		Vec2 purePos=target-pos;
		//cout<<pos.getX()<<"--"<<pos.getY()<<"$$"<<purePos.getX()<<"--"<<purePos.getY()<<endl;
		int dis=(int)(delta*5*speed);
		//cout<<dis<<endl;
		double a=atan2(1.0*purePos.getY(),1.0*purePos.getX());
		cout<<a*57<<endl;
		setPosition(Vec2((int)(pos.getX()+dis*cos(a)),(int)(pos.getY()+dis*sin(a))));
	}
}

vector<Animation*> BulletManager::vBullet;