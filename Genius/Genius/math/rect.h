#ifndef __RECT_H__
#define __RECT_H__

#include"vec2.h"

class Rect
{
public:
	Rect(Vec2 point,int w,int h);
	Vec2 point;
	int width;//x
	int height;//y
	//�����Ƿ������
	bool containPoint(Vec2 p);
};
#endif