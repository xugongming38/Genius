#include"log.h"

//1.日志调试函数
//自动换行版本
//使用举例{	Log("%s%d%s","sfnilkf",1,"fsdf");				}

void Logn(const char* format,...)
{
	if(!Macros::debug)
		return;
	char buff[1024];
	va_list list;
	va_start(list,format);
	vsnprintf_s(buff,1024,format,list);
	va_end(list);
	printf("%s\n",buff);
}

//非自动换行版本
void Log(const char* format,...)
{
	if(!Macros::debug)
		return;
	char buff[1024];
	va_list list;
	va_start(list,format);
	vsnprintf_s(buff,1024,format,list);
	va_end(list);
	printf("%s",buff);
}