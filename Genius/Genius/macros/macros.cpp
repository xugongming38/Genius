#include"macros.h"

//默认为调试模式
 bool Macros::debug=true;

 //默认为非暂停
 bool Macros::pause=false;

 //默认打开声音
 bool Macros::voice=true;

 //默认为0，所以开始必须自动设置
 Vec2 Macros::screenSize=0;

 //管理员模式(用于操作清屏，休眠)
bool Macros::admin=false;
int Macros::sleep=0;
bool Macros::clear=true;