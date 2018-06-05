#ifndef __AUDIOMANAGER_H__
#define __AUDIOMANAGER_H__

#include"../render/render.h"
#include"../math/math.h"
#include"../util/util.h"
#pragma comment(lib,"Winmm.lib")

//未考虑多线程效率
class AudioManager
{
private:
	//是否当前有背景音乐在播放
	bool isPlayBackAudio;
	//当前背景音乐路径
	string BackAudioPath;
public:
	AudioManager();
	~AudioManager();

	//单例模式
	static AudioManager* instance;
	static AudioManager* getInstance();

	//背景音乐默认循环播放
	bool playBackGroundAudio(string path);
	//暂停音乐播放
	bool pauseBackGroundAudio();
	//关闭音乐播放，并释放
	bool stopBackGroundAudio();

	//音效只播放一次（未考虑结束后的资源释放问题，后面事件分发再说）
	bool playEffect(string path);

	//返回当前是否有背景音乐存在（便于stop）
	bool isPlayBackGroundAudio();
};

#endif