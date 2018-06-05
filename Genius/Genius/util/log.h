#ifndef __LOG_H__
#define __LOG_H__

#include"../base/base.h"
#include"../macros/macros.h"
//1.日志调试函数

//自动换行版本
void Logn(const char* format,...);
//非自动换行版本
void Log(const char* format,...);

#endif