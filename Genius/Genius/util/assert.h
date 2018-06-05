#ifndef __ASSERT_H__
#define __ASSERT_H__

#include"log.h"

#define ASSERT(condition,msg) do{	\
	if(!(condition))				\
		Logn("Assert failed! [%s] ",msg);\
}while(0)


#endif