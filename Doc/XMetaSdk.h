//
//  XMetaSdk.h
//  Herd
//
//  Created by Allen Zeng on 16/1/13.
//
//

#ifndef XMetaSdk_h
#define XMetaSdk_h

#define SDK_OFF         0x00
#define SDK_OPEN        0x01

#define SDK_METAADS        SDK_OPEN        //是否使用广告组件
#define SDK_METAPLATFORM   SDK_OPEN        //是否使用平台组件
#define SDK_METAVIDEO      SDK_OPEN        //是否使用视频组件
#define SDK_METAFACEBOOK   SDK_OPEN        //是否使用facebook组件
#define SDK_METAREPLAY     SDK_OFF         //是否使用游戏视频记录组件
#define SDK_ADJUST         SDK_OPEN        //分析和广告推送挂载组建

#endif /* XMetaSdk_h */
