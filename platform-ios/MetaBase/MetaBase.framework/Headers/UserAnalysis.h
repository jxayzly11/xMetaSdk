//
//  UserAnalysis.h
//  MetaAds
//
//  Created by Allen Zeng on 15/5/8.
//  Copyright (c) 2015年 metafun. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UserAnalysis : NSObject

+ (UserAnalysis *) getInstance;

- (void)initHelper;

- (NSDate*) getInstallDate;

- (NSString*) getUserLanguage;

- (NSString*)getUserType;

- (NSString*)getUserConnectionType;


@end
