#include"autoreleasepool.h"
#include"../../util/util.h"
#include"poolmanager.h"
/*������ͷ�ļ���������Ϊ���ӣ����׳������⣨��������д��һ�𣬿ɱ���������⣩*/

AutoreleasePool::AutoreleasePool()
: _isClearing(false)
{
    _managedObjectArray.reserve(50);//Ԥ����50��Ԫ�صĴ洢�ռ䡣
    PoolManager::getInstance()->push(this);
}

AutoreleasePool::~AutoreleasePool()
{
    Logn("deallocing AutoreleasePool: %p", this);
     _managedObjectArray.clear();
    PoolManager::getInstance()->pop();
}

//���Ӷ����Զ��ͷų�
void AutoreleasePool::addObject(Ref* object)
{
    _managedObjectArray.push_back(object);
}

//�����Զ��ͷųأ���Ref::relsese��
void AutoreleasePool::clear()
{
    _isClearing = true;
	Ref*T=nullptr;
    for ( vector<Ref*>::iterator it_pos = _managedObjectArray.begin(); it_pos != _managedObjectArray.end(); )
    {
		if ((*it_pos)->getReferenceCount() == 0)
		 {
			 cout<<"ɾ��һ����"<<endl;
			 T=(*it_pos);
			  it_pos=_managedObjectArray.erase(it_pos);
			//delete T;
		 }
		else
			it_pos++;
    }
   
    _isClearing = false;

}

//����Ƿ������ǰ����
bool AutoreleasePool::contains(Ref* object) const
{
    for (const auto& obj : _managedObjectArray)
    {
        if (obj == object)
            return true;
    }
    return false;
}