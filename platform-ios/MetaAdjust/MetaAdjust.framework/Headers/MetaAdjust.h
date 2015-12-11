//
//  tempelate.h
//  tempelate
//
//  Created by Allen Zeng on 15/7/2.
//  Copyright (c) 2015年 metafun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "Adjust.h"

@interface MetaAdjust : NSObject <AdjustDelegate>{
@private
    UIViewController *_controller;
}

@property (nonatomic, strong) UIViewController *controller;

+(void)initMeta:(UIViewController*) controller;

+(void)appWillOpenUrl:(NSURL *)url;

@end
