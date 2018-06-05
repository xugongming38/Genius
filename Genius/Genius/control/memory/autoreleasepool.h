#ifndef __AUTORELEASEPOOL_H__
#define __AUTORELEASEPOOL_H__

#include"ref.h"
#include"../../math/math.h"

class AutoreleasePool
{
public:
	AutoreleasePool();
	~AutoreleasePool();

	//���Ӷ����Զ��ͷų�
	void addObject(Ref *object);

	//�����Զ��ͷųأ���Ref::relsese��
	 void clear();

	 //����Ƿ�����
	bool isClearing() const { return _isClearing; };

	//����Ƿ������ǰ����
	bool contains(Ref* object) const;

private:
	//����Ref��������
	std::vector<Ref*> _managedObjectArray;
	//�����־
	bool _isClearing;

};


#endif