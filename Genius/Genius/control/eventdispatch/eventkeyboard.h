#include"event.h"

//���ڼ�������Ϣ�Ĵ洢����ʱ��д���õ���˵
class EventKeyboard:public Event
{
public:
	//�����λ��Ϣ
	int key;
	//��ʱδ���ݲ���
	EventKeyboard(int key);
	int getKey();
	static EventKeyboard* create(int key);
};