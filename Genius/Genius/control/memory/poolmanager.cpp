#include"poolmanager.h"
#include"../../util/util.h"

PoolManager* PoolManager::s_singleInstance = nullptr;

//获取单例池管理器
PoolManager* PoolManager::getInstance()
{
    if (s_singleInstance == nullptr)
    {
        s_singleInstance = new (std::nothrow) PoolManager();
        // 加入第一个自释放池
        new AutoreleasePool();
    }
    return s_singleInstance;
}


//销毁单例池管理器
void PoolManager::destroyInstance()
{
    delete s_singleInstance;
    s_singleInstance = nullptr;
}

//池管理器构造函数
PoolManager::PoolManager()
{
    _releasePoolStack.reserve(10);//预申请10个空间
}

//池管理器析构函数
PoolManager::~PoolManager()
{
    Logn("deallocing PoolManager: %p", this);
    
    while (!_releasePoolStack.empty())
    {
        AutoreleasePool* pool = _releasePoolStack.back();
        
        delete pool;
    }
}


AutoreleasePool* PoolManager::getCurrentPool() const
{
    return _releasePoolStack.back();
}

bool PoolManager::isObjectInPools(Ref* obj) const
{
    for (const auto& pool : _releasePoolStack)
    {
        if (pool->contains(obj))
            return true;
    }
    return false;
}

void PoolManager::push(AutoreleasePool *pool)
{
    _releasePoolStack.push_back(pool);
}

void PoolManager::pop()
{
    ASSERT(!_releasePoolStack.empty(),"自释放线程池栈不为空！");
    _releasePoolStack.pop_back();
}