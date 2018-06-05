#ifndef __ARRAY_H__
#define __ARRAY_H__

#include"../base/base.h"
#define max_v 50
template<class T>
class Array
{
	//��װ����ܲ�����
public:
	Array(){ len=0; }
	T  v[max_v];
	//�������ǣ���ʱ����
	int len;
	void push_back(T t);
	T at(int i);
	//��ȡ��С
	int size();
	//���
	void clear();
};

template<class T>
void Array<T>::push_back(T t)
{
	v[len++]=t;
}

//�����±괦��0    -   len-1��
template<class T>
T Array<T>::at(int i)//��ȫ��δ�࿼��
{
	if(i<len)
		return v[i];
	return 0;
}
//��ȡ��С
template<class T>
int Array<T>::size()
{
	return len;
}
//���
template<class T>
void Array<T>::clear()
{
	for(int i=0;i<len;i++)
		delete v[i];
	//ֻ�����洢ָ��
	len=0;
}
#endif