#include"eventcustom.h"
//名称不为空,暂时不写断言，用户自行处理
EventCustom::EventCustom(string name)
{
	type=EventType::EventCustomType;
	eventName=name;
}

string EventCustom::getEventName()
{
	return eventName;
}
EventCustom*EventCustom::create(string name)
{
	return new EventCustom(name);
}

