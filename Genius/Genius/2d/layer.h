#ifndef __LAYER_H__
#define __LAYER_H__

//layer¿‡∂®“Â
#include"node.h"
#include"scene.h"
class Layer :public Node
{
public:
	static Layer* create();
	Layer();
	virtual bool init();
};

#endif