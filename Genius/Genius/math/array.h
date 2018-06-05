#ifndef __ARRAY_H__
#define __ARRAY_H__

#include"../base/base.h"
#define max_v 50
template<class T>
class Array
{
	//封装后可能不好用
public:
	Array(){ len=0; }
	T  v[max_v];
	//不做考虑，暂时够用
	int len;
	void push_back(T t);
	T at(int i);
	//获取大小
	int size();
	//清空
	void clear();
};

template<class T>
void Array<T>::push_back(T t)
{
	v[len++]=t;
}

//返回下标处（0    -   len-1）
template<class T>
T Array<T>::at(int i)//安全性未多考虑
{
	if(i<len)
		return v[i];
	return 0;
}
//获取大小
template<class T>
int Array<T>::size()
{
	return len;
}
//清空
template<class T>
void Array<T>::clear()
{
	for(int i=0;i<len;i++)
		delete v[i];
	//只用作存储指针
	len=0;
}
#endif