#include"queue.h"
//������Ԫ�غ�������Ԫ�� 
void Queue::push(Ref* ref)
{
	ref->retain();
	mQueue.push(ref);
}
//�����һ��Ԫ��
void  Queue::pop()
{
	mQueue.front()->release();
	mQueue.pop();
}
//�ж��Ƿ�Ϊ��
 bool  Queue::empty()
{
	return mQueue.empty();
}
//��ʾ��һ��Ԫ��          
Ref* Queue::front()
{
	return mQueue.front();
}
//��ʾ���һ��Ԫ��        
Ref*	Queue::back()
{
	return mQueue.back();
}
//���ض��д�С
int Queue::size()
{
	return mQueue.size();
}