#ifndef __EVENT_H__
#define __EVENT_H__

#include"../memory/ref.h"
#include"../../math/math.h"

enum EventType
{
	EventCustomType,//自定义事件
	EventMouseType,//鼠标事件
	EventKeyboardType//键盘事件
};
//不限制发生事件类型，即任何对象都可以发送 自定义事件|鼠标事件|键盘事件
//目的是易于实现AI部分
class Event:public Ref
{
public:
	Event();
	EventType type;
	EventType getType();
};

#endif