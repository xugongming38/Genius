#include"audiomanager.h"

//单例模式
AudioManager* AudioManager::instance=nullptr;

AudioManager* AudioManager::getInstance()
{
    if (instance == nullptr)
    {
        instance = new AudioManager();
    }
    return instance;
}

AudioManager::AudioManager()
{
	//默认不播放
	isPlayBackAudio=false;
	BackAudioPath="";
}
AudioManager::~AudioManager()
{
	//如过有背景音乐资源，就释放
	if(isPlayBackGroundAudio())
		stopBackGroundAudio();
}

//背景音乐默认循环播放(注意路径格式)
bool AudioManager::playBackGroundAudio(string path)
{
	ASSERT(path!=string(""),"背景音乐路径不为空");
	Logn("播放路径为 [%s] 的背景音乐 ",path.c_str());

	//清空以前的背景音乐，因为背景音乐默认只能有一个
	stopBackGroundAudio();


	isPlayBackAudio=true;
	BackAudioPath=getCurrentDir()+path;


	char command[500];
	sprintf_s(command,"open \"D:\\VS2012_projecrs\\Genius\\Genius\\win32\\resource\\%s\"  alias backaudio",path.c_str());
	//打开
	cout<<command<<endl;
	cout<<mciSendString(command, NULL, 0, NULL);
	//Sleep(1000);
	//播放
	mciSendString(_T("play backaudio repeat"), NULL, 0, NULL);

	return true;
}

//暂停音乐播放
bool AudioManager::pauseBackGroundAudio()
{
	ASSERT(isPlayBackGroundAudio()==true,"当前有背景音乐在播放");
	Logn("暂停播放路径为 [%s] 的背景音乐 ",BackAudioPath.c_str());

	if(isPlayBackGroundAudio())
		mciSendString(_T("stop backaudio"), NULL, 0, NULL);
	isPlayBackAudio=false;
	return true;
}

//关闭音乐播放，并释放
bool AudioManager::stopBackGroundAudio()
{
	if(BackAudioPath==string(""))
		return false;

	ASSERT(BackAudioPath!=string(""),"当前有背景音乐资源存在");
	Logn("关闭播放路径为 [%s] 的背景音乐 ",BackAudioPath.c_str());


	//若正在播放，则先暂停，然后关闭
	if(isPlayBackGroundAudio())
	{
		mciSendString(_T("stop backaudio"), NULL, 0, NULL);
		mciSendString(_T("close backaudio"), NULL, 0, NULL);
		isPlayBackAudio=false;
	}
	//不为空，则说明有背景音乐只是，暂停了
	else if(BackAudioPath!=string(""))
	{
		//关闭当前路径
		mciSendString(_T("close backaudio"), NULL, 0, NULL);
		//清空路径
		BackAudioPath="";
	}
	return true;
}

//音效只播放一次（未考虑结束后的资源释放问题，后面事件分发再说）
bool AudioManager::playEffect(string path)
{
	ASSERT(path!=string(""),"特效音乐路径不为空");
	Logn("播放路径为 [%s] 的特效音乐 ",path.c_str());

	
	char command[50];
	sprintf_s(command,"open %s  alias effect",path.c_str());
	//打开
	mciSendString(command, NULL, 0, NULL);
	//播放
	mciSendString(_T("play effect from 0"), NULL, 0, NULL);
	return true;
}

//返回当前是否有背景音乐存在（便于stop）
bool AudioManager::isPlayBackGroundAudio()
{
	return isPlayBackAudio;
}