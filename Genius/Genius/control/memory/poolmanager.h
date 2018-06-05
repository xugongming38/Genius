#ifndef __POOLMANAGER_H__
#define __POOLMANAGER_H__

#include"autoreleasepool.h"


class  PoolManager
{
public:
	//单例模式
    static PoolManager* getInstance();
    //销毁当前管理器
    static void destroyInstance();
    
   //获取当前自释放池
    AutoreleasePool *getCurrentPool() const;

	//检测当前对象是否在池中
    bool isObjectInPools(Ref* obj) const;

	//声明为友元类
    friend class AutoreleasePool;
    
private:
    PoolManager();
    ~PoolManager();
    
	//入栈
    void push(AutoreleasePool *pool);
	//出栈
    void pop();
    
    static PoolManager* s_singleInstance;
    //栈
    std::vector<AutoreleasePool*> _releasePoolStack;
};

#endif