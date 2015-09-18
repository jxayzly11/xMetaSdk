#include "AndroidPlat.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include <android/log.h>


#define RegistInvokeGame(name) JNIEXPORT jstring JNICALL name \
(JNIEnv *env, jclass jclass, jint type, jstring jmsg) \
{ \
    if (jmsg==NULL) \
    { \
        return env->NewStringUTF(""); \
    } \
    jboolean isCp; \
    std::string ret = ""; \
    std::string recStr = ""; \
    recStr = (std::string)env->GetStringUTFChars(jmsg, &isCp); \
    env->DeleteLocalRef(jmsg); \
    ret = AndroidPlat::getInstance()->getOnInvokeGame()(type, recStr); \
    return env->NewStringUTF(ret.c_str()); \
}

#ifdef __cplusplus
extern "C" {
#endif

//regist callback function
#if (SDK_METAADS == SDK_OPEN)
    RegistInvokeGame(Java_com_metafun_metaads_MetaAds_invokeGame)
#endif
#if (SDK_METAPLATFORM == SDK_OPEN)
    RegistInvokeGame(Java_com_metafun_metaplatform_MetaPlatform_invokeGame)
#endif
#if (SDK_METAVIDEO == SDK_OPEN)
    RegistInvokeGame(Java_com_metafun_metavideo_MetaVideo_invokeGame)
#endif
#if (SDK_METAFACEBOOK == SDK_OPEN)
    RegistInvokeGame(Java_com_metafun_metafacebook_MetaFacebook_invokeGame)
#endif

std::string invokeJFunc(std::string funcPath, std::string funcName, int type, std::string msg)
{
    std::string ret = "";
    //函数信息结构体
    cocos2d::JniMethodInfo minfo;
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,/*JniMethodInfo的引用*/
                                                          funcPath.c_str(),//"com/metafun/sdk",/*类的路径*/
                                                          funcName.c_str(),//"invokePlat",/*函数名*/
                                                          "(ILjava/lang/String;)Ljava/lang/String;");/*函数类型简写*/
    jstring jretMsg;
    jstring jsendMsg;
    if(isHave){
        //CallStaticObjectMethod调用java函数，并把返回值赋值给activityObj
        jsendMsg = minfo.env->NewStringUTF(msg.c_str());
        jretMsg = (jstring)minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID, type, jsendMsg);
        minfo.env->DeleteLocalRef(jsendMsg);
        minfo.env->DeleteLocalRef(minfo.classID);
        if(jretMsg != NULL){
            jboolean isCp;
            ret = (std::string)minfo.env->GetStringUTFChars(jretMsg, &isCp);
            minfo.env->DeleteLocalRef(jretMsg);
        }
    } 
    return ret; 
}
    
#ifdef __cplusplus
}
#endif

void AndroidPlat::initMeta(void* meta) {
	//do nothing
}

std::string AndroidPlat::invokeMeta(int type, std::string msg) {
    std::string ret;
    #define RETURN_INVOKEJFUNC(funcPath, funcName) ret = invokeJFunc(funcPath, funcName, type, msg); \
    if(strcmp(ret.c_str(), "") != 0){ \
        return ret;\
    }
//优先判断是否Rate，然后判断是否显示Video，然后判断Ads计数
#if(SDK_METAPLATFORM == SDK_OPEN)
    RETURN_INVOKEJFUNC("com/metafun/metaplatform/MetaPlatform", "invokePlat")
#endif
#if(SDK_METAVIDEO == SDK_OPEN)
    RETURN_INVOKEJFUNC("com/metafun/metavideo/MetaVideo", "invokePlat")
#endif
#if(SDK_METAADS == SDK_OPEN)
    RETURN_INVOKEJFUNC("com/metafun/metaads/MetaAds", "invokePlat")
#endif
#if(SDK_METAFACEBOOK == SDK_OPEN)
    RETURN_INVOKEJFUNC("com/metafun/metafacebook/MetaFacebook", "invokePlat")
#endif
    
	return "";
}

#endif
 