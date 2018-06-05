#include"eventdispatch.h"
//假装实现构造与析构函数
EventDispatch::EventDispatch()
{
}
EventDispatch::~EventDispatch()
{
}

//单例模式
EventDispatch* EventDispatchInstance=nullptr;
EventDispatch* EventDispatch::getInstance()
{
	if(EventDispatchInstance==nullptr)
	{
		EventDispatchInstance=new EventDispatch();
	}
	return EventDispatchInstance;
}
//每帧调用的时间分发操作
void EventDispatch::dispatchEvent()
{
	//处理自定义事件
	HandleCustom();
	//处理鼠标事件
	HandleMouse();
	//处理键盘事件
	handleKeyboard();
}
//由事件产生者调用，创建事件,其中event必须有event的类型
bool EventDispatch::sendEvent(Event* event)
{
	switch (event->getType())
	{
	case EventType::EventCustomType:
		queueCustom.push(event);
				break;
	case EventType::EventKeyboardType:
		queueKeyboard.push(event);
				break;
	case EventType::EventMouseType:
		queueMouse.push(event);
				break;
	default:
		return false;
		break;
	}
	return true;
}

bool EventDispatch::addListener(Listener* ls)
{
	switch (ls->getType())
	{
	case ListenerType::CustomListenerType:
		CustomListeners.push_back((CustomListener*)ls);
		break;

	case ListenerType::KeyboardListenerType:
		KeyboardListeners.push_back((KeyboardListener*)ls);
		break;
	case ListenerType::MouseListenerType:
		MouseListeners.push_back((MouseListener*)ls);
		break;

	default:
		return false;
		break;
	}
	return true;
}


//以下为三种事件相应处理
//处理自定义事件
void EventDispatch::HandleCustom()
{
	while(!queueCustom.empty())
	{
		EventCustom *event=(EventCustom *)queueCustom.front();
		//关于注册后调用次数问题，可以在用户代码中计数处理，这里不在实现
		for (auto iter = 0; iter != CustomListeners.size(); ++iter)
			if(CustomListeners.at(iter)->isHandle(event->getEventName()))
				CustomListeners.at(iter)->handleCustomCallBack();
		queueCustom.pop();
	}
}
//处理鼠标事件
void EventDispatch::HandleMouse()
{
	while(!queueMouse.empty())
	{
		EventMouse *event=(EventMouse *)queueMouse.front();
		//cout<<MouseListeners.size()<<"$$"<<endl;
		//关于注册后调用次数问题，可以在用户代码中计数处理，这里不在实现

		//此处在处理鼠标事件中又又一次调用添加监听者，导致迭代器损坏，注意问题；
		//重写数据结构 不再使用vector
		for (int iter = 0; iter < MouseListeners.size();++ iter)
		{
			MouseListeners.at(iter)->handleMouseCallBack(event->getMouse());
		}
		queueMouse.pop();
	}
}
//处理键盘事件
void EventDispatch::handleKeyboard()
{
	while(!queueKeyboard.empty())
	{
		EventKeyboard *event=(EventKeyboard *)queueKeyboard.front();
		//关于注册后调用次数问题，可以在用户代码中计数处理，这里不在实现
		for (auto iter = 0; iter< KeyboardListeners.size(); iter++)
			KeyboardListeners.at(iter)->handleKeyboardCallBack(event->getKey());
		queueKeyboard.pop();
	}
}

void EventDispatch::MouseListeners_Clear()
{
	MouseListeners.clear();
}