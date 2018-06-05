#ifndef __DEMO3__
#define __DEMO3__

#include"../../Genius/Genius.h"
#include <Mmsystem.h>		// 使用该计时器必须包含的


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
	 void Init	( int	 );		// 初始化烟花
	 void Load	( );		// 加载烟花图片
	 void Shoot	();		// 发射烟花
	 void Chose	( DWORD& );		// 筛选烟花
	 void Style	( DWORD& );		// 发射样式
	 void Show	( DWORD* );		// 绽放烟花
};

#endif