#ifndef __DIRECTOR_H__
#define __DIRECTOR_H__

#include"../2d/views.h"
#include"../math/math.h"
#include"eventdispatch\eventdispatch.h"
#include"schedule\schedule.h"

//暂时不加入自释放池
class Director
{
public:
	//单例模式
	static Director* instance;
	//两帧的间隔
	float deltaTime;
	//上次更新时间
	struct timeval * lastUpdate;

	//当前正在运行场景
	Scene* runningScene;
	//下一个运行场景，将取代当前场景
	Scene* nextScene;

	//场景栈
	vector<Scene*> scenesStack;

	//是否暂停
	bool paused;
	Scheduler *scheduler;
    EventDispatch* eventDispatch;

	int totalFrames;
	float totalTime;

public:
	//构造与析构
	Director();
	~Director();

	//单例模式
	static Director* getInstance();

	//初始化
	virtual bool init();
	//是否处于暂停状态
	inline bool isPaused() { return paused; }

	//场景相关
	//获取当前正在运行场景
	inline Scene* getRunningScene() { return runningScene; }
	void  setNextScene();

	//首个场景
	void runWithScene(Scene *scene);

	void pushScene(Scene *scene);

	void popScene();

	void replaceScene(Scene *scene);

	void end();

	void pause();

	void resume();
	//渲染部分（遍历UI树）
	void drawScene();

	//核心主循环，不打算作为虚函数
	virtual void mainLoop() ;

	//人体学输入事件探测（主要指鼠标 键盘）
	void DelectHIDEvent();

	//计算deltatime
	void calculateDeltaTime();
	float getDeltaTime() const;
};


#endif