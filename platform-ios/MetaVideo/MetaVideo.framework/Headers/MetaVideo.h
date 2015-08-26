//
//  MetaApi.h
//  MetaVideo
//
//  Created by Allen Zeng on 15/7/4.
//  Copyright (c) 2015年 metafun. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@interface MetaVideo : NSObject

//初始化 Meta
+ (void) initMeta:(UIViewController*)controller removeAds:(BOOL)isRemove;

+ (BOOL) isVideoReady;

+ (void) showVideo;

+ (BOOL) isVideoRewardReady;

+ (void) showRewardVideo;

+ (void) setWatchCallBack:(void(^)(bool))callBack;

+ (BOOL) getShowVideo;

+ (void) removeAdsChanged;

@end
