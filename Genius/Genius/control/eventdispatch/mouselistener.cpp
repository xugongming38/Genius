#include"mouselistener.h"

MouseListener* MouseListener::create(MouseCallBack m,Node * lis)
{
	MouseListener* mouse= new MouseListener();
	mouse->type=ListenerType::MouseListenerType;
	mouse->setCallBack(m);
	mouse->setListener(lis);
	return mouse;
}
void MouseListener::handleMouseCallBack(MOUSEMSG m)
{
	(listener->*callback)(m);
}