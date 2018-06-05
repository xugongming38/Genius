#ifndef __SCHEDULE_H__
#define __SCHEDULE_H__

#include"../../2d/node.h"

class Scheduler
{
public:
	static Scheduler* instance;
	static Scheduler*getInstance();
	vector<Node*> scheduleList;
	void push(Node*node );
	void earse(Node*node);
	void update(float dt );
};


#endif