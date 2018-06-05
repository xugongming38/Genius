#include"director.h"

//��װʵ�ֹ�������
Director::Director()
{
}
Director::~Director()
{
    instance = nullptr;
}
//����ģʽ
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

//��ʼ������
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
        Logn("Error on gettimeofday( lastUpdate��ʼ�� )");
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

//ѹ��sceneջ��ȡ����ǰ����
void Director::pushScene(Scene *scene)
{
    ASSERT(scene, "the scene should not null");
	scenesStack.push_back(scene);
	nextScene = scene;
	//���б�ġ�������
}

// ������ǰջ��������ʹ����һ��ջ������
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

//�׸�������������������δʵ�֣�����
void Director::runWithScene(Scene *scene)
{
    ASSERT(scene != nullptr, "This command can only be used to start the Director. There is already a scene present.");
    ASSERT(runningScene == nullptr, "runningScene should be null");

    pushScene(scene);
}

//�滻��ǰ�������г���
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
	//����+1
    nextScene->retain();
    nextScene = nullptr;
}

//��������ʱδʵ�֣�
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

//����deltatime
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

//����ѭ��
void Director::mainLoop()
{
	//���Ƴ���
    drawScene();
    // �ڴ���ͷŹ���
	PoolManager::getInstance()->getCurrentPool()->clear();
}

// ���Ƴ���
void Director::drawScene()
{
    // ����deltaʱ��
    calculateDeltaTime();
    //cout<<deltaTime<<endl;
    // ��deltaTime�ӽ���0������һ֡
	
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
    // ���Ƴ���
    if (runningScene)
    {
		//����scene��ʹ��draw������ȫ��
		runningScene->draw();
    }

 
	//FPS��ʾ���
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
	//���̼���
	char c;
	if(kbhit())//�������в���ȷ
	{
		c=getch();//getch()��getchar()�����������ǣ�getch()�ڼ�⵽�û�����һ���ַ���ͻ�������򣬲���Ҫ���س����������ַ���������Ļ����ʾ��
		eventDispatch->sendEvent(EventKeyboard::create(c));
		cout<<c<<endl;
	}

	//������
	MOUSEMSG m;
	if (MouseHit())
	{
		m = GetMouseMsg();
		if(m.uMsg==WM_LBUTTONUP||m.uMsg==WM_LBUTTONDOWN)//��һ���� ֻ�����
		//if(m.uMsg!=WM_MOUSEMOVE)//�ƶ�̫��ʱ
		//X��ʱֻ�������Ҽ��ͷ�ʱ�������ܲ��㣬���Ǵ�msg��ϢX
		//�޸�Ϊȫ����Ϣ
		eventDispatch->sendEvent(EventMouse::create(m));
	}

}