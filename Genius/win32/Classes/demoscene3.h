#ifndef __DEMO3__
#define __DEMO3__

#include"../../Genius/Genius.h"
#include <Mmsystem.h>		// ʹ�øü�ʱ�����������


class DemoScene3:public Layer
{
public:
	DemoScene3();

	  bool init();
	  static Scene *createScene();
	  CREATE(DemoScene3);
	  virtual void update(float delta);

	  DWORD t1;
	  DWORD st1;
	  DWORD* pMem;

	  //
	 void Init	( int	 );		// ��ʼ���̻�
	 void Load	( );		// �����̻�ͼƬ
	 void Shoot	();		// �����̻�
	 void Chose	( DWORD& );		// ɸѡ�̻�
	 void Style	( DWORD& );		// ������ʽ
	 void Show	( DWORD* );		// �����̻�
};

#endif