//
//  GameStatistics.h
//  MetaBase
//
//  Created by Allen Zeng on 16/6/2.
//  Copyright © 2016年 metafun. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GameStatistics : NSObject

+ (void)init;

//计数事件
+ (void)addEvent:(NSString*)event;

//计算事件
+ (void)addEventCount:(NSString*)event count:(int)num;

//关卡统计，开始
+ (void)startLevel:(NSString*)level;

//关卡统计，失败
+ (void)failLevel:(NSString*)level;

//关卡统计，结束
+ (void)finishLevel:(NSString*)level;

@end
