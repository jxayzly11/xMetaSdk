//
//  MetaBase.h
//  MetaBase
//
//  Created by Allen Zeng on 15/7/29.
//  Copyright (c) 2015年 metafun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <MetaBase/Reachability.h>
#import <MetaBase/InvokeParam.h>
#import <MetaBase/UserAnalysis.h>
#import <MetaBase/GameStatistics.h>
#import <MetaBase/UMOnlineConfig.h>

@interface MetaBase : NSObject

@property (nonatomic, strong) UIViewController *gameController;

+ (MetaBase*) getInstance;

+ (void)initMeta:(UIViewController*) controller;

+ (UIViewController*) getController;

/********************** getParamsFrom Server *********************/

+ (NSString*) getShareLink;

+ (NSString*) getSharePic;

+ (int) getRateExe;

+ (BOOL) getMenuRateExe;

+ (NSMutableDictionary*) getVideoParams;

+ (NSMutableDictionary*) getRewardParams;

+ (NSMutableDictionary*) getParamsFromServer:(NSString*)name;

/********************** getParamsFrom Game *********************/
+ (NSString*) getParamsFromGame:(NSString*)name;

@end
