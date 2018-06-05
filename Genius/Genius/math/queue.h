#ifndef __QUEUE_H__
#define __QUEUE_H__
#include"../base/base.h"
#include"../control/memory/ref.h"
//只存储ref对象
class  Queue
{
public:
	queue<Ref*> mQueue;
	//从已有元素后面增加元素 
	void push(Ref* ref);
	//清除第一个元素
	void  pop();
	//判断是否为空
	 bool empty();
	//显示第一个元素          
	Ref* front() ; 
	//显示最后一个元素        
	Ref*	back(); 
	//返回队列大小
	int size();

};


#endif