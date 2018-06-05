#ifndef _KEYBOARDLISTENER_H__
#define _KEYBOARDLISTENER_H__

#include"listener.h"

class KeyboardListener:public Listener
{
public:
	KeyboardCallBack callback;
	static KeyboardListener* create(KeyboardCallBack m,Node * lis);
	void handleKeyboardCallBack(int k);
	void setCallBack(KeyboardCallBack m)
	{
		callback=m;
	}
};
#endif