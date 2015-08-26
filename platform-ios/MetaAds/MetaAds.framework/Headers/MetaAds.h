//
//  MetaApi.h
//  MetaAds
//
//  Created by Allen Zeng on 15/5/7.
//  Copyright (c) 2015年 metafun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#define BANNER_CENNER_TOP      0
#define BANNER_CENNER_BOTTOM   1

@interface MetaAds : NSObject

//初始化 Meta
+ (void) initMeta:(UIViewController*)controller removeAds:(BOOL)isRemove;

//在ViewController内调用
+ (void) viewWillAppear;

//在ViewController内调用
+ (void) viewWillDisappear;

//设置Load回调
+ (void)setLoadCallBack:(void(^)())callBack;

//隐藏banner
+ (void) hideBanner;

//显示banner，仅在调用hideBanner之后有效
+ (void) showBanner;

//设置banner条位置，在所有可能出现的地方都需要设置位置，否则保持上一个界面的位置
+ (void) setBannerPosition:(int) position;

//显示插屏广告
+ (void) showGameAd;

//显示MoreGames
+ (void) showMoreGames;

//获取nativeAd
+ (NSString*) nativeIconAdCache:(int)count;

//位置为index的icon被点击
+ (void) nativeIconAdClicked:(int)index;

//广告状态发生变化
+ (void) removeAdsChanged;

@end
