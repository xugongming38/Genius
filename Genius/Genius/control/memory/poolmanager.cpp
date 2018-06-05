#include"poolmanager.h"
#include"../../util/util.h"

PoolManager* PoolManager::s_singleInstance = nullptr;

//��ȡ�����ع�����
PoolManager* PoolManager::getInstance()
{
    if (s_singleInstance == nullptr)
    {
        s_singleInstance = new (std::nothrow) PoolManager();
        // �����һ�����ͷų�
        new AutoreleasePool();
    }
    return s_singleInstance;
}


//���ٵ����ع�����
void PoolManager::destroyInstance()
{
    delete s_singleInstance;
    s_singleInstance = nullptr;
}

//�ع��������캯��
PoolManager::PoolManager()
{
    _releasePoolStack.reserve(10);//Ԥ����10���ռ�
}

//�ع�������������
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
    ASSERT(!_releasePoolStack.empty(),"���ͷ��̳߳�ջ��Ϊ�գ�");
    _releasePoolStack.pop_back();
}