#ifndef __DEMO1__
#define __DEMO1__
#include"../../Genius/Genius.h"

#include"popsprite.h"
class DemoScene1:public Layer
{
public:
	//10*10��ɫ�����
	PopSprite* popStarSprite[10][10];
	Array<PopSprite*> poparr;

	//�������Ҽ��
	void checkPopUDLR(PopSprite *pop,int i,int j,Array<PopSprite*>& poparr);
	//�������
	void checkPopISNEW();

	void reDiessPopStar();
	void reDiessPopStarRT();
	void reDiessPopStarRun(int x);
	
	//�Զ��������η���
	void autoCreatpopSprite();

	//��괦�����
	void handleMouse(MOUSEMSG m);
	//����õ�popstar
	PopSprite * getPopSprite(Vec2 pos);

	  bool init();
	  static Scene *createScene();
	  CREATE(DemoScene1);
	  virtual void update(float delta);
};

#endif