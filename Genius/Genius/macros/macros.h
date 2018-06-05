#ifndef __MACROS_H__
#define __MACROS_H__

#include"../math/math.h"
class Macros
{
public:
	static bool debug;//是否开启调试
	static bool pause;//是否暂停
	static bool voice;//是否可以播放声音
	static Vec2 screenSize;//屏幕大小
	static bool admin;//管理员模式(用于操作清屏，休眠)
	static int sleep;
	static bool clear;
};
#endif
