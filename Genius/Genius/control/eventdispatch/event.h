#ifndef __EVENT_H__
#define __EVENT_H__

#include"../memory/ref.h"
#include"../../math/math.h"

enum EventType
{
	EventCustomType,//�Զ����¼�
	EventMouseType,//����¼�
	EventKeyboardType//�����¼�
};
//�����Ʒ����¼����ͣ����κζ��󶼿��Է��� �Զ����¼�|����¼�|�����¼�
//Ŀ��������ʵ��AI����
class Event:public Ref
{
public:
	Event();
	EventType type;
	EventType getType();
};

#endif