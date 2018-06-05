#include"event.h"

//关于键盘那信息的存储，暂时不写，用到再说
class EventKeyboard:public Event
{
public:
	//点击键位信息
	int key;
	//暂时未传递参数
	EventKeyboard(int key);
	int getKey();
	static EventKeyboard* create(int key);
};