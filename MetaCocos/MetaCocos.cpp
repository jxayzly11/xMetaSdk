//
//  MetaCocos.cpp
//
//  Created by vector on 15-4-3.
//  Modify by Allen Zeng on 15-6-17.
//
//

#include "MetaCocos.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    #include "platform/IOSPlat.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    #include "platform/AndroidPlat.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
    #include "platform/Win32Plat.h"
#endif

MetaCocos *sInsTance = nullptr;
std::function< std::string(int code, std::string msg)> gameSetFunc = nullptr;

MetaCocos* MetaCocos::getInstance() {
    if(sInsTance == nullptr) {
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        sInsTance = new IOSPlat();
	#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        sInsTance = new AndroidPlat();
	#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		sInsTance = new Win32Plat();
    #endif 
    }
    return sInsTance;
}

std::string onInvokeGame(int type, std::string msg) {
    std::string ret = "";
	if (gameSetFunc) {
		ret = gameSetFunc(type, msg);
	}
    return ret;
}

std::function<std::string(int code, std::string msg)> MetaCocos::getOnInvokeGame() {
    return onInvokeGame;
}

void MetaCocos::setOnInvokeGame(std::function< std::string(int code, std::string msg)> func) {
	gameSetFunc = func;
}