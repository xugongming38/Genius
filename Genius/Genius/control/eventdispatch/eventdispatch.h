#ifndef __EVENTDISPATCH_H__
#define __EVENTDISPATCH_H__

#include"../../math/math.h"
#include"event.h"
#include"eventcustom.h"
#include"eventkeyboard.h"
#include"eventmouse.h"

#include"../../2d/node.h"

#include"customlistener.h"
#include"keyboardlistener.h"
#include"mouselistener.h"

//�¼��ַ�������
//������ղ������¼����Լ�ÿ֡ѭ���¼������Լ����������������¼�
//�����������������¼��Ĳ��������director��������ʱ����
class EventDispatch
{
public:
	//��������������
	EventDispatch();
	~EventDispatch();
	//����ģʽ
	static EventDispatch* getInstance();
	static EventDispatch* Instance;
	//ÿ֡���õ�ʱ��ַ�����
	void dispatchEvent();
	//���¼������ߵ��ã������¼�,����event������event������
	bool sendEvent(Event* event);

	//����Ϊ�����¼�����
	//�Զ����¼�
	Queue queueCustom;
	//����¼���Ԥ������¼������������ޡ�����
	Queue queueMouse;
	//�����¼�
	Queue queueKeyboard;

	//����Ϊ�����¼�������
	//�Զ����¼�������
	Array<CustomListener*> CustomListeners;
	//�����¼�������
	Array<KeyboardListener*> KeyboardListeners;
	//����¼�������
	Array<MouseListener*> MouseListeners;
	void MouseListeners_Clear();

	//�������ͼ��������
	bool  addListener(Listener* ls);

	//����Ϊ�����¼���Ӧ����
	//�����Զ����¼�
	void HandleCustom();
	//��������¼�
	void HandleMouse();
	//��������¼�
	void handleKeyboard();

};


#endif