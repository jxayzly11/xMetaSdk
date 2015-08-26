//
//  SocialHelper.h
//  Vplatform
//
//  Created by vector on 14-6-24.
//  Copyright (c) 2014年 vector. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GameKit/GameKit.h>
#import <Social/Social.h>
#import <StoreKit/StoreKit.h>

@interface SocialHelper : NSObject <GKLeaderboardViewControllerDelegate,
UIAlertViewDelegate,
SKStoreProductViewControllerDelegate>{
    
}

@property (nonatomic, strong) UIViewController *control;

@property (nonatomic, strong) NSString         *productID;

@property (nonatomic, assign) BOOL             isLoginSuccess;

- (void) initHelper: (UIViewController*) control productID: (NSString*) productID;

- (void) reportScore: (int64_t) score forCategory: (NSString*) category;

- (void) reportArchivement: (int64_t) point forIndentifier: (NSString*) indentifier;

- (void) moreGame: (NSString*) link;

- (void) showRank: (NSString*) categroy;

- (void) showShare: (NSString*) text img: (NSString*) img;

- (void) showRate;

- (void) showPrayRate: (NSString*) title text: (NSString*) text btnOK: (NSString*) btnOK btnNO: (NSString*) btnNO;

- (void) faceBookLike: (NSString*) home;

- (void) twitterFollow: (NSString*) home;

- (void) faceBookShare:(NSString*) shareTx imgPath:(NSString*) path shareUrl:(NSString*)url callBack:(void(^)(BOOL)) block;

- (void) twitterShare:(NSString*) shareTx imgPath:(NSString*) path shareUrl:(NSString*)url callBack:(void(^)(BOOL)) block;
@end