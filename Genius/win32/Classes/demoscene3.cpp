#include"demoscene3.h"

#define NUM		13			// 烟花种类数量宏定义

/***** 结构定义区 **********/

// 烟花结构
struct FIRE
{
	int r;					// 当前爆炸半径
	int max_r;				// 爆炸中心距离边缘最大半径
	int x, y;				// 爆炸中心在窗口的坐标
	int cen_x, cen_y;		// 爆炸中心相对图片左上角的坐标
	int width, height;		// 图片的宽高
	int xy[240][240];		// 储存图片像素点

	bool show;				// 是否绽放
	bool draw;				// 开始输出像素点
	DWORD t1, t2, dt;		// 绽放速度
}Fire[NUM];

// 烟花弹结构
struct JET
{
	int x, y;				// 喷射点坐标
	int hx, hy;				// 最高点坐标------将赋值给 FIRE 里面的 x, y
	int height;				// 烟花高度
	bool shoot;				// 是否可以发射

	DWORD t1, t2, dt;		// 发射速度
	IMAGE img[2];			// 储存花弹一亮一暗图片
	byte n : 1;				// 图片下标
}Jet[NUM];

DemoScene3::DemoScene3()
{
	//管理员拥有最高权限
	Macros::admin=true;
	Macros::sleep=10;
	Macros::clear=false;
}

bool DemoScene3::init()
{
	//初始化父级init
	if ( !Layer::init() )
    {
        return false;
    }	

	t1	= timeGetTime();		// 筛选烟花计时
	st1	= timeGetTime();		// 播放花样计时
	pMem = GetImageBuffer();		// 获取窗口显存指针

	for ( int i = 0; i < NUM; i++ )		// 初始化烟花
	{
		Init( i );
	}
	Load();
	scheduleUpdate();

	return true;
}

 Scene *DemoScene3::createScene()
 {
    auto scene = Scene::create();

    auto layer =DemoScene3:: create();

    scene->addChild(layer);

    // return the scene
    return scene;
 }

 void DemoScene3::update(float delta)
 {
		Sleep(1 );
		// 随机选择 4000 个像素点擦除
		for ( int clr = 0; clr < 1000; clr++ )
		{
			for ( int j = 0; j < 2; j++ )
			{
				int px1 = getRandomInt(2400) % 1200;
				int py1 = getRandomInt(2400) % 800;

				if ( py1 < 799 )				// 防止越界
					pMem[py1 * 1200 + px1] = pMem[py1 * 1200 + px1 + 1] = BLACK;	// 对显存赋值擦出像素点
			}
		}
		Chose( t1);// 筛选烟花
		Shoot();	// 发射烟花
		Show(pMem	);// 绽放烟花
		Style(st1);	// 花样发射
 }

// 初始化烟花参数
void DemoScene3::Init( int i )
{
	// 分别为：烟花中心到图片边缘的最远距离、烟花中心到图片左上角的距离 (x、y) 两个分量
	int r[13] = { 120, 120, 155, 123, 130, 147, 138, 138, 130, 135, 140, 132, 155 };
	int x[13] = { 120, 120, 110, 117, 110, 93,  102, 102, 110, 105, 100, 108, 110 };
	int y[13] = { 120, 120, 85,  118, 120, 103, 105, 110, 110, 120, 120, 104, 85  };

	/**** 初始化烟花 *****/

	Fire[i].x		= 0;				// 烟花中心坐标
	Fire[i].y		= 0;
	Fire[i].width	= 240;				// 图片宽
	Fire[i].height	= 240;				// 图片高
	Fire[i].max_r	= r[i];				// 最大半径
	Fire[i].cen_x	= x[i];				// 中心距左上角距离
	Fire[i].cen_y	= y[i];
	Fire[i].show	= false;			// 是否绽放
	Fire[i].dt		= 5;				// 绽放时间间隔
	Fire[i].t1		= timeGetTime();
	Fire[i].r		= 0;				// 从 0 开始绽放

	/**** 初始化烟花弹 *****/

	Jet[i].x		= -240;				// 烟花弹左上角坐标
	Jet[i].y		= -240;
	Jet[i].hx		= -240;				// 烟花弹发射最高点坐标
	Jet[i].hy		= -240;
	Jet[i].height	= 0;				// 发射高度
	Jet[i].t1		= timeGetTime();
	Jet[i].dt		= rand() % 10;		// 发射速度时间间隔
	Jet[i].n		= 0;				// 烟花弹闪烁图片下标
	Jet[i].shoot	= false;			// 是否发射
}
// 加载图片
void DemoScene3::Load()
{
/**** 储存烟花的像素点颜色 ****/
	IMAGE fm, gm;
	//loadimage( &fm, "./win32/resource/fire/flower.jpg", 3120, 240 );
	loadimage( &fm, "./win32/resource/fire/flower.jpg", 3120, 240 );
	for ( int i = 0; i < 13; i++ )
	{
		SetWorkingImage( &fm );
		getimage( &gm, i * 240, 0, 240, 240 );
		SetWorkingImage( &gm );

		for ( int a = 0; a < 240; a++ )
			for ( int b = 0; b < 240; b++ )
				Fire[i].xy[a][b] = getpixel( a, b );
	}

/**** 加载烟花弹 ************/
	IMAGE sm;
	loadimage( &sm, "./win32/resource/fire/shoot.jpg", 200, 50 );
	putimage(0,0,&sm);
	for ( int i = 0; i < 13; i++ )
	{
		SetWorkingImage( &sm );
		int n = rand() % 5;

		getimage( &Jet[i].img[0], n * 20, 0, 20, 50 );			// 暗
		getimage( &Jet[i].img[1], (n + 5) * 20, 0, 20, 50 );	// 亮
	}
	SetWorkingImage();		// 设置回绘图窗口
}

