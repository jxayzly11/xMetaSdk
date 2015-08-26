#ifndef __IOSPLAT__
#define __IOSPLAT__
#include <iostream>
#include "../MetaCocos.h"

class IOSPlat: public MetaCocos
{
private:
    int overTimes;
    int puaseTimes;
    int setOverTimes;
    int setPuaseTimes;
    
public: 
    IOSPlat(){};
    ~IOSPlat(){};
    
    virtual void initMeta(void* meta);

    virtual std::string invokeMeta(int type, std::string msg = "");
};

#endif /* defined(__IOSPLAT__) */
