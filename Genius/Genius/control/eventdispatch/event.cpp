#include"event.h"

Event::Event()
{
	this->autorelease();
}
EventType Event::getType()
{
	return type;
}
