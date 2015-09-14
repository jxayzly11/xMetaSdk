//
//  MetaReplay.h
//  MetaReplay
//
//  Created by Allen Zeng on 15/9/9.
//  Copyright (c) 2015年 metafun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Everyplay/Everyplay.h>

typedef NSString*(^InvokeGameCallBack)(NSNumber*, NSString*);

@interface MetaReplay : NSObject <EveryplayDelegate>{
@private
    UIViewController *_controller;
    InvokeGameCallBack _invokeGameCallBack;
}

@property (nonatomic, strong) UIViewController *controller;

@property (nonatomic, strong) InvokeGameCallBack invokeGameCallBack;

+(void)initMeta:(UIViewController*) controller;

+(void)registerOnInvokeGame:(InvokeGameCallBack) callback;

+(void)autoRecordForSeconds:(NSInteger) tim;

+(void)startRecord;

+(void)pauseRecord;

+(void)resumeRecord;

+(void)stopRecord;

+(void)playLastRecord;

@end
