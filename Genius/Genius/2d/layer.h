#ifndef __LAYER_H__
#define __LAYER_H__

//layer�ඨ��
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