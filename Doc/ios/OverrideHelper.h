//
//  OverrideHelper.h
//  TowerWithFriends
//
//  Created by Allen Zeng on 15/7/22.
//
//

#import <Foundation/Foundation.h>

@interface OverrideHelper : NSObject

/**** RootViewController.mm 里面重写 ***/
+(void) viewWillAppear;

+(void) viewWillDisappear;



/**** AppController.mm 里面重写 ***/
+(void) application:(UIViewController*) controller;

+(void) applicationDidBecomeActive:(UIApplication *)application;

+(void) applicationWillTerminate:(UIApplication *)application;

+(BOOL) application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

+(BOOL) application:(UIApplication *)application handleOpenURL:(NSURL *)url;


@end
