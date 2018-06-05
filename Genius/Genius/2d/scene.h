#ifndef __SCENE_H__
#define __SCENE_H__

#include"node.h"

class Scene:public Node
{

public:
	//构造函数(不允许直接生成对象)
	Scene();
	//理应删除所有孩子节点（未实现）
	~Scene();
	virtual bool init();
	static Scene*  create();

};

#endif