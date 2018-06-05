#ifndef __FIRSTLAYER_H__
#define __FIRSTLAYER_H__

#include"../../Genius/Genius.h"

class FirstLayer:public Layer
{
public:
	bool listening;
	 ColorfulSprite *btn1;
	 ColorfulSprite *btn2;
	 ColorfulSprite *btn3;

	 void handleMouse(MOUSEMSG m);

	 bool init();
	  Scene *createScene();
	  CREATE(FirstLayer);
	  virtual void update(float delta);
};

#endif