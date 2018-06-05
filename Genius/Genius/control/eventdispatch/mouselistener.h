#ifndef __MOUSELISTENER_H__
#define __MOUSELISTENER_H__

#include"listener.h"

class MouseListener:public Listener
{
public:
	MouseCallBack callback;
	static MouseListener* create(MouseCallBack m,Node * lis);
	void handleMouseCallBack(MOUSEMSG m);
	void setCallBack(MouseCallBack m)
	{
		callback=m;
	}
};
#endif