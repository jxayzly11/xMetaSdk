//
//  MetaBase.h
//  MetaBase
//
//  Created by Allen Zeng on 15/7/29.
//  Copyright (c) 2015年 metafun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MetaBase/MobClick.h>
#import <MetaBase/Reachability.h>
#import <MetaBase/InvokeParam.h>
#import <MetaBase/UserAnalysis.h>


@interface MetaBase : NSObject

@property (nonatomic, strong) UIViewController *gameController;

+ (MetaBase*) getInstance;

+ (void)initMeta:(UIViewController*) controller;

+ (UIViewController*) getController;

/********************** getParamsFrom Server *********************/

+ (NSString*) getShareLink;

+ (NSString*) getSharePic;

+ (int) getRateExe;

+ (NSMutableDictionary*) getVideoParams;

+ (NSMutableDictionary*) getRewardParams;

+ (NSMutableDictionary*) getParamsFromServer:(NSString*)name;

/********************** getParamsFrom Game *********************/
+ (NSString*) getParamsFromGame:(NSString*)name;

@end
