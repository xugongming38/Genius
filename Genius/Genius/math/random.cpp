#include"random.h"

//a.获取随机整数（参数为返回具体范围-[start,end] 的值，默认为0，即任意范围）
int getRandomInt(int start,int end)
{
	static bool init=false;
	if(!init)
	{
		// 设置随机函数种子
		srand((unsigned) time(NULL));
		init=!init;
	}
			
	int t=rand();
	if(start||end)
		t=t%(end-start+1)+start;
	return t;
}
int getRandomInt(int length)
{
	return getRandomInt(0,length);
}
//b.获取随机点(X范围为[start,end]，Y范围为[start2,end2])
Vec2 getRandomPoint(int start,int end,int start2,int end2)
{
	return Vec2(getRandomInt(start,end),getRandomInt(start2,end2));
}
Vec2 getRandomPoint(int X,int Y)
{
	return getRandomPoint(0,X,0,Y);
}
Vec2 getRandomPoint(int XY)
{
	return getRandomPoint(0,XY,0,XY);
}