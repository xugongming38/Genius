#include"ref.h"
#include"../../util/util.h"
#include"poolmanager.h"

void Ref::retain()
{
    ASSERT(referenceCount >=0, "reference count should greater than 0 when retain");
    ++referenceCount;
}

void Ref::release()
{
    ASSERT(referenceCount >= 0, "reference count should greater than 0 when release");
    --referenceCount;
	if(referenceCount<0)
		referenceCount=0;
	
}

Ref* Ref::autorelease()
{
    PoolManager::getInstance()->getCurrentPool()->addObject(this);
    return this;
}

int Ref::getReferenceCount() const
{
    return referenceCount;
}

Ref::Ref()
{
	//����Ϊ0,����eventΪһ���Ե�
	referenceCount=0;
}

Ref::~Ref()
{
	//�����������Ĺ������Ȳ�д
}