#ifndef __RANDOM_H__
#define __RANDOM_H__

#include"vec2.h"
#include"../base/base.h"
//a.��ȡ�������
int getRandomInt(int start,int end);
int getRandomInt(int length=0);
//b.��ȡ�����
Vec2 getRandomPoint(int start,int end,int start2,int end2);
Vec2 getRandomPoint(int X,int Y);
Vec2 getRandomPoint(int XY=0);

#endif