#ifndef __QUEUE_H__
#define __QUEUE_H__
#include"../base/base.h"
#include"../control/memory/ref.h"
//ֻ�洢ref����
class  Queue
{
public:
	queue<Ref*> mQueue;
	//������Ԫ�غ�������Ԫ�� 
	void push(Ref* ref);
	//�����һ��Ԫ��
	void  pop();
	//�ж��Ƿ�Ϊ��
	 bool empty();
	//��ʾ��һ��Ԫ��          
	Ref* front() ; 
	//��ʾ���һ��Ԫ��        
	Ref*	back(); 
	//���ض��д�С
	int size();

};


#endif