#ifndef __LISTENER_H__
#define __LISTENER_H__

#include"../../2d/node.h"

typedef void (Node::*CustomCallBack)(void);
typedef void (Node::*MouseCallBack)(MOUSEMSG);
typedef void (Node::*KeyboardCallBack)(int);//键盘估计为整数

enum ListenerType
{
	CustomListenerType,
	MouseListenerType,
	KeyboardListenerType
};

class Listener
{
public:
	ListenerType type;
	//暂且以node节点为基类
	Node* listener;
	void  setListener(Node* listener)
	{
		this->listener=listener;
	}
	ListenerType getType()
	{
		return type;
	}
};

#endif