#include"eventdispatch.h"
//��װʵ�ֹ�������������
EventDispatch::EventDispatch()
{
}
EventDispatch::~EventDispatch()
{
}

//����ģʽ
EventDispatch* EventDispatchInstance=nullptr;
EventDispatch* EventDispatch::getInstance()
{
	if(EventDispatchInstance==nullptr)
	{
		EventDispatchInstance=new EventDispatch();
	}
	return EventDispatchInstance;
}
//ÿ֡���õ�ʱ��ַ�����
void EventDispatch::dispatchEvent()
{
	//�����Զ����¼�
	HandleCustom();
	//��������¼�
	HandleMouse();
	//��������¼�
	handleKeyboard();
}
//���¼������ߵ��ã������¼�,����event������event������
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


//����Ϊ�����¼���Ӧ����
//�����Զ����¼�
void EventDispatch::HandleCustom()
{
	while(!queueCustom.empty())
	{
		EventCustom *event=(EventCustom *)queueCustom.front();
		//����ע�����ô������⣬�������û������м����������ﲻ��ʵ��
		for (auto iter = 0; iter != CustomListeners.size(); ++iter)
			if(CustomListeners.at(iter)->isHandle(event->getEventName()))
				CustomListeners.at(iter)->handleCustomCallBack();
		queueCustom.pop();
	}
}
//��������¼�
void EventDispatch::HandleMouse()
{
	while(!queueMouse.empty())
	{
		EventMouse *event=(EventMouse *)queueMouse.front();
		//cout<<MouseListeners.size()<<"$$"<<endl;
		//����ע�����ô������⣬�������û������м����������ﲻ��ʵ��

		//�˴��ڴ�������¼�������һ�ε�����Ӽ����ߣ����µ������𻵣�ע�����⣻
		//��д���ݽṹ ����ʹ��vector
		for (int iter = 0; iter < MouseListeners.size();++ iter)
		{
			MouseListeners.at(iter)->handleMouseCallBack(event->getMouse());
		}
		queueMouse.pop();
	}
}
//��������¼�
void EventDispatch::handleKeyboard()
{
	while(!queueKeyboard.empty())
	{
		EventKeyboard *event=(EventKeyboard *)queueKeyboard.front();
		//����ע�����ô������⣬�������û������м����������ﲻ��ʵ��
		for (auto iter = 0; iter< KeyboardListeners.size(); iter++)
			KeyboardListeners.at(iter)->handleKeyboardCallBack(event->getKey());
		queueKeyboard.pop();
	}
}

void EventDispatch::MouseListeners_Clear()
{
	MouseListeners.clear();
}