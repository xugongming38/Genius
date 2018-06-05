#include"keyboardlistener.h"

KeyboardListener* KeyboardListener::create(KeyboardCallBack m,Node * lis)
{
	KeyboardListener* mouse= new KeyboardListener();
	mouse->type=ListenerType::KeyboardListenerType;
	mouse->setCallBack(m);
	mouse->setListener(lis);
	return mouse;
}
void KeyboardListener::handleKeyboardCallBack(int k)
{
	(listener->*callback)(k);
}