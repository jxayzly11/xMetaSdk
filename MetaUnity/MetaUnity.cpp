//
//  MetaUnity.cpp
//
//  Created by vector on 15-4-3.
//  Modify by Allen Zeng on 15-6-17.
//
//

#include "MetaUnity.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    #include "platform/IOSPlat.h"
#else 
    #include "platform/DefaultPlat.h"
#endif

MetaUnity *sInsTance = nullptr;
std::function< std::string(int code, std::string msg)> gameSetFunc = nullptr;

MetaUnity* MetaUnity::getInstance() {
    if(sInsTance == nullptr) {
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        sInsTance = new IOSPlat();
    #else
        sInsTance = new DefaultPlat();
    #endif 
    }
    return sInsTance;
}

std::string sendMessageToUnity(int type, std::string msg){
    char param[64] = {0};
    sprintf(param, "%d,%s", type, msg.c_str());
    UnitySendMessage("MetaUnity", "invokeCallback", param);
    return "";
}

std::function<std::string(int code, std::string msg)> MetaUnity::getOnInvokeGame() {
    return sendMessageToUnity;
}

// oc code called by unity c#, added by luxiao @2015.9.29
#if defined (__cplusplus)
extern "C"
{
#endif
    char* _invokeMeta(int type, const char* msg){
        printf ("type=%d, %s", type, msg);
        
        std::string str = sInsTance->invokeMeta(type, msg);
        
        char* ret = (char*)malloc(str.length()+1);
        strcpy(ret, str.c_str());
        return ret;
    }
    
#if defined (__cplusplus)
} // extern "C"
#endif
// end added
