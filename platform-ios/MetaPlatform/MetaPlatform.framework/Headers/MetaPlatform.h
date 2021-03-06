//
//  PlatformController.h
//  platform
//
//  Created by vector on 14-2-17.
//  Copyright (c) 2014年 vector. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SocialHelper.h"
#import "IAPHelper.h"

typedef NSString*(^InvokeGameCallBack)(NSNumber*, NSString*);

@interface MetaPlatform : NSObject<IAPHelperDelegate>{
    @private
        UIViewController *_controller;
        SocialHelper     *_socialHelper;
        IAPHelper        *_iapHelper;
        UIActivityIndicatorView *_activityIndicator;
        InvokeGameCallBack _invokeGameCallBack;
}

@property (nonatomic, strong) UIViewController *controller;

@property (nonatomic, strong) SocialHelper  *socialHelper;

@property (nonatomic, strong) IAPHelper     *iapHelper;

@property (nonatomic, strong) UIActivityIndicatorView *activityIndicator;

@property (nonatomic, strong) InvokeGameCallBack invokeGameCallBack;

+(void)initMeta:(UIViewController*) controller;

+(void)registerOnInvokeGame:(InvokeGameCallBack) callback;

#pragma mark - purchase -

+(void)buy:(NSString*) productName ;

+(void)restore;

#pragma mark - baseSocial -

+(NSString*)getShareLink;

+(NSString*)getItemByKey:(NSString*) key;

+(NSString*) getUserName;

+(void) getScore: (NSString*) leaderboardID callBack:(void(^)(NSString*)) block;

+(void)uploadScore:(int64_t) score category:(NSString*)category;

+(void)uploadArchivement: (int64_t) point indentifier: (NSString*) indentifier;

+(void)moreGame;

+(void)showRank:(NSString*) categroy;

+(void)showAchievement;

+(void)showRate;

+(void)showShare:(NSString*) text img:(NSString*)img;

+(void)faceBookLike;

+(void)twitterFollow;

+(void)faceBookShare:(NSString*) shareTx imgPath:(NSString*) path callBack:(void(^)(BOOL)) block;

+(void)twitterShare:(NSString*) shareTx imgPath:(NSString*) path callBack:(void(^)(BOOL)) block;

+(NSString*)getIemiKey;

+(void)writePlatConfig:(NSString*)key value:(NSString*) value;

+(NSString*)readPlatConfig:(NSString*)key defaultValue:(NSString*) value;

+(void)Vibrate:(int)tim;

+(NSString*)getClipboard;

+(BOOL)getIsChineseUser;

+(BOOL)getIsOpenMenuRate;

+(BOOL)getIsPopRate;

+(void)unscheduleLocalNotification:(NSString*)key;

+(void)scheduleLocalNotification:(NSString*)key
                         content:(NSString*)content
                        delayTim:(NSInteger)delayTim
                       repeatTim:(NSCalendarUnit)repeatTim
                       badgeNum:(NSInteger)badgeNum;

#pragma mark - uiContorl -

-(void)releaseIndicator;

-(void)newIndicator;

@end
