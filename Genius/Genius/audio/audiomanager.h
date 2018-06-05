#ifndef __AUDIOMANAGER_H__
#define __AUDIOMANAGER_H__

#include"../render/render.h"
#include"../math/math.h"
#include"../util/util.h"
#pragma comment(lib,"Winmm.lib")

//δ���Ƕ��߳�Ч��
class AudioManager
{
private:
	//�Ƿ�ǰ�б��������ڲ���
	bool isPlayBackAudio;
	//��ǰ��������·��
	string BackAudioPath;
public:
	AudioManager();
	~AudioManager();

	//����ģʽ
	static AudioManager* instance;
	static AudioManager* getInstance();

	//��������Ĭ��ѭ������
	bool playBackGroundAudio(string path);
	//��ͣ���ֲ���
	bool pauseBackGroundAudio();
	//�ر����ֲ��ţ����ͷ�
	bool stopBackGroundAudio();

	//��Чֻ����һ�Σ�δ���ǽ��������Դ�ͷ����⣬�����¼��ַ���˵��
	bool playEffect(string path);

	//���ص�ǰ�Ƿ��б������ִ��ڣ�����stop��
	bool isPlayBackGroundAudio();
};

#endif