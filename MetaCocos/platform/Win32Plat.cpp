#include "Win32Plat.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)

void Win32Plat::initPlat()
{
	//do nothing
}

std::string Win32Plat::invokeMeta(int type, std::string msg)
{
	//do nothing
	return "win32";
}

#endif