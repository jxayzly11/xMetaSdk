//
//  OverrideHelper.m
//  TowerWithFriends
//
//  Created by Allen Zeng on 15/7/22.
//
//

#import "OverrideHelper.h"
#import "MetaCocos.h"
#if(SDK_METAADS == SDK_OPEN)
#import <MetaAds/MetaAds.h>
#endif
#if(SDK_METAPLATFORM == SDK_OPEN)
#import <MetaPlatform/MetaPlatform.h>
#endif
#if(SDK_METAVIDEO == SDK_OPEN)
#import <MetaVideo/MetaVideo.h>
#endif
#if(SDK_METAFACEBOOK == SDK_OPEN)
#import <MetaFacebook/MetaFacebook.h>
#endif

@implementation OverrideHelper

+(void) viewWillAppear{
#if(SDK_METAADS == SDK_OPEN)
    [MetaAds viewWillAppear];
#endif
}

+(void) viewWillDisappear{
#if(SDK_METAADS == SDK_OPEN)
    [MetaAds viewWillDisappear];
#endif
}

+(void) application:(UIViewController*) controller{
    MetaCocos::getInstance()->initMeta(controller);
}

+(void)applicationDidBecomeActive:(UIApplication *)application{
#if(SDK_METAFACEBOOK == SDK_OPEN)
    [MetaFacebook applicationDidBecomeActive:application];
#endif
}

+(void) applicationWillTerminate:(UIApplication *)application{
#if(SDK_METAFACEBOOK == SDK_OPEN)
    [MetaFacebook applicationWillTerminate:application];
#endif
}

+(BOOL) application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation{
#if(SDK_METAFACEBOOK == SDK_OPEN)
    return [MetaFacebook application:application openURL:url sourceApplication:sourceApplication annotation:annotation];
#endif
    return YES;
}

+(BOOL) application:(UIApplication *)application handleOpenURL:(NSURL *)url{
#if(SDK_METAFACEBOOK == SDK_OPEN)
    return [MetaFacebook application:application handleOpenURL:url];
#endif
    return YES;
}

@end
