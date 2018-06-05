#ifndef __CUSTOMLISTENER_H
#define __CUSTOMLISTENER_H

#include"listener.h"

class CustomListener:public Listener
{
public:
	string listening_name;
	CustomCallBack callback;
	static CustomListener* create(CustomCallBack m,Node * lis,string name);
	void handleCustomCallBack();
	void setCallBack(CustomCallBack m)
	{
		callback=m;
	}
	//ѯ���Ƿ�����Ҫ�Ƚ�name�Ƿ���ͬ
	bool isHandle(string name);
};
#endif