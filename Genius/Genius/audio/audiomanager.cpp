#include"audiomanager.h"

//����ģʽ
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
	//Ĭ�ϲ�����
	isPlayBackAudio=false;
	BackAudioPath="";
}
AudioManager::~AudioManager()
{
	//����б���������Դ�����ͷ�
	if(isPlayBackGroundAudio())
		stopBackGroundAudio();
}

//��������Ĭ��ѭ������(ע��·����ʽ)
bool AudioManager::playBackGroundAudio(string path)
{
	ASSERT(path!=string(""),"��������·����Ϊ��");
	Logn("����·��Ϊ [%s] �ı������� ",path.c_str());

	//�����ǰ�ı������֣���Ϊ��������Ĭ��ֻ����һ��
	stopBackGroundAudio();


	isPlayBackAudio=true;
	BackAudioPath=getCurrentDir()+path;


	char command[500];
	sprintf_s(command,"open \"D:\\VS2012_projecrs\\Genius\\Genius\\win32\\resource\\%s\"  alias backaudio",path.c_str());
	//��
	cout<<command<<endl;
	cout<<mciSendString(command, NULL, 0, NULL);
	//Sleep(1000);
	//����
	mciSendString(_T("play backaudio repeat"), NULL, 0, NULL);

	return true;
}

//��ͣ���ֲ���
bool AudioManager::pauseBackGroundAudio()
{
	ASSERT(isPlayBackGroundAudio()==true,"��ǰ�б��������ڲ���");
	Logn("��ͣ����·��Ϊ [%s] �ı������� ",BackAudioPath.c_str());

	if(isPlayBackGroundAudio())
		mciSendString(_T("stop backaudio"), NULL, 0, NULL);
	isPlayBackAudio=false;
	return true;
}

//�ر����ֲ��ţ����ͷ�
bool AudioManager::stopBackGroundAudio()
{
	if(BackAudioPath==string(""))
		return false;

	ASSERT(BackAudioPath!=string(""),"��ǰ�б���������Դ����");
	Logn("�رղ���·��Ϊ [%s] �ı������� ",BackAudioPath.c_str());


	//�����ڲ��ţ�������ͣ��Ȼ��ر�
	if(isPlayBackGroundAudio())
	{
		mciSendString(_T("stop backaudio"), NULL, 0, NULL);
		mciSendString(_T("close backaudio"), NULL, 0, NULL);
		isPlayBackAudio=false;
	}
	//��Ϊ�գ���˵���б�������ֻ�ǣ���ͣ��
	else if(BackAudioPath!=string(""))
	{
		//�رյ�ǰ·��
		mciSendString(_T("close backaudio"), NULL, 0, NULL);
		//���·��
		BackAudioPath="";
	}
	return true;
}

//��Чֻ����һ�Σ�δ���ǽ��������Դ�ͷ����⣬�����¼��ַ���˵��
bool AudioManager::playEffect(string path)
{
	ASSERT(path!=string(""),"��Ч����·����Ϊ��");
	Logn("����·��Ϊ [%s] ����Ч���� ",path.c_str());

	
	char command[50];
	sprintf_s(command,"open %s  alias effect",path.c_str());
	//��
	mciSendString(command, NULL, 0, NULL);
	//����
	mciSendString(_T("play effect from 0"), NULL, 0, NULL);
	return true;
}

//���ص�ǰ�Ƿ��б������ִ��ڣ�����stop��
bool AudioManager::isPlayBackGroundAudio()
{
	return isPlayBackAudio;
}