#include"log.h"

//1.��־���Ժ���
//�Զ����а汾
//ʹ�þ���{	Log("%s%d%s","sfnilkf",1,"fsdf");				}

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

//���Զ����а汾
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