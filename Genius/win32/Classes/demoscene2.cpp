#include"demoscene2.h"
#include"animation.h"
#include"bullet.h"

bool DemoScene2::init()
{
	//初始化父级init
	if ( !Layer::init() )
    {
        return false;
    }
	sumTime=0;
	ifdraw=false;
	ifdrawactor=false;
	drawPos=Vec2(-1,-1);
	auto Mouselistener=MouseListener::create((MouseCallBack)&DemoScene2::handleMouse,this);
	EventDispatch::getInstance()->addListener(Mouselistener);

	auto Keyboardlistener=KeyboardListener::create((KeyboardCallBack)&DemoScene2::handleKeyboard,this);
	EventDispatch::getInstance()->addListener(Keyboardlistener);

	InitImages();

	actor=Animation::create(10,hero_img);
	actor->setPosition(Vec2(200,200));
	actor->setAI(false);
	addChild(actor);

	for(int i=0;i<50;i++)
	{
		Animation *enemy=Animation::create(14,enemy_img);
		int x=getRandomInt(800);
		int y=getRandomInt(800);
		enemy->setPosition(Vec2(x,y));
		BulletManager::vBullet.push_back(enemy);
		addChild(enemy);
	}
	

	


	scheduleUpdate();
	return true;
}

 Scene *DemoScene2::createScene()
 {
    auto scene = Scene::create();


	//auto colorbg=ColorfulLayer::create(RGB(180,170,160));
	//创建背景
	
	auto colorbg= Layer::create();
	auto bgSprite=Sprite::createSprite("background.jpg");
	colorbg->addChild(bgSprite);
	scene->addChild(colorbg);

    auto layer =DemoScene2:: create();
    scene->addChild(layer);

    // return the scene
    return scene;
 }

 void DemoScene2::update(float delta)
 {
	
		
	 //Vec2 v=sp->getPosition()+Vec2(1,1);
	// sp->setPosition(v);
	 sumTime+=delta;

 }

 void DemoScene2::handleMouse(MOUSEMSG m)
{
	if(m.uMsg==WM_LBUTTONUP||m.uMsg==WM_LBUTTONDOWN)
	{
		if(m.uMsg==WM_LBUTTONUP)
			ifdraw=false;
		else
		{
			ifdraw=true;
			drawPos=Vec2(m.x,m.y);
			//
			//cout<<"&&&&"<<PointDistance(drawPos,actor->getPosition())<<"&&&&"<<endl;
			if(PointDistance(drawPos,actor->getPosition())>=90000)
			{
				actor->hasTarget=true;
				actor->setTarget(drawPos);
			}
			else
			{
				auto bullet =Bullet::create("a.jpg",drawPos);
				bullet->setPosition(actor->getPosition());
				addChild(bullet);
				//BulletManager:: vBullet.push_back(bullet);
			}
				
			
		}
			
	}
}
void DemoScene2::DrawCircle(int x, int y, int r, int R, double a)
{
	double PI=3.14;
	setorigin(x,y);
	setbkmode(TRANSPARENT);
	setlinecolor(LIGHTGREEN);
	circle(0,0,r); //绘制两个同心圆
	circle(0,0,R);

	double a1,a2,a3; //弧度值
	int x11,y11,x12,y12; //分割圆环线坐标
	int x21,y21,x22,y22;
	int x31,y31,x32,y32;

	a1 =2*PI/3+a; //绘制第一条圆环间隔线
	x11 = (int)(r*cos(a1));
	y11 = (int)(r*sin(a1));
	x12 = (int)(R*cos(a1));
	y12 = (int)(R*sin(a1));
	line(x11,y11,x12,y12); 
	a2 = 2*2*PI/3+a; //绘制第二条圆环间隔线
	x21 = (int)(r*cos(a2));
	y21 = (int)(r*sin(a2));
	x22 = (int)(R*cos(a2));
	y22 = (int)(R*sin(a2));
	line(x21,y21,x22,y22);
	//line(60,0,80,0); //绘制第三条圆环间隔线
	a3 = 0+a; //绘制第三条圆环间隔线
	x31 = (int)(r*cos(a3));
	y31 = (int)(r*sin(a3));
	x32 = (int)(R*cos(a3));
	y32 = (int)(R*sin(a3));
	line(x31,y31,x32,y32);

	int x1,x2,x3;
	int y1,y2,y3;

	int dis=(r+R)/2;

	x1=(int)(dis*cos(PI/3+a));
	y1=(int)(dis*sin(PI/3+a));

	x2=(int)(dis*cos(PI+a));
	y2=(int)(dis*sin(PI+a));

	x3=(int)(dis*cos(5*PI/3+a));
	y3=(int)(dis*sin(5*PI/3+a));

	//用红、黄、蓝三色填充三段圆弧
	setfillcolor(RGB(253,249,2)); //YELLOW
	floodfill(x1,y1,LIGHTGREEN); 
	setfillcolor(RGB(231,58,15)); //RED
	floodfill(x2,y2,LIGHTGREEN);
	setfillcolor(RGB(0,119,192)); //BLUE
	floodfill(x3,y3,LIGHTGREEN);

	////用背景色清除边缘线
	//setlinecolor(RGB(40,68,115)); //背景色填充
	//circle(0,0,60);
	//circle(0,0,80);
	//setfillcolor(RGB(231,58,15)); //RED
	//line(x11,y11,x12,y12);
	//setfillcolor(RGB(0,119,192)); //BLUE
	//line(x21,y21,x22,y22);
	//setfillcolor(RGB(253,249,2)); //YELLOW
	//line(60,0,80,0);


	setorigin(0,0);
}

