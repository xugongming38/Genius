#ifndef __FISTSCENE_H__
#define __FISTSCENE_H__

//�����������ͷ�ļ�
#include"../../Genius/Genius.h"

class FirstScene:public Scene
{
public:
	bool init();
	static FirstScene* create();
};



#endif