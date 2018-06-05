#include"eventmouse.h"


EventMouse::EventMouse(MOUSEMSG m)
{
	type=EventType::EventMouseType;
	this->m =m;
}

MOUSEMSG EventMouse::getMouse()
{
	return m;
}

EventMouse*  EventMouse::create(MOUSEMSG m)
{
	return new EventMouse(m);
}