void DemoScene2::draw()
{
	Layer::draw();	
	if(BulletManager::vBullet.size()>0)
	  {
		  char s[20];
		  sprintf_s(s,"已用时间：%f",sumTime);
		   outtextxy(0,0,s);
	  }
	if(ifdraw)
		{
			float a=sumTime*10;
			while(a>6.28f) a-=6.28;
			DrawCircle(drawPos.getX(),drawPos.getY(),60,80,a);
		}
		
		if(ifdrawactor)
		{
			Vec2 pos=actor->getPosition();
			DrawCircle(pos.getX()+20,pos.getY()+20,300,303);
		}
}

void DemoScene2::InitImages()
{
	loadimage(&hero_rc,"hero.jpg");	
	SetWorkingImage(&hero_rc);
	for(int i=0;i<4;i++)
	{
		getimage(&hero_img[i][1],40*i,0,40,40);		
		getimage(&hero_img[i][0],40*i,40,40,40);
	}
	for(int i=5;i<9;i++)
	{
		getimage(&hero_img[i][1],40*(i-5),80,40,40);		
		getimage(&hero_img[i][0],40*(i-5),120,40,40);
	}
	getimage(&hero_img[4][1],240,160,40,40);	
	getimage(&hero_img[4][0],240,200,40,40);
	getimage(&hero_img[9][1],240,240,40,40);
	getimage(&hero_img[9][0],240,280,40,40);

	SetWorkingImage(NULL);

	
	loadimage(&enemy_rc,"enemy.jpg");			//获取图片
	SetWorkingImage(&enemy_rc);
	for(int i=0;i<5;i++)
	{
		getimage(&enemy_img[i][1],40*i,0,40,40);		
		getimage(&enemy_img[i][0],40*i,40,40,40);
	}
	for(int i=7;i<12;i++)
	{
		getimage(&enemy_img[i][1],40*(i-7),80,40,40);		
		getimage(&enemy_img[i][0],40*(i-7),120,40,40);
	}
	getimage(&enemy_img[5][1],280,160,40,40);	
	getimage(&enemy_img[5][0],280,200,40,40);
	getimage(&enemy_img[6][1],320,160,40,40);	
	getimage(&enemy_img[6][0],320,200,40,40);
	getimage(&enemy_img[12][1],280,240,40,40);
	getimage(&enemy_img[12][0],280,280,40,40);
	getimage(&enemy_img[13][1],320,240,40,40);
	getimage(&enemy_img[13][0],320,280,40,40);

	SetWorkingImage(NULL);
}

//键盘处理相关
void DemoScene2::handleKeyboard(int key)
{
	if(key==32)
		ifdrawactor=!ifdrawactor;
	//cout<<" #"<<key<<"#"<<endl;
}