#include"event.h"
#include"../../base/base.h"

class EventCustom:public Event
{
public:
	string eventName;
	EventCustom(string name);
	//��ȡ�¼����ƣ���ʱ�����Ǵ��������ݣ���Ϊ�������¼�������ִ����Ӧ�¼�����
	string getEventName();
	static EventCustom* create(string name);
};