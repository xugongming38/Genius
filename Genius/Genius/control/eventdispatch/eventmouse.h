#include"event.h"
#include"../../render/render.h"

//关于鼠标对象(对于坐标与当前窗口的关系，再说)
class EventMouse:public Event
{
public:
	//点击位置
	MOUSEMSG m;
	//关于鼠标对象的系列参数暂时不写
	EventMouse(MOUSEMSG m);
	MOUSEMSG getMouse();
	Vec2 getPosition(){ return Vec2(m.x,m.y);}
	static EventMouse*  create(MOUSEMSG m);
};