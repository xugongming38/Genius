#include"event.h"
#include"../../base/base.h"

class EventCustom:public Event
{
public:
	string eventName;
	EventCustom(string name);
	//获取事件名称，暂时不考虑传复杂数据，即为见到该事件发生就执行相应事件即可
	string getEventName();
	static EventCustom* create(string name);
};