#ifndef __DIRECTOR_H__
#define __DIRECTOR_H__

#include"../2d/views.h"
#include"../math/math.h"
#include"eventdispatch\eventdispatch.h"
#include"schedule\schedule.h"

//��ʱ���������ͷų�
class Director
{
public:
	//����ģʽ
	static Director* instance;
	//��֡�ļ��
	float deltaTime;
	//�ϴθ���ʱ��
	struct timeval * lastUpdate;

	//��ǰ�������г���
	Scene* runningScene;
	//��һ�����г�������ȡ����ǰ����
	Scene* nextScene;

	//����ջ
	vector<Scene*> scenesStack;

	//�Ƿ���ͣ
	bool paused;
	Scheduler *scheduler;
    EventDispatch* eventDispatch;

	int totalFrames;
	float totalTime;

public:
	//����������
	Director();
	~Director();

	//����ģʽ
	static Director* getInstance();

	//��ʼ��
	virtual bool init();
	//�Ƿ�����ͣ״̬
	inline bool isPaused() { return paused; }

	//�������
	//��ȡ��ǰ�������г���
	inline Scene* getRunningScene() { return runningScene; }
	void  setNextScene();

	//�׸�����
	void runWithScene(Scene *scene);

	void pushScene(Scene *scene);

	void popScene();

	void replaceScene(Scene *scene);

	void end();

	void pause();

	void resume();
	//��Ⱦ���֣�����UI����
	void drawScene();

	//������ѭ������������Ϊ�麯��
	virtual void mainLoop() ;

	//����ѧ�����¼�̽�⣨��Ҫָ��� ���̣�
	void DelectHIDEvent();

	//����deltatime
	void calculateDeltaTime();
	float getDeltaTime() const;
};


#endif