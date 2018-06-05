#include"schedule.h"

Scheduler* Scheduler::instance=nullptr;
Scheduler* Scheduler::getInstance()
{
	if(instance==nullptr)
	{
		instance= new Scheduler();
	}
	return instance;
}

void Scheduler::push(Node*node )
{
	scheduleList.push_back(node);
}
void Scheduler::earse(Node*node)
{
	for (auto iter = scheduleList.begin(); iter != scheduleList.end(); iter++)
		if((*iter)==node)
		{
			scheduleList.erase(iter);
			break;
		}
}
void Scheduler::update(float dt )
{
	
	for (auto iter = scheduleList.begin(); iter != scheduleList.end(); iter++)
		(*iter)->update(dt);
}