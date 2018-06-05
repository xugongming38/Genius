#include"director.h"

//假装实现构造析构
Director::Director()
{
}
Director::~Director()
{
    instance = nullptr;
}
//单例模式
Director* Director::instance=nullptr;
Director* Director::getInstance()
{
	if (!instance)
    {
        instance = new Director();
        instance->init();
    }

    return instance;
}

//初始化操作
bool Director::init(void)
{
    // scenes
    runningScene = nullptr;
	nextScene = nullptr;
    scenesStack.reserve(15);

	//fps
    lastUpdate = new struct timeval;
	if (gettimeofday(lastUpdate, nullptr) != 0)
    {
        Logn("Error on gettimeofday( lastUpdate初始化 )");
    }
	totalFrames=0;
	totalTime=0;
    // paused ?
    paused = false;

    // scheduler
	scheduler =  Scheduler::getInstance();

	//eventDispatch
	eventDispatch =  EventDispatch::getInstance();
    return true;
}

//压入scene栈，取代当前场景
void Director::pushScene(Scene *scene)
{
    ASSERT(scene, "the scene should not null");
	scenesStack.push_back(scene);
	nextScene = scene;
	//还有别的。先留着
}

// 弹出当前栈顶场景，使用下一个栈顶场景
void Director::popScene(void)
{
	ASSERT(runningScene != nullptr, "running scene should not null");

	scenesStack.pop_back();
	auto c = scenesStack.size();

	if (c == 0)
	{
		end();
	}
	else
	{
		nextScene = scenesStack.at(c - 1);
	}
}

//首个场景（场景过场动画未实现！！）
void Director::runWithScene(Scene *scene)
{
    ASSERT(scene != nullptr, "This command can only be used to start the Director. There is already a scene present.");
    ASSERT(runningScene == nullptr, "runningScene should be null");

    pushScene(scene);
}

//替换当前正在运行场景
void Director::replaceScene(Scene *scene)
{
    ASSERT(runningScene, "Use runWithScene: instead to start the director");
    ASSERT(scene != nullptr, "the scene should not be null");
	
    if (nextScene)
    {
        nextScene = nullptr;
    }

    auto index = scenesStack.size();
	scenesStack.pop_back();
	scenesStack.push_back(scene);
    nextScene = scene;
}
void Director::setNextScene()
{
    runningScene = nextScene;
	//计数+1
    nextScene->retain();
    nextScene = nullptr;
}

//结束（暂时未实现）
void Director::end()
{

}

void Director::pause()
{
	paused=true;
}

void Director::resume()
{
	paused=false;
}

//计算deltatime
void Director::calculateDeltaTime()
{
    struct timeval now;

    if (gettimeofday(&now, nullptr) != 0)
    {
        Logn("error in gettimeofday");
        deltaTime = 0;
        return;
    }

   
        deltaTime = (now.tv_sec - lastUpdate->tv_sec)+ (now.tv_usec - lastUpdate->tv_usec) / 1000000.0f ;
        deltaTime = Max(float(0), deltaTime);


    // If we are debugging our code, prevent big delta time
    if (deltaTime > 0.2f)
	{
        deltaTime = 1 / 60.0f;
	}

    *lastUpdate = now;
}
float Director::getDeltaTime() const
{
	return deltaTime;
}

//核心循环
void Director::mainLoop()
{
	//绘制场景
    drawScene();
    // 内存池释放管理
	PoolManager::getInstance()->getCurrentPool()->clear();
}

// 绘制场景
void Director::drawScene()
{
    // 计算delta时间
    calculateDeltaTime();
    //cout<<deltaTime<<endl;
    // 当deltaTime接近于0，跳过一帧
	
    if(deltaTime < FLT_EPSILON)
    {
        return;
    }

	DelectHIDEvent();
    
    if (! paused)
    {
       scheduler->update(deltaTime);
       eventDispatch->dispatchEvent();
    }
    if (nextScene)
    {
        setNextScene();
    }
    // 绘制场景
    if (runningScene)
    {
		//遍历scene，使用draw，绘制全部
		runningScene->draw();
    }

 
	//FPS显示相关
    totalFrames++;
	totalTime+=deltaTime;
    // swap buffers
  
	if (Macros::debug)
    {
		cout<<"["<<totalFrames<<"] "<<"FPS=("<<1/deltaTime<<")  deltaTime=<"<<deltaTime<<">"<<endl;
    }
}

void Director::DelectHIDEvent()
{
	//键盘监听
	char c;
	if(kbhit())//缓冲区尚不明确
	{
		c=getch();//getch()与getchar()函数的区别是，getch()在检测到用户输入一个字符后就会继续程序，不需要按回车键，并且字符不会在屏幕上显示。
		eventDispatch->sendEvent(EventKeyboard::create(c));
		cout<<c<<endl;
	}

	//鼠标监听
	MOUSEMSG m;
	if (MouseHit())
	{
		m = GetMouseMsg();
		if(m.uMsg==WM_LBUTTONUP||m.uMsg==WM_LBUTTONDOWN)//进一步简化 只有左键
		//if(m.uMsg!=WM_MOUSEMOVE)//移动太耗时
		//X暂时只考虑左右键释放时，若功能不足，则考虑传msg信息X
		//修改为全部信息
		eventDispatch->sendEvent(EventMouse::create(m));
	}

}