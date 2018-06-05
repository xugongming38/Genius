#ifndef __DEMO2__
#define __DEMO2__

#include"../../Genius/Genius.h"

#include"popsprite.h"
#include"animation.h"
#include"bullet.h"

class DemoScene2:public Layer
{
public:
	//�����Լ����˶������ɶ��ʹ��
	IMAGE hero_img[10][2],enemy_img[14][2];
	IMAGE hero_rc,enemy_rc;

	Animation *actor;

	Vec2 drawPos;
	bool ifdraw;
	bool ifdrawactor;
	float  sumTime;
	//��괦�����
	void handleMouse(MOUSEMSG m);
	//���̴������
	void handleKeyboard(int key);
	//����õ�popstar
	PopSprite * getPopSprite(Vec2 pos);

	  bool init();
	  static Scene *createScene();
	  CREATE(DemoScene2);
	  virtual void update(float delta);
	  void DrawCircle(int x, int y, int r1, int r2, double a=0);
	  virtual void draw();
	  void InitImages();
};

#endif