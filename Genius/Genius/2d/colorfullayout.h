#ifndef __COLORFULLAYER_H__
#define __COLORFULLAYER_H__

//layer¿‡∂®“Â
#include"node.h"
#include"scene.h"
class ColorfulLayer :public Node
{
public:
	int color;
	static ColorfulLayer* create(int color);
	ColorfulLayer(int color);
	virtual bool init();
	void setColor(int color);
	int getColor();
	virtual void draw();
};

#endif