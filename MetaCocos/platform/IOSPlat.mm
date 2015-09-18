#include "IOSPlat.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

#import <UIKit/UIKit.h>
#import <MetaBase/MetaBase.h>

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
#if(SDK_METAREPLAY == SDK_OPEN)
    #import <MetaReplay/MetaReplay.h>
#endif

void IOSPlat::initMeta(void* meta){
    overTimes=0;
    puaseTimes=0;
    setOverTimes = [[MetaBase getParamsFromGame:PRODUCT_ADTIME_OVER] intValue];
    setPuaseTimes = [[MetaBase getParamsFromGame:PRODUCT_ADTIME_PUASE] intValue];
    
    UIViewController* viewController = (__bridge UIViewController*)meta;
    
    BOOL isRemoveAds = NO;
    
    [MetaBase initMeta:viewController];
    
#if(SDK_METAPLATFORM == SDK_OPEN)
    [MetaPlatform initMeta:viewController];
    isRemoveAds = ([[MetaPlatform readPlatConfig:@"mp_sob" defaultValue:@"false"] compare:@"true"] == NSOrderedSame);
#endif
    
#if(SDK_METAADS == SDK_OPEN)
    [MetaAds initMeta:viewController removeAds:isRemoveAds];
#endif
    
#if(SDK_METAVIDEO == SDK_OPEN)
    [MetaVideo initMeta:viewController removeAds:isRemoveAds];
#endif
    
#if(SDK_METAFACEBOOK == SDK_OPEN)
    [MetaFacebook initMeta:viewController];
#endif
    
#if (SDK_METAREPLAY == SDK_OPEN)
    [MetaReplay initMeta:viewController];
#endif
}

