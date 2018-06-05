#include"firstlayer.h"
#include"demoscene1.h"
#include"demoscene2.h"
#include"demoscene3.h"


bool FirstLayer::init()
{
	//初始化父级init
	if ( !Layer::init() )
    {
        return false;
    }
	AudioManager::getInstance()->playBackGroundAudio("明天的记忆.mp3");
	cout<<getCurrentDir();
	
	listening=true;

	
		//auto sp=Sprite::createSprite(_T(".\\win32\\resource\\abc.gif"));
		//sp=Sprite::createSprite("abc.gif");
		btn1=ColorfulSprite::createColorfulSprite(RGB(241,124,103),300,100);
		btn1->setPosition(Vec2(490,120));
		btn2=ColorfulSprite::createColorfulSprite(RGB(241,124,103),300,100);
		btn2->setPosition(Vec2(490,320));
		btn3=ColorfulSprite::createColorfulSprite(RGB(241,124,103),300,100);
		btn3->setPosition(Vec2(490,520));
	
		addChild(btn1);
		addChild(btn2);
		addChild(btn3);

		//MouseCallBack f=&FirstLayer::handleMouse;
		auto listener=MouseListener::create((MouseCallBack)&FirstLayer::handleMouse,this);
		EventDispatch::getInstance()->addListener(listener);
	
		scheduleUpdate();

	return true;
}

 Scene *FirstLayer::createScene()
 {
    auto scene = Scene::create();
    
    auto layer =FirstLayer:: create();

    scene->addChild(layer);

    // return the scene
    return scene;
 }

 void FirstLayer::update(float delta)
 {
	 //Vec2 v=sp->getPosition()+Vec2(1,1);
	// sp->setPosition(v);
 }
 void FirstLayer::handleMouse(MOUSEMSG m)
 {
	 if(!(m.uMsg==WM_LBUTTONUP||m.uMsg==WM_RBUTTONUP))
		 return;

	  Vec2 pos(m.x,m.y);
	 if(listening)
	 {
		 Rect r1= Rect(Vec2(490,120),300,100);
		 if(r1.containPoint(pos))
		 {
			 listening=false;
			 btn1->setColor(BLACK);
			  EventDispatch::getInstance()->MouseListeners_Clear();
			  Director::getInstance()->pushScene(DemoScene1::createScene());
			
			 return;
		 }
		 Rect r2= Rect(Vec2(490,320),300,100);
		 if(r2.containPoint(pos))
		 {
			 listening=false;
			 btn2->setColor(BLACK);
			 EventDispatch::getInstance()->MouseListeners_Clear();
			  Director::getInstance()->pushScene(DemoScene2::createScene());
			 return;
		 }
		 Rect r3= Rect(Vec2(490,520),300,100);
		 if(r3.containPoint(pos))
		 {
			 listening=false;
			 btn3->setColor(BLACK);
			 EventDispatch::getInstance()->MouseListeners_Clear();
			  Director::getInstance()->pushScene(DemoScene3::createScene());
			 return;
		 }
	 }
 }