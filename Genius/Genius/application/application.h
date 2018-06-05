#ifndef __APPLICATION_H__
#define __APPLICATION_H__
#include"../math/math.h"
#include"../control/control.h"

class Application
{
public:
	Application();
	virtual ~Application();

	//��ʼ������Ϸ�߼�Ҫ��д�÷���
	virtual bool init() = 0;

	//����ѭ��
	int run();

	//����ģʽ
	static Application* getInstance();


	//������Դ·�����
	void setResourceRootPath(const std::string& rootResDir);
	const std::string& getResourceRootPath(void);


protected:
	//Ӧ��name ��ʱ����
	static Application * instance;
	string resourcepath;
};

#endif