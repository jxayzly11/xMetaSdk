#ifndef __WIN32PLAT__
#define __WIN32PLAT__
#include "../MetaCocos.h"

class Win32Plat: public MetaCocos
{
public:
	Win32Plat(){};
	~Win32Plat(){};

	virtual void initPlat();

	virtual std::string invokeMeta(int type, std::string msg = "");
};

#endif