#include"random.h"

//a.��ȡ�������������Ϊ���ؾ��巶Χ-[start,end] ��ֵ��Ĭ��Ϊ0�������ⷶΧ��
int getRandomInt(int start,int end)
{
	static bool init=false;
	if(!init)
	{
		// ���������������
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
//b.��ȡ�����(X��ΧΪ[start,end]��Y��ΧΪ[start2,end2])
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