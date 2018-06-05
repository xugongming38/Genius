#ifndef __CREATE_H__
#define __CREATE_H__

// static createºê¶¨Òå
#define CREATE( TYPE) \
static TYPE * create() \
{ \
	TYPE * ret = new TYPE();\
	if(ret&&ret->init())\
	{\
		ret->autorelease();\
		return ret;\
	}else\
	{\
		return nullptr;\
	}\
}                                


#endif