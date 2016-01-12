#ifndef __WIN32PLAT__
#define __WIN32PLAT__
#include "../MetaUnity.h"

class DefaultPlat: public MetaUnity
{
public:
	DefaultPlat(){};
	~DefaultPlat(){};

	virtual void initPlat();

	virtual std::string invokeMeta(int type, std::string msg = "");
};

#endif