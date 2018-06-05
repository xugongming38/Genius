#ifndef __NODE_H__
#define __NODE_H__

#include"../math/math.h"
#include"../control/memory/poolmanager.h"
#include"../util/util.h"
//�����¼���������scheduler��������������update�Ժ�д
class Node:public Ref
{
public:
	//�ڵ�����
	Node();//���캯��
	int id;//���ڱ�ʶÿ���ڵ�
	int prior;//ȷ����Ⱦ���ȼ����൱��Z�������Ĭ��Ϊ0��
	Vec2 position;//λ��
	bool visible;//�Ƿ�ɼ�
	bool scheduled;//�Ƿ������µ���

	//���ӹ���
	int childsize;//������Ŀ
	Node *head;//���ӽڵ�ͷ���
	Node *right;//��һ���ֵܽڵ�
	Node *down;//��һ�����ȼ��ĺ��ӽڵ����

	//���ڵ�
	Node *father;


public:
	//�����ڵ㺯������̬��
	static Node* create(Vec2&p);
	//��������
	virtual bool init();//��ʼ��ʱ����
	virtual void draw();//ÿ֡����ʱ����
	
	//����ID
	bool setID(int id);
	int getID();

	//����prior
	bool setPrior(int prior);
	int getPrior();

	//����λ��
	void setPosition(Vec2 &p){position=p;}
	Vec2& getPosition(){return position;}//ע�ⷵ�ص�������

	//���ӹ���
	bool addChild(Node *child,int prior=0);
	//ɾ�����ӽڵ�
	bool deleteChild(Node *child);
	//��һ�����ڸ��ڵ㣬��һ���ɹ�
	bool removeFromParent();

	//ȥ�� ������ͷ�ļ�ѭ��
	//EventDispatch *getEventDispatch();


	//�Ƿ�ɼ�
	void setVisible(bool visible);
	bool getVisable();

	void listChild();//���Ժ������оٺ�������

	//���º�������Ϊ����UI������£�
	bool isScheduled();
	void scheduleUpdate(void);
	void unscheduleUpdate(void);
	virtual void update(float delta);
};





#endif