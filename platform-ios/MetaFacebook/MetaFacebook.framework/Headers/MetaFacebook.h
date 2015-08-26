//
//  MetaFB
//
//  Created by vector on 15-7-8.
//  Copyright (c) 2015年 vector. All rights reserved.
//
#include <FacebookSDK/FacebookSDK.h>
#import "ImageFetcherDelegate.h"
#import "ImageFetcher.h"

#define APP_HANDLED_URL @"APP_HANDLED_URL"

@interface MetaFacebook: NSObject<ImageFetcherDelegate>{
@private
    UIViewController *_controller;
    ImageFetcher     *_imgFetcher;
    NSString* _ms_nsstrFirstName;
    NSString* _ms_uPlayerFBID;
    BOOL _ms_bIsLoggedIn;
    FBFrictionlessRecipientCache* _ms_friendCache;
}

@property (nonatomic, strong) UIViewController *controller;
@property (nonatomic, strong) ImageFetcher *imgFetcher;
@property (nonatomic, strong) NSString*(^afterDownload)(int, NSString*);
@property (nonatomic, strong) NSString* ms_nsstrFirstName;
@property (nonatomic, strong) NSString* ms_uPlayerFBID;
@property (nonatomic, assign) BOOL ms_bIsLoggedIn;
@property (nonatomic, strong) FBFrictionlessRecipientCache* ms_friendCache;


+(void)initMeta:(UIViewController*) controller;

+(void)registMetaAfterDownload:(NSString*(^)(int, NSString*)) block;

+(BOOL)application:(UIApplication *)application openURL:(NSURL *)url
  sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

+(BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url;

+(void)applicationDidBecomeActive:(UIApplication *)application;

+(void)applicationWillTerminate:(UIApplication *)application;

#pragma mark - headImagdownload -

+(void)addImageDownloadEvent:(NSString*) uid;

+(NSString*)getImagePath:(NSString*) uid;

#pragma mark - facebook -
+(void)CreateNewSession;

+(void)Login:(void(^)(bool)) callback;
+(void)OpenSession:(void(^)(bool)) callback;
+(void)Logout:(void(^)(bool)) callback;

+(void)CheckForPermission:(NSString*) permission callBack:(void(^)(bool)) callback;
+(BOOL)IsLoggedIn;

// Method for forcing this in the case of a login powered by parse
+(void)SetLoggedIn:(BOOL)isLoggin;

+(void)FetchUserDetails:(void(^)(bool)) callback;
+(void)FetchFriendDetails:(void(^)(NSArray*)) callback;
+(void)FetchInvitableFriendDetails:(void(^)(NSArray*)) callback;

+(void)ProcessIncomingURL:(NSURL*) targetURL callback:(void(^)(NSString*, NSString*)) callback;
+(void)ProcessIncomingRequest:(NSURL*) targetURL callback:(void(^)(NSString*, NSString*)) callback;
+(void)ProcessIncomingFeed:(NSURL*) targetURL callback:(void(^)(NSString*, NSString*)) callback;

+(void)SendInvite:(NSArray*) friendIDs callback:(void(^)(NSArray*)) callback;
+(void)SendRequest:(NSArray*) friendIDs score:(int)nScore;

+(void)SendFilteredRequest:(int) nScore;
+(void)SendLinkShare:(NSString*) linkDescription linkName:(NSString*)name callback:(void(^)(bool)) callback;
+(void)SendPhotoShare:(NSString*) description picPath:(NSString*) picPath callback:(void(^)(bool)) callback;
+(void)SendScore:(int) nScore;
+(void)SendAchievement:(NSString*) achievement;
+(void)GetScores:(void(^)(NSArray*)) callback;

+(void)LogCustomAppEvent:(int) nScore;

+(void)RequestWritePermissions;
+(void)ReRequestFriendPermission;

+(NSString*) GetUserFirstName;
+(NSString*) GetUserFBID;


@end
