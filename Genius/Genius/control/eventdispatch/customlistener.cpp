#include"customlistener.h"

CustomListener* CustomListener::create(CustomCallBack m,Node * lis,string name)
{
	CustomListener* mouse= new CustomListener();
	mouse->type=ListenerType::CustomListenerType;
	mouse->setCallBack(m);
	mouse->setListener(lis);
	mouse->listening_name=name;
	return mouse;
}
void CustomListener::handleCustomCallBack()
{
	(listener->*callback)();
}

//询问是否处理，主要比较name是否相同
bool CustomListener::isHandle(string name)
{
	return listening_name==name;
}