std::string IOSPlat::invokeMeta(int type, std::string msg){
    id(^parseJson)(std::string)  = ^id(std::string srcJson){
        NSString* msgStr= [NSString stringWithCString:srcJson.c_str() encoding:[NSString defaultCStringEncoding]];
        NSData* msgData = [msgStr dataUsingEncoding:NSUTF8StringEncoding];
        return [NSJSONSerialization JSONObjectWithData:msgData options:NSJSONReadingAllowFragments error:nil];
    };
    NSString*(^toJsonString)(id) = ^NSString*(id src){
        NSData *jsonData = [NSJSONSerialization dataWithJSONObject:src options:NSJSONWritingPrettyPrinted error:nil];
        return [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
    };
    
    switch (type) {
    #if(SDK_METAADS == SDK_OPEN) 
        case MA_SETADLOAD:
            [MetaAds setLoadCallBack:^(){getOnInvokeGame()(MA_SETADLOAD,"");}];
            break;
        case MA_HIDEBANNER:
            [MetaAds hideBanner];
            break;
        case MA_SHOWBANNER:
            [MetaAds showBanner];
            break;
        case MA_BANNERPOSITION:
            if(msg==MA_BANNER_CENNER_BOTTOM)
                [MetaAds setBannerPosition:BANNER_CENNER_BOTTOM];
            else if(msg==MA_BANNER_CENNER_TOP)
                [MetaAds setBannerPosition:BANNER_CENNER_TOP];
            break;
        case MA_SHOWGAMEAD:
            if(msg==MSLocationPauseBefore){
                puaseTimes++;
                if(setPuaseTimes!=0 && puaseTimes%setPuaseTimes==0){
                    return MSTypeInterstitial;
                }
            }else if(msg==MSLocationPauseAfter){
                if(setPuaseTimes!=0 && puaseTimes%setPuaseTimes==0){
                    [MetaAds showGameAd];
                    return MSTypeInterstitial;
                }
            }else if(msg==MSLocationOverBefore){
            #if(SDK_METAPLATFORM == SDK_OPEN)
                int rateExe = [MetaBase getRateExe];
                if(rateExe>0){
                    int rateTime = [[MetaPlatform readPlatConfig:@"mb_rate" defaultValue:@"0"] intValue];
                    rateTime++;
                    [MetaPlatform writePlatConfig:@"mb_rate" value:[NSString stringWithFormat:@"%d",rateTime]];
                    if(rateTime==2 || rateTime==10){
                        return MSTypeRate;
                    }
                }
            #endif
            #if(SDK_METAVIDEO == SDK_OPEN)
                if([MetaVideo getShowVideo]){
                    overTimes=0;
                    [MetaVideo showVideo];
                    return MSTypeVideo;
                }
            #endif
                overTimes++;
                if(setOverTimes!=0 && overTimes%setOverTimes==0){
                    [MetaAds showGameAd];
                    return MSTypeInterstitial;
                }
            }else if(msg==MSLocationOverAfter){
            }else{
                [MetaAds showGameAd];
                return MSTypeInterstitial;
            }
            return MSTypeNull;
        case MA_SHOWMOREGAMES:
            [MetaAds showMoreGames];
            break;
        case MA_NATIVEICONCACHE:
        {
            int count         = std::atoi(msg.c_str());
            NSString* nsJson  = [MetaAds nativeIconAdCache:count];
            std::string *json = new std::string([nsJson UTF8String]);
            return *json;
        }
        case MA_NATIVEICONCLICKED:
        {
            int index = std::atoi(msg.c_str());
            [MetaAds nativeIconAdClicked:index];
            break;
        }
    #endif
            
            
    #if(SDK_METAPLATFORM == SDK_OPEN)
        case MP_GETITEMKEY:
            return [[MetaPlatform getItemByKey:[NSString stringWithCString:msg.c_str() encoding:[NSString defaultCStringEncoding]]] UTF8String];
        case MP_UPLOADSCORE:
        {
            NSDictionary *msgDic = parseJson(msg);
            long score           = [[msgDic objectForKey:@"score"] integerValue];
            NSString *category   = [msgDic objectForKey:@"category"];
            [MetaPlatform uploadScore:score category:category];
            break;
        }
        case MP_UPLOADARCHIVE:
        {
            NSDictionary *msgDic = parseJson(msg);
            long      point = [[msgDic objectForKey:@"point"] integerValue];
            NSString *indentifier = [msgDic objectForKey:@"indentifier"];
            [MetaPlatform uploadArchivement:point indentifier:indentifier];
            break;
        }
        case MP_MOREGAME:
            [MetaPlatform moreGame];
            break;
        case MP_SHOWRANK:
            [MetaPlatform showRank:[NSString stringWithCString:msg.c_str() encoding:[NSString defaultCStringEncoding]]];
            break;
        case MP_SHOWRATE:
            [MetaPlatform writePlatConfig:@"mb_rate" value:@"100"];
            [MetaPlatform showRate];
            break;
        case MP_SHOWSHARE:
        case MP_TWITTERSHARE:
        {
            NSDictionary *msgDic = parseJson(msg);
            NSString *text = [msgDic objectForKey:@"text"];
            NSString *imgPath = [msgDic objectForKey:@"imgPath"];
            if(type == MP_SHOWSHARE)[MetaPlatform showShare:text img:imgPath];
            else if(type == MP_TWITTERSHARE)[MetaPlatform twitterShare:text imgPath:imgPath callBack:^(BOOL isSuc){
                getOnInvokeGame()(MP_TWITTERSHARE, isSuc?"true":"false");
            }];
            break;
        }
        case MP_FBLIKE:
            [MetaPlatform faceBookLike];
            break;
        case MP_TWITTERFOLLOW:
            [MetaPlatform twitterFollow];
            break;
        case MP_GETIEMIKEY:
            return [[MetaPlatform getIemiKey] UTF8String];
        case MP_BUY:
        {
            [MetaPlatform registerOnInvokeGame:^NSString*(NSNumber *retType, NSString* retMsg){
                getOnInvokeGame()([retType intValue], [retMsg UTF8String]);
                return nil;
            }];
            [MetaPlatform buy:[NSString stringWithCString:msg.c_str() encoding:[NSString defaultCStringEncoding]]];
            break;
        }
        case MP_RESTORE:
        {
            [MetaPlatform registerOnInvokeGame:^NSString*(NSNumber *retType, NSString* retMsg){
                getOnInvokeGame()([retType intValue], [retMsg UTF8String]);
                return nil;
            }];
            [MetaPlatform restore];
            break;
        }
        case MP_REMOVEADS:
            [MetaPlatform writePlatConfig:@"mp_sob" value:@"true"];
            #if (SDK_METAADS == SDK_OPEN)
                [MetaAds removeAdsChanged];
            #endif
            
            #if (SDK_METAVIDEO == SDK_OPEN)
                [MetaVideo removeAdsChanged];
            #endif
            break;
        case MP_ISREMOVEADS:
            return [[MetaPlatform readPlatConfig:@"mp_sob" defaultValue:@"false"] UTF8String];
        case MP_VIBRATE:
            [MetaPlatform Vibrate:atoi(msg.c_str())];
            break;
        case MP_CLIPBOARD:
            return [[MetaPlatform getClipboard] UTF8String];
        case MP_EVENTCOUNT:
            [MetaPlatform analysisEvent:[NSString stringWithCString:msg.c_str() encoding:[NSString defaultCStringEncoding]]];
            break;
        case MP_GETSHARELINK:
            return [[MetaPlatform getShareLink] UTF8String];
    #endif
            
            
    #if (SDK_METAVIDEO == SDK_OPEN)
        case MV_ISREADY_REWARD:
            return [MetaVideo isVideoRewardReady]?"true":"false";
        case MV_SHOW_REWARD:
            [MetaVideo showRewardVideo];
            break;
        case MV_SUCWATCH:
            [MetaVideo setWatchCallBack:^(bool isSuc){getOnInvokeGame()(MV_SUCWATCH, isSuc?"true":"false");}];
            break;
    #endif
            
            
    #if (SDK_METAFACEBOOK == SDK_OPEN)
        case MFB_FBLOGIN:
            [MetaFacebook Login:^(bool isSuc){
                [MetaFacebook FetchUserDetails:^(bool isSuc){}];
                getOnInvokeGame()(MFB_FBLOGIN, isSuc?"true":"false");
            }];
            break;
        case MFB_FBLOGOUT:
            [MetaFacebook Logout:^(bool isSuc){
                getOnInvokeGame()(MFB_FBLOGOUT, isSuc?"true":"false");
            }];
            break;
        case MFB_FBISLOGIN:
            return [MetaFacebook IsLoggedIn]? "true":"false";
        case MFB_FBSHARE:
        {
            NSDictionary *msgDic = parseJson(msg);
            NSString *text = [msgDic objectForKey:@"text"];
            NSString *name = [msgDic objectForKey:@"name"];
            NSString *imgPath = [msgDic objectForKey:@"imgPath"];
            if(imgPath == nil){
                [MetaFacebook SendLinkShare:text linkName:name callback:^(bool isSuc){
                    getOnInvokeGame()(MFB_FBSHARE, isSuc?"true":"false");
                }];
            }else{
                [MetaFacebook SendPhotoShare:text picPath:imgPath callback:^(bool isSuc){
                    getOnInvokeGame()(MFB_FBSHARE, isSuc?"true":"false");
                }];
            }
            break;
        }
        case MFB_FBINVITE:
        {
            [MetaFacebook SendInvite:nil callback:^(NSArray *data){
                getOnInvokeGame()(MFB_FBINVITE, data==nil?"":[toJsonString(data) UTF8String]);
            }];
            break;
        }
        case MFB_FBGETUSERINFO:
        {
            NSDictionary *dict = [[NSDictionary alloc] initWithObjectsAndKeys:
                                  [MetaFacebook GetUserFirstName], @"name",
                                  [MetaFacebook GetUserFBID], @"uid",
                                  nil];
            return [toJsonString(dict) UTF8String];
        }
        case MFB_FBGETRANK:
        {
            [MetaFacebook GetScores:^(NSArray *data){
                getOnInvokeGame()(MFB_FBGETRANK, data==nil?"":[toJsonString(data) UTF8String]);
            }];
        }
        case MFB_UPLOADSCORE: 
            [MetaFacebook SendScore:std::atoi(msg.c_str())];
            break;
        case MFB_UPLOADARCHIVE:
            [MetaFacebook SendAchievement:[NSString stringWithCString:msg.c_str() encoding:[NSString defaultCStringEncoding]]];
            break;
        case MFB_ADDDOWNLOAD:
            [MetaFacebook addImageDownloadEvent:[NSString stringWithCString:msg.c_str() encoding:[NSString defaultCStringEncoding]]];
            break;
        case MFB_GETHEADIMGPATH:
        {
            NSString *imgPath = [MetaFacebook getImagePath:[NSString stringWithCString:msg.c_str() encoding:[NSString defaultCStringEncoding]]];
            return imgPath==nil? "":[imgPath UTF8String];
        }
    #endif
    #if (SDK_METAREPLAY == SDK_OPEN)
        case MR_AUTORECORD:
            [MetaReplay registerOnInvokeGame:^NSString*(NSNumber *retType, NSString* retMsg){
                std::string ret  = getOnInvokeGame()([retType intValue], [retMsg UTF8String]);
                return [NSString stringWithCString:ret.c_str() encoding:[NSString defaultCStringEncoding]];
            }];
            [MetaReplay autoRecordForSeconds:atoi(msg.c_str())];
            break;
        case MR_STARTRECORD:
            [MetaReplay startRecord];
            break;
        case MR_PAUSERECORD:
            [MetaReplay pauseRecord];
            break;
        case MR_RESUMERECORD:
            [MetaReplay resumeRecord];
            break;
        case MR_STOPRECORD:
            [MetaReplay registerOnInvokeGame:^NSString*(NSNumber *retType, NSString* retMsg){
                std::string ret  = getOnInvokeGame()([retType intValue], [retMsg UTF8String]);
                return [NSString stringWithCString:ret.c_str() encoding:[NSString defaultCStringEncoding]];
            }];
            [MetaReplay stopRecord];
            break;
        case MR_PLAYLASTRECORD:
            [MetaReplay registerOnInvokeGame:^NSString*(NSNumber *retType, NSString* retMsg){
                std::string ret  = getOnInvokeGame()([retType intValue], [retMsg UTF8String]);
                return [NSString stringWithCString:ret.c_str() encoding:[NSString defaultCStringEncoding]];
            }];
            [MetaReplay playLastRecord];
            break;
    #endif
            
    }
    return "IOS";
}
#endif