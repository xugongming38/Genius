#ifndef __RANDOM_H__
#define __RANDOM_H__

#include"vec2.h"
#include"../base/base.h"
//a.获取随机整数
int getRandomInt(int start,int end);
int getRandomInt(int length=0);
//b.获取随机点
Vec2 getRandomPoint(int start,int end,int start2,int end2);
Vec2 getRandomPoint(int X,int Y);
Vec2 getRandomPoint(int XY=0);

#endif