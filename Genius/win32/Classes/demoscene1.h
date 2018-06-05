#ifndef __DEMO1__
#define __DEMO1__
#include"../../Genius/Genius.h"

#include"popsprite.h"
class DemoScene1:public Layer
{
public:
	//10*10的色块对象
	PopSprite* popStarSprite[10][10];
	Array<PopSprite*> poparr;

	//上下左右检查
	void checkPopUDLR(PopSprite *pop,int i,int j,Array<PopSprite*>& poparr);
	//迭代检查
	void checkPopISNEW();

	void reDiessPopStar();
	void reDiessPopStarRT();
	void reDiessPopStarRun(int x);
	
	//自动创建矩形方阵
	void autoCreatpopSprite();

	//鼠标处理相关
	void handleMouse(MOUSEMSG m);
	//点击得到popstar
	PopSprite * getPopSprite(Vec2 pos);

	  bool init();
	  static Scene *createScene();
	  CREATE(DemoScene1);
	  virtual void update(float delta);
};

#endif