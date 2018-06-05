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
	//初试为0,比如event为一次性的
	referenceCount=0;
}

Ref::~Ref()
{
	//析构子类做的工作，先不写
}