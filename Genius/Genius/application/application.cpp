#include"application.h"
#include"../util/util.h"
//共享app指针
Application * Application::instance = 0;

Application::Application()
{
    ASSERT(instance==0,"instance 初值为0");
    instance = this;
}

Application::~Application()
{
    ASSERT(this == instance,"当前应用销毁");
    instance = nullptr;
}

Application* Application::getInstance()
{
    ASSERT(instance,"共享instance不为空");
    return instance;
}

//设置资源根目录
void Application::setResourceRootPath(const std::string& rootResDir)
{
    resourcepath = rootResDir;
}

//获取资源根目录
const std::string& Application::getResourceRootPath(void)
{
    return resourcepath;
}

int Application::run()
{
	//先初始化操作
	if (!init())
    {
        return 0;
    }
	//初始化绘画
	initgraph(Macros::screenSize.getX(), Macros::screenSize.getY(),SHOWCONSOLE);
    auto director = Director::getInstance();

	//开始批绘画
	BeginBatchDraw();

    while(true)
    {
            director->mainLoop();
			FlushBatchDraw();
			if(Macros::admin)
			{
				Sleep(Macros::sleep); //害得我帧率低 失误
				//清屏
				if(Macros::clear)
					cleardevice();
			}
			else
				cleardevice();//非管理员  每帧必清屏   
    }
	//结束批绘画
	EndBatchDraw();
	//关闭绘画
	closegraph();
	/*
    // Director should still do a cleanup if the window was closed manually.
    if (glview->isOpenGLReady())
    {
        director->end();
        director->mainLoop();
        director = nullptr;
    }
    glview->release();
	*/
    return true;
}
