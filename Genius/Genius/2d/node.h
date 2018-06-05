#ifndef __NODE_H__
#define __NODE_H__

#include"../math/math.h"
#include"../control/memory/poolmanager.h"
#include"../util/util.h"
//关于事件管理器，scheduler，动作管理器，update稍后写
class Node:public Ref
{
public:
	//节点自身
	Node();//构造函数
	int id;//用于标识每个节点
	int prior;//确定渲染优先级（相当于Z坐标管理，默认为0）
	Vec2 position;//位置
	bool visible;//是否可见
	bool scheduled;//是否参与更新调度

	//孩子管理
	int childsize;//孩子数目
	Node *head;//孩子节点头结点
	Node *right;//下一个兄弟节点
	Node *down;//下一个优先级的孩子节点队列

	//父节点
	Node *father;


public:
	//创建节点函数（静态）
	static Node* create(Vec2&p);
	//生命周期
	virtual bool init();//初始化时调用
	virtual void draw();//每帧绘制时调用
	
	//操作ID
	bool setID(int id);
	int getID();

	//操作prior
	bool setPrior(int prior);
	int getPrior();

	//操作位置
	void setPosition(Vec2 &p){position=p;}
	Vec2& getPosition(){return position;}//注意返回的是引用

	//孩子管理
	bool addChild(Node *child,int prior=0);
	//删除孩子节点
	bool deleteChild(Node *child);
	//不一定存在父节点，不一定成功
	bool removeFromParent();

	//去掉 引起了头文件循环
	//EventDispatch *getEventDispatch();


	//是否可见
	void setVisible(bool visible);
	bool getVisable();

	void listChild();//调试函数，列举孩子链表

	//更新函数（简化为按照UI次序更新）
	bool isScheduled();
	void scheduleUpdate(void);
	void unscheduleUpdate(void);
	virtual void update(float delta);
};





#endif