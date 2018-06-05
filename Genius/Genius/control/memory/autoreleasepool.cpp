#include"autoreleasepool.h"
#include"../../util/util.h"
#include"poolmanager.h"
/*这三个头文件的依赖较为复杂，容易出现问题（若三个类写在一起，可避免这个问题）*/

AutoreleasePool::AutoreleasePool()
: _isClearing(false)
{
    _managedObjectArray.reserve(50);//预分配50个元素的存储空间。
    PoolManager::getInstance()->push(this);
}

AutoreleasePool::~AutoreleasePool()
{
    Logn("deallocing AutoreleasePool: %p", this);
     _managedObjectArray.clear();
    PoolManager::getInstance()->pop();
}

//增加对象到自动释放池
void AutoreleasePool::addObject(Ref* object)
{
    _managedObjectArray.push_back(object);
}

//清理自动释放池（当Ref::relsese）
void AutoreleasePool::clear()
{
    _isClearing = true;
	Ref*T=nullptr;
    for ( vector<Ref*>::iterator it_pos = _managedObjectArray.begin(); it_pos != _managedObjectArray.end(); )
    {
		if ((*it_pos)->getReferenceCount() == 0)
		 {
			 cout<<"删除一对象"<<endl;
			 T=(*it_pos);
			  it_pos=_managedObjectArray.erase(it_pos);
			//delete T;
		 }
		else
			it_pos++;
    }
   
    _isClearing = false;

}

//检查是否包含当前对象
bool AutoreleasePool::contains(Ref* object) const
{
    for (const auto& obj : _managedObjectArray)
    {
        if (obj == object)
            return true;
    }
    return false;
}