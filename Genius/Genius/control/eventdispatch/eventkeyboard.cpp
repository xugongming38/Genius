#include"eventkeyboard.h"

EventKeyboard::EventKeyboard(int key)
{
	type=EventType::EventKeyboardType;
	this->key=key;
}
int EventKeyboard::getKey()
{
	return key;
}
 EventKeyboard* EventKeyboard::create(int key)
 {
	 return new EventKeyboard(key);
 }