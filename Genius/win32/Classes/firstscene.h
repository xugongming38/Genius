#ifndef __FISTSCENE_H__
#define __FISTSCENE_H__

//引入引擎核心头文件
#include"../../Genius/Genius.h"

class FirstScene:public Scene
{
public:
	bool init();
	static FirstScene* create();
};



#endif