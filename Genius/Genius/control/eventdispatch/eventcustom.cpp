#include"eventcustom.h"
//���Ʋ�Ϊ��,��ʱ��д���ԣ��û����д���
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

