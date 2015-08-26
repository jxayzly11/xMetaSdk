//
//  MetaConfig.h
//
//  Created by Allen Zeng on 15-6-17.
//
//

#ifndef __METACONFIG__
#define __METACONFIG__

#define SDK_OFF         0x00
#define SDK_OPEN        0x01

#define SDK_METAADS        SDK_OPEN        //是否使用广告组件
#define SDK_METAPLATFORM   SDK_OPEN        //是否使用平台组件
#define SDK_METAVIDEO      SDK_OPEN        //是否使用视频组件
#define SDK_METAFACEBOOK   SDK_OPEN        //是否使用facebook组建

#include "cocos2d.h"

#endif /* defined(__METACONFIG__) */