// 在一定范围内筛选可发射的烟花，并初始化发射参数，输出烟花弹到屏幕，播放声音
void DemoScene3::Chose( DWORD& t1 )
{
	DWORD t2 = timeGetTime();

	if ( t2 - t1 > 100 )
	{
		int n = rand() % 20;

		if ( n < 13 && Jet[n].shoot == false && Fire[n].show == false )
		{
			/**** 重置烟花弹，预备发射 *****/
			Jet[n].x		= rand() % 1200;
			Jet[n].y		= rand() % 100 + 600;
			Jet[n].hx		= Jet[n].x;
			Jet[n].hy		= rand() % 400;
			Jet[n].height	= Jet[n].y - Jet[n].hy;
			Jet[n].shoot	= true;
			putimage( Jet[n].x, Jet[n].y, &Jet[n].img[Jet[n].n], SRCINVERT );

			/**** 播放每个烟花弹的声音 *****/
			char c1[50], c2[30], c3[30];
			sprintf_s( c1, "open ./win32/resource/fire/shoot.mp3 alias s%d", n );
			sprintf_s( c2, "play s%d", n );
			sprintf_s( c3, "close n%d", n );

			mciSendString( c3, 0, 0, 0 );
			mciSendString( c1, 0, 0, 0 );
			mciSendString( c2, 0, 0, 0 );
		}
		t1 = t2;
	}
}  
// 扫描烟花弹并发射
void DemoScene3::Shoot()
{
	for ( int i = 0; i < 13; i++ )
	{
		Jet[i].t2 = timeGetTime();

		if ( Jet[i].t2 - Jet[i].t1 > Jet[i].dt && Jet[i].shoot == true )
		{
			/**** 烟花弹的上升 *****/
			putimage( Jet[i].x, Jet[i].y, &Jet[i].img[Jet[i].n], SRCINVERT );

			if ( Jet[i].y > Jet[i].hy )
			{
				Jet[i].n++;
				Jet[i].y -= 5;
			}

			putimage( Jet[i].x, Jet[i].y, &Jet[i].img[Jet[i].n], SRCINVERT );

			/**** 上升到高度的 3 / 4，减速 *****/
			if ( (Jet[i].y - Jet[i].hy) * 4 < Jet[i].height )
				Jet[i].dt = rand() % 4 + 10 ;

			/**** 上升到最大高度 *****/
			if ( Jet[i].y <= Jet[i].hy )
			{
				// 播放爆炸声
				char c1[50], c2[30], c3[30];
				sprintf_s( c1, "open ./win32/resource/fire/bomb.wav alias n%d", i );
				sprintf_s( c2, "play n%d", i );
				sprintf_s( c3, "close s%d", i );

				mciSendString( c3, 0, 0, 0 );
				mciSendString( c1, 0, 0, 0 );
				mciSendString( c2, 0, 0, 0 );

				putimage( Jet[i].x, Jet[i].y, &Jet[i].img[Jet[i].n], SRCINVERT );	// 擦掉烟花弹
				Fire[i].x = Jet[i].hx + 10;											// 在烟花弹中间爆炸
				Fire[i].y = Jet[i].hy;												// 在最高点绽放
				Fire[i].show = true;					// 开始绽放
				Jet[i].shoot = false;					// 停止发射
			}
			Jet[i].t1 = Jet[i].t2;
		}
	}
}
// 显示花样
void DemoScene3::Style( DWORD& st1 )
{
	DWORD st2 = timeGetTime();

	if ( st2 - st1 > 266000 )		// 一首歌的时间
	{
		// 心形坐标
		int x[13] = { 60, 75, 91, 100, 95, 75, 60, 45, 25, 15, 25, 41, 60 };
		int y[13] = { 65, 53, 40, 22, 5, 4, 20, 4, 5, 22, 40, 53, 65 };
		for ( int i = 0; i < NUM; i++ )
		{
			cleardevice();
			/**** 规律分布烟花弹 ***/
			Jet[i].x		= x[i] * 10;
			Jet[i].y		= ( y[i] + 75 ) * 10;
			Jet[i].hx		= Jet[i].x;
			Jet[i].hy		= y[i] * 10;
			Jet[i].height	= Jet[i].y - Jet[i].hy;
			Jet[i].shoot	= true;
			Jet[i].dt		= 7;
			putimage( Jet[i].x, Jet[i].y, &Jet[i].img[Jet[i].n], SRCINVERT );	// 显示烟花弹

			/**** 设置烟花参数 ***/
			Fire[i].x		= Jet[i].x + 10;
			Fire[i].y		= Jet[i].hy;
			Fire[i].show	= false;
			Fire[i].r		= 0;

			/**** 播放发射声音 ***/
			char c1[50], c2[30], c3[30];
			sprintf_s( c1, "open ./win32/resource/fire/shoot.mp3 alias s%d", i );
			sprintf_s( c2, "play s%d", i );
			sprintf_s( c3, "close n%d", i );

			mciSendString( c3, 0, 0, 0 );
			mciSendString( c1, 0, 0, 0 );
			mciSendString( c2, 0, 0, 0 );
		}
		st1 = st2;
	}
}
// 绽放烟花
void DemoScene3::Show( DWORD* pMem )
{
	// 烟花个阶段绽放时间间隔，制作变速绽放效果
	int drt[16] = { 5, 5, 5, 5, 5, 6, 25, 25, 25, 25, 55, 55, 55, 55, 55 };

	for ( int i = 0; i < NUM; i++ )
	{
		Fire[i].t2 = timeGetTime();

		// 增加爆炸半径，绽放烟花，增加时间间隔做变速效果
		if ( Fire[i].t2 - Fire[i].t1 > Fire[i].dt && Fire[i].show == true )
		{
			if ( Fire[i].r < Fire[i].max_r )
			{
				Fire[i].r++;
				Fire[i].dt = drt[Fire[i].r / 10];
				Fire[i].draw = true;
			}

			if ( Fire[i].r >= Fire[i].max_r - 1 )
			{
				Fire[i].draw = false;
				Init( i );
			}
			Fire[i].t1 = Fire[i].t2;
		}

		// 如果该号炮花可爆炸，根据当前爆炸半径画烟花，颜色值接近黑色的不输出。
		if ( Fire[i].draw )
		{
			for ( double a = 0; a <= 6.28; a += 0.01 )
			{
				int x1 = (int)( Fire[i].cen_x + Fire[i].r * cos(a) );				// 相对于图片左上角的坐标
				int y1 = (int)( Fire[i].cen_y - Fire[i].r * sin(a) );

				if ( x1 > 0 && x1 < Fire[i].width && y1 > 0 && y1 < Fire[i].height )	// 只输出图片内的像素点
				{
					int b = Fire[i].xy[x1][y1] & 0xff;
					int g = ( Fire[i].xy[x1][y1] >> 8 ) & 0xff;
					int r = ( Fire[i].xy[x1][y1] >> 16 );

					// 烟花像素点在窗口上的坐标
					int xx = (int)( Fire[i].x + Fire[i].r * cos(a) );
					int yy = (int)( Fire[i].y - Fire[i].r * sin(a) );

					// 较暗的像素点不输出、防止越界
					if ( r > 0x20 && g > 0x20 && b > 0x20 && xx > 0 && xx < 1200 && yy > 0 && yy < 800 )
						pMem[yy * 1200 + xx] = BGR( Fire[i].xy[x1][y1] );	// 显存操作绘制烟花
				}
			}
			Fire[i].draw = false;
		}
	}
}