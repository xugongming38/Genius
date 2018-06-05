#include"string2LPCTSTR.h"

/*
LPCTSTR string2PCTSTR(string s)
{
	
	int len;
	int slength = (int)s.length() + 1;
	 len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	 wchar_t* buf = new wchar_t[len];
	 MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	 std::wstring r(buf);
	 delete[] buf;
	 //¼´µÃ½á¹û
	 return r.c_str();
}
*/
