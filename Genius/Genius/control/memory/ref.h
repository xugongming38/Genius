#ifndef __REF_H__
#define __REF_H__

//所以自释放内存，均继承自Ref
class Ref
{
public:
	//构造函数
	Ref();
	//析构函数（本来是虚函数，被我删了）
     ~Ref();
	
	//持有 则计数+1
	void retain();
	//释放 则计数-1
	void release();
	//加入自释放池
	Ref* autorelease();
	//获取当前应用计数
	int getReferenceCount() const;
protected:
		//引用计数
	int referenceCount;
	friend class AutoreleasePool;
 

};


#endif