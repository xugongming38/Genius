#include"getcurrentdir.h"

string getCurrentDir()
{
	char buff[1000];
	_getcwd(buff, 1000);
	return string(buff);
}
