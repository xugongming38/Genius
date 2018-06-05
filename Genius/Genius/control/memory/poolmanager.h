#ifndef __POOLMANAGER_H__
#define __POOLMANAGER_H__

#include"autoreleasepool.h"


class  PoolManager
{
public:
	//����ģʽ
    static PoolManager* getInstance();
    //���ٵ�ǰ������
    static void destroyInstance();
    
   //��ȡ��ǰ���ͷų�
    AutoreleasePool *getCurrentPool() const;

	//��⵱ǰ�����Ƿ��ڳ���
    bool isObjectInPools(Ref* obj) const;

	//����Ϊ��Ԫ��
    friend class AutoreleasePool;
    
private:
    PoolManager();
    ~PoolManager();
    
	//��ջ
    void push(AutoreleasePool *pool);
	//��ջ
    void pop();
    
    static PoolManager* s_singleInstance;
    //ջ
    std::vector<AutoreleasePool*> _releasePoolStack;
};

#endif