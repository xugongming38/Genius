#ifndef __REF_H__
#define __REF_H__

//�������ͷ��ڴ棬���̳���Ref
class Ref
{
public:
	//���캯��
	Ref();
	//�����������������麯��������ɾ�ˣ�
     ~Ref();
	
	//���� �����+1
	void retain();
	//�ͷ� �����-1
	void release();
	//�������ͷų�
	Ref* autorelease();
	//��ȡ��ǰӦ�ü���
	int getReferenceCount() const;
protected:
		//���ü���
	int referenceCount;
	friend class AutoreleasePool;
 

};


#endif