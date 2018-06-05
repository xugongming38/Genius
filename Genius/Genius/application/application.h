#ifndef __APPLICATION_H__
#define __APPLICATION_H__
#include"../math/math.h"
#include"../control/control.h"

class Application
{
public:
	Application();
	virtual ~Application();

	//初始化，游戏逻辑要复写该方法
	virtual bool init() = 0;

	//核心循环
	int run();

	//单例模式
	static Application* getInstance();


	//设置资源路径相关
	void setResourceRootPath(const std::string& rootResDir);
	const std::string& getResourceRootPath(void);


protected:
	//应用name 暂时不提
	static Application * instance;
	string resourcepath;
};

#endif