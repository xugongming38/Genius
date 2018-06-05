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

//事件分发管理器
//负责接收产生的事件，以及每帧循环事件队列以及监听队列来处理事件
//关于例如键盘鼠标点击事件的产生大概有director产生，暂时不管
class EventDispatch
{
public:
	//构造与析构函数
	EventDispatch();
	~EventDispatch();
	//单例模式
	static EventDispatch* getInstance();
	static EventDispatch* Instance;
	//每帧调用的时间分发操作
	void dispatchEvent();
	//由事件产生者调用，创建事件,其中event必须有event的类型
	bool sendEvent(Event* event);

	//以下为三种事件队列
	//自定义事件
	Queue queueCustom;
	//鼠标事件（预测鼠标事件队列内容有限。。）
	Queue queueMouse;
	//键盘事件
	Queue queueKeyboard;

	//以下为三种事件监听者
	//自定义事件监听者
	Array<CustomListener*> CustomListeners;
	//键盘事件监听者
	Array<KeyboardListener*> KeyboardListeners;
	//鼠标事件监听者
	Array<MouseListener*> MouseListeners;
	void MouseListeners_Clear();

	//根据类型加入监听者
	bool  addListener(Listener* ls);

	//以下为三种事件相应处理
	//处理自定义事件
	void HandleCustom();
	//处理鼠标事件
	void HandleMouse();
	//处理键盘事件
	void handleKeyboard();

};


#endif