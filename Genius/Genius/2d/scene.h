#ifndef __SCENE_H__
#define __SCENE_H__

#include"node.h"

class Scene:public Node
{

public:
	//���캯��(������ֱ�����ɶ���)
	Scene();
	//��Ӧɾ�����к��ӽڵ㣨δʵ�֣�
	~Scene();
	virtual bool init();
	static Scene*  create();

};

#endif