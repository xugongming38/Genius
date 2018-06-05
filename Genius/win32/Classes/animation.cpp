#include"animation.h"

Animation::Animation(int N,IMAGE img[][2] ,float interval)
{
	len=N;
	Imgages1= new IMAGE[len];
	Imgages2= new IMAGE[len];
	for(int i=0;i<len;i++)
	{
		Imgages1[i]=img[i][0];
		Imgages2[i]=img[i][1];
	}
	times=0;
	index=getRandomInt(len);
	this->interval=interval;//暂时使用这个值

	isAI=true;
	hasTarget=false;
	target=getRandomPoint(40,1000,40,800);
	//target=Vec2(640,480);
	//cout<<target.getX()<<" %%%%"<<target.getY()<<endl;
	speed=50;
}
Animation::~Animation()
{
	delete Imgages1;
	delete Imgages2;
}
Animation *Animation::create(int N,IMAGE img[][2] ,float interval)
{
	Animation *animation= new Animation(N,img,interval);
	if(animation&&animation->init())
	{
		return animation;
	}
	return nullptr;
}

bool Animation::init()
{
	if(!Node::init())
		return false;

	//开启每帧监听
	scheduleUpdate();

	return true;
}

void Animation::update(float delta)
{
	times+=delta;
	if(times>=interval)
	{
			index=(index+1)%len;
			times-=interval;
	}

	if(isAI)
		AI(delta);
	else
	{
		Actor(delta);
	}
}

void Animation::draw()
{
	Vec2 pos =getPosition();
	putimage(pos.getX(),pos.getY(),&Imgages1[index],SRCAND);
    putimage(pos.getX(),pos.getY(),&Imgages2[index],SRCPAINT);
	Node::draw();
}

void Animation::AI(float delta)
{
	//cout<<"AI"<<endl;
	Vec2 pos =getPosition();
	//暂定精确度为25、
	//cout<<PointDistance(pos,target)<<endl;
	if(PointDistance(pos,target)<=100)
	{
		speed=getRandomInt(50)+50;
		target=getRandomPoint(40,1000,40,800);
	}
	else
	{
		Vec2 purePos=target-pos;
		int dis=(int)(delta*2*speed);
		double a=atan2(1.0*purePos.getY(),1.0*purePos.getX());
		setPosition(Vec2((int)(pos.getX()+dis*cos(a)),(int)(pos.getY()+dis*sin(a))));
	}
	/*
		Vec2 dis=getRandomPoint(-3,3,-3,3);
		Vec2 newPos=pos+dis;
		if(newPos.getX()>1280||newPos.getX()<0||newPos.getY()>960||newPos.getY()<0)
			newPos=getRandomPoint(0,800,0,800);
		
		setPosition(newPos);
		*/
}

void Animation::Actor(float delta)
{
	if(!hasTarget)
		return;

	

	Vec2 pos =getPosition();
	//暂定精确度为25
	//cout<<PointDistance(pos,target)<<endl;
	if(PointDistance(pos,target)<=100)
	{
		//cout<<"AI"<<endl;
		hasTarget=false;
	}
	else
	{
		Vec2 purePos=target-pos;
		//cout<<pos.getX()<<"--"<<pos.getY()<<"$$"<<purePos.getX()<<"--"<<purePos.getY()<<endl;
		int dis=(int)(delta*5*speed);
		//cout<<dis<<endl;
		double a=atan2(1.0*purePos.getY(),1.0*purePos.getX());
		//cout<<a*57<<endl;
		setPosition(Vec2((int)(pos.getX()+dis*cos(a)),(int)(pos.getY()+dis*sin(a))));
	}
}