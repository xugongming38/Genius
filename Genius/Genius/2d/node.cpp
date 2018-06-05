#include"node.h"
#include"../control/schedule/schedule.h"

Node* Node::create(Vec2&p)
{
	Node * node=new Node();
	if(node->init())
	{
		//将节点自身加入自释放池
		node->autorelease();
		return node;
	}
	return nullptr;
}

//构造函数
Node::Node()
{
	scheduled=false;
	position=0;
	//节点自身
	id=-1;//默认为-1，除非单独制定
	prior=0;//默认同级

	//孩子管理
	head=right=down=nullptr;
	father=nullptr;//父节点暂时为空
	childsize=0;

}

//初始化
bool Node::init()
{
	return true;
}

//操作ID相关
bool Node::setID(int id)
{
	this->id=id;
	return true;
}
int Node::getID(){return id;}

//操作prior相关
bool Node::setPrior(int prior)
{
	this->prior=prior;
	return true;
}
int Node::getPrior(){return prior;}

	//是否可见
void Node::setVisible(bool visible)
{
	this->visible=visible;
}
bool Node::getVisable()
{
	return visible;
}


//更新调度
bool Node::isScheduled()
{
	return scheduled;
}
void Node::scheduleUpdate(void)
{
	if(!scheduled)
	{
		Scheduler::getInstance()->push(this);
		scheduled=true;
		return;
	}
		
	
}
void Node::unscheduleUpdate(void)
{
	if(scheduled)
	{
		scheduled=false;
		Scheduler::getInstance()->earse(this);
		return;
	}
		
	
}




//添加孩子节点（核心函数）!!  该函数较为复杂，注意。。。。
bool Node::addChild(Node *child,int prior)//默认参数只能放在声明和定义之一中，一般那放在声明文件中，否则只能在定义文件中调用
{
	//设置父节点
	child->father=this;

	//将子节点的父节点设置为当前节点，便于获取相对坐标
	//将孩子节点加入父节点孩子列表中

	//引用计数+1，在取出时-1（注意）
	child->retain();

	child->setPrior(prior);
	if(head==nullptr)
	{ 
		head=child;child->right=nullptr;child->down=nullptr;return true;
	}

	Node *T=head;
	if(T->prior>prior)
	{
		child->down=T;
		child->right=nullptr;
		head=child;
		return true;
	}
	while(T->prior<prior) 
	{
		if(T->down==nullptr)
		{
			T->down=child;child->right=nullptr;child->down=nullptr;return true;
		}
			
		else
		{
			if(T->down->prior<=prior)
				T=T->down;
			else
			{
				child->down=T->down;
				T->down=child;
				child->right=nullptr;
				return true;
			}
		}

	  }
	//此时已找到所属队列
	while(T->right!=nullptr)T=T->right;
	T->right=child;
	child->right=nullptr;
	childsize++;
	return true;
}

//注意与父节点坐标相加，相对坐标*********核心*************

void Node::draw()
{
	
	//先绘制自身，后绘制孩子节点
	//---------
	//Node结点没什么要draw
	//--------

	//循环按照优先级绘制孩子节点************
	for(Node *i=head;i;i=i->down)
		for(Node *j=i;j;j=j->right)
			j->draw();
}

void Node::listChild()//调试函数，列举孩子链表
{
	printf("--------------------ID为%d的孩子节点表---------------------\n",getID());
	for(Node *i=head;i;i=i->down)
	{
		printf("优先级为%d的队列： ",i->getPrior());
		for(Node *j=i;j;j=j->right)
		{
			cout<<j->getID()<<"--";
		}
		cout<<endl;
	}
}

void Node::update(float delta)
{
		//先不写，估计和draw类似
}

//删除孩子节点(较为复杂)
bool Node::deleteChild(Node * child)
{
	ASSERT(child!=nullptr,"要删除孩子节点不为空！");
	ASSERT(head!=nullptr,"要删除的父节点的孩子节点不为空！");
	if(head==nullptr)
		return false;

	//删除标志
	bool del=false;

	//孩子结点头结点即为要删除孩子
	if(head==child)
	{ 
		//第一层不止一个节点，不会降层
		if(head->right!=nullptr)
		{
			head->right->down=head->down;
			head=head->right;
		}
		//第一层只有一个节点，会降层
		else
		{
			head=head->down;
		}
		child->release();
		del=true;
	}
	//孩子结点头结点并非要删除孩子
	else
	{
		//检索该节点的左边结点
		Node *left=head;
		//检索该节点的上边结点，防止为其他层的头结点
		Node *up=nullptr;
		
		//在第一层找
		for(Node *index=head->right;index!=nullptr;index=index->right)
		{
			if(index==child)
			{
				del=true;
				left->right=index->right;
				child->release();
				break;
			}
			left=index;
		}
		up=head;
		//在第一层未找到，继续向下一层找
		if(del==false)
			for(Node *i=head->down;i;i=i->down)
			{
				for(Node *j=i;j;j=j->right)
				{
					//在其他层的首节点处判断
					if(j==i)
					{
						//若删除节点是其他层的首节点
						if(j==child)
						{
							del=true;
							//找到后若当前层只有一个节点
							if(j->right==nullptr)
							{
								up->down=j->down;
							}
							//找到后若当前层不只有一个节点
							else
							{
								up->down=j->right;
								j->right->down=j->down;
							}
							child->release();
							break;
						}
					}
					//若删除节点不是其他层的首节点
					else
					{
						//在当前层非首节点找到
						if(j==child)
						{
							del=true;
							left->right=j->right;
							child->release();
							break;
						}
					}

					left=j;
				}
				//若在上一层找到，则结束循环
				if(del==true)
					break;
				up=i;
			}


	}

	if(del)
		childsize--;
	return del;
}
//不一定存在父节点，不一定成功
bool Node::removeFromParent()
{
	Node *parent=this->father;
	if(parent!=nullptr)
	{
		parent->deleteChild(this);
		this->release();
		return true;
	}
	else	
		return false;
}