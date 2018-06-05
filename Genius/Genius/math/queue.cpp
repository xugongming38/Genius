#include"queue.h"
//从已有元素后面增加元素 
void Queue::push(Ref* ref)
{
	ref->retain();
	mQueue.push(ref);
}
//清除第一个元素
void  Queue::pop()
{
	mQueue.front()->release();
	mQueue.pop();
}
//判断是否为空
 bool  Queue::empty()
{
	return mQueue.empty();
}
//显示第一个元素          
Ref* Queue::front()
{
	return mQueue.front();
}
//显示最后一个元素        
Ref*	Queue::back()
{
	return mQueue.back();
}
//返回队列大小
int Queue::size()
{
	return mQueue.size();
}