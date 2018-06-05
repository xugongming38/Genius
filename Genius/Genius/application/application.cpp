#include"application.h"
#include"../util/util.h"
//����appָ��
Application * Application::instance = 0;

Application::Application()
{
    ASSERT(instance==0,"instance ��ֵΪ0");
    instance = this;
}

Application::~Application()
{
    ASSERT(this == instance,"��ǰӦ������");
    instance = nullptr;
}

Application* Application::getInstance()
{
    ASSERT(instance,"����instance��Ϊ��");
    return instance;
}

//������Դ��Ŀ¼
void Application::setResourceRootPath(const std::string& rootResDir)
{
    resourcepath = rootResDir;
}

//��ȡ��Դ��Ŀ¼
const std::string& Application::getResourceRootPath(void)
{
    return resourcepath;
}

int Application::run()
{
	//�ȳ�ʼ������
	if (!init())
    {
        return 0;
    }
	//��ʼ���滭
	initgraph(Macros::screenSize.getX(), Macros::screenSize.getY(),SHOWCONSOLE);
    auto director = Director::getInstance();

	//��ʼ���滭
	BeginBatchDraw();

    while(true)
    {
            director->mainLoop();
			FlushBatchDraw();
			if(Macros::admin)
			{
				Sleep(Macros::sleep); //������֡�ʵ� ʧ��
				//����
				if(Macros::clear)
					cleardevice();
			}
			else
				cleardevice();//�ǹ���Ա  ÿ֡������   
    }
	//�������滭
	EndBatchDraw();
	//�رջ滭
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
