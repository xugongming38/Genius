#include"event.h"
#include"../../render/render.h"

//����������(���������뵱ǰ���ڵĹ�ϵ����˵)
class EventMouse:public Event
{
public:
	//���λ��
	MOUSEMSG m;
	//�����������ϵ�в�����ʱ��д
	EventMouse(MOUSEMSG m);
	MOUSEMSG getMouse();
	Vec2 getPosition(){ return Vec2(m.x,m.y);}
	static EventMouse*  create(MOUSEMSG m);
};