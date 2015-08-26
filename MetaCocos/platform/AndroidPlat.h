#ifndef __ANDROIDPLAT__
#define __ANDROIDPLAT__
#include "../MetaCocos.h"

class AndroidPlat: public MetaCocos
{  
public:
	AndroidPlat(){};
	~AndroidPlat(){};
    
    virtual void initMeta(void* meta);
    
	virtual std::string invokeMeta(int type, std::string msg = "");
};

#endif
