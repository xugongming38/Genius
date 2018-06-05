#include"node.h"
#include"../control/schedule/schedule.h"

Node* Node::create(Vec2&p)
{
	Node * node=new Node();
	if(node->init())
	{
		//���ڵ�����������ͷų�
		node->autorelease();
		return node;
	}
	return nullptr;
}

//���캯��
Node::Node()
{
	scheduled=false;
	position=0;
	//�ڵ�����
	id=-1;//Ĭ��Ϊ-1�����ǵ����ƶ�
	prior=0;//Ĭ��ͬ��

	//���ӹ���
	head=right=down=nullptr;
	father=nullptr;//���ڵ���ʱΪ��
	childsize=0;

}

//��ʼ��
bool Node::init()
{
	return true;
}

//����ID���
bool Node::setID(int id)
{
	this->id=id;
	return true;
}
int Node::getID(){return id;}

//����prior���
bool Node::setPrior(int prior)
{
	this->prior=prior;
	return true;
}
int Node::getPrior(){return prior;}

	//�Ƿ�ɼ�
void Node::setVisible(bool visible)
{
	this->visible=visible;
}
bool Node::getVisable()
{
	return visible;
}


//���µ���
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




//��Ӻ��ӽڵ㣨���ĺ�����!!  �ú�����Ϊ���ӣ�ע�⡣������
bool Node::addChild(Node *child,int prior)//Ĭ�ϲ���ֻ�ܷ��������Ͷ���֮һ�У�һ���Ƿ��������ļ��У�����ֻ���ڶ����ļ��е���
{
	//���ø��ڵ�
	child->father=this;

	//���ӽڵ�ĸ��ڵ�����Ϊ��ǰ�ڵ㣬���ڻ�ȡ�������
	//�����ӽڵ���븸�ڵ㺢���б���

	//���ü���+1����ȡ��ʱ-1��ע�⣩
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
	//��ʱ���ҵ���������
	while(T->right!=nullptr)T=T->right;
	T->right=child;
	child->right=nullptr;
	childsize++;
	return true;
}

//ע���븸�ڵ�������ӣ��������*********����*************

void Node::draw()
{
	
	//�Ȼ�����������ƺ��ӽڵ�
	//---------
	//Node���ûʲôҪdraw
	//--------

	//ѭ���������ȼ����ƺ��ӽڵ�************
	for(Node *i=head;i;i=i->down)
		for(Node *j=i;j;j=j->right)
			j->draw();
}

void Node::listChild()//���Ժ������оٺ�������
{
	printf("--------------------IDΪ%d�ĺ��ӽڵ��---------------------\n",getID());
	for(Node *i=head;i;i=i->down)
	{
		printf("���ȼ�Ϊ%d�Ķ��У� ",i->getPrior());
		for(Node *j=i;j;j=j->right)
		{
			cout<<j->getID()<<"--";
		}
		cout<<endl;
	}
}

void Node::update(float delta)
{
		//�Ȳ�д�����ƺ�draw����
}

//ɾ�����ӽڵ�(��Ϊ����)
bool Node::deleteChild(Node * child)
{
	ASSERT(child!=nullptr,"Ҫɾ�����ӽڵ㲻Ϊ�գ�");
	ASSERT(head!=nullptr,"Ҫɾ���ĸ��ڵ�ĺ��ӽڵ㲻Ϊ�գ�");
	if(head==nullptr)
		return false;

	//ɾ����־
	bool del=false;

	//���ӽ��ͷ��㼴ΪҪɾ������
	if(head==child)
	{ 
		//��һ�㲻ֹһ���ڵ㣬���ή��
		if(head->right!=nullptr)
		{
			head->right->down=head->down;
			head=head->right;
		}
		//��һ��ֻ��һ���ڵ㣬�ή��
		else
		{
			head=head->down;
		}
		child->release();
		del=true;
	}
	//���ӽ��ͷ��㲢��Ҫɾ������
	else
	{
		//�����ýڵ����߽��
		Node *left=head;
		//�����ýڵ���ϱ߽�㣬��ֹΪ�������ͷ���
		Node *up=nullptr;
		
		//�ڵ�һ����
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
		//�ڵ�һ��δ�ҵ�����������һ����
		if(del==false)
			for(Node *i=head->down;i;i=i->down)
			{
				for(Node *j=i;j;j=j->right)
				{
					//����������׽ڵ㴦�ж�
					if(j==i)
					{
						//��ɾ���ڵ�����������׽ڵ�
						if(j==child)
						{
							del=true;
							//�ҵ�������ǰ��ֻ��һ���ڵ�
							if(j->right==nullptr)
							{
								up->down=j->down;
							}
							//�ҵ�������ǰ�㲻ֻ��һ���ڵ�
							else
							{
								up->down=j->right;
								j->right->down=j->down;
							}
							child->release();
							break;
						}
					}
					//��ɾ���ڵ㲻����������׽ڵ�
					else
					{
						//�ڵ�ǰ����׽ڵ��ҵ�
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
				//������һ���ҵ��������ѭ��
				if(del==true)
					break;
				up=i;
			}


	}

	if(del)
		childsize--;
	return del;
}
//��һ�����ڸ��ڵ㣬��һ���ɹ�
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