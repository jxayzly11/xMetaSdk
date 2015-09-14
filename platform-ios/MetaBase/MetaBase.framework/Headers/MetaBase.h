//
//  MetaBase.h
//  MetaBase
//
//  Created by Allen Zeng on 15/7/29.
//  Copyright (c) 2015年 metafun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MobClick.h"
#import "Reachability.h"
#import "InvokeParam.h"

@interface MetaBase : NSObject

/********************** getParamsFrom Server *********************/

+(NSString*) getShareLink;

+(NSString*) getSharePic;

+(int) getRateExe;

+(int) getVideoVG;

+(int) getVideoAC;

+(NSString*) getVideoShow;

/********************** getParamsFrom Game *********************/
+(NSString*) getParamsFromGame:(NSString*)name;

@end
