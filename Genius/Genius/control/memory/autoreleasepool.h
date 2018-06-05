#ifndef __AUTORELEASEPOOL_H__
#define __AUTORELEASEPOOL_H__

#include"ref.h"
#include"../../math/math.h"

class AutoreleasePool
{
public:
	AutoreleasePool();
	~AutoreleasePool();

	//增加对象到自动释放池
	void addObject(Ref *object);

	//清理自动释放池（当Ref::relsese）
	 void clear();

	 //检查是否清理
	bool isClearing() const { return _isClearing; };

	//检查是否包含当前对象
	bool contains(Ref* object) const;

private:
	//管理Ref对象数组
	std::vector<Ref*> _managedObjectArray;
	//清理标志
	bool _isClearing;

};


#endif