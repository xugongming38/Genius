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

//ѯ���Ƿ�����Ҫ�Ƚ�name�Ƿ���ͬ
bool CustomListener::isHandle(string name)
{
	return listening_name==name;
}