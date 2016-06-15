//
//  MetaCocos.h
//
//  Created by vector on 15-4-3.
//  Modify by Allen Zeng on 15-6-17.
//
//

#ifndef __METACOCOS__
#define __METACOCOS__

#include "MetaConfig.h"

//General-Position
#define MA_BANNER_CENNER_TOP      "0"//banner位置为顶部中央值
#define MA_BANNER_CENNER_BOTTOM   "1"//banner位置为底部中央值

//General-Location
#define MSLocationPauseBefore     "MSLocationPauseBefore"  //暂停动画之前调用
#define MSLocationPauseAfter      "MSLocationPauseAfter"   //暂停动画之后调用
#define MSLocationPauseOver       "MSLocationPauseOver"    //暂停界面结束调用
#define MSLocationOverBefore      "MSLocationOverBefore"   //结束动画之前调用
#define MSLocationOverAfter       "MSLocationOverAfter"    //结束动画之后调用
#define MSLocationOverOver        "MSLocationOverOver"     //结束界面结束调用
#define MSLocationNativeBefore    "MSLocationNativeBefore" //原生界面之前调用
#define MSLocationNativeAfter     "MSLocationNativeAfter"  //原生界面之后调用
#define MSLocationNativeOver      "MSLocationNativeOver"   //原生界面结束调用
#define MSLocationEveryBefore     "MSLocationEveryBefore"  //必出动画之前调用
#define MSLocationEveryOver       "MSLocationEveryOver"    //必出动画之后调用

//General-AdType
#define MSTypeNull                "MSTypeNull"         //啥也没有
#define MSTypeRate                "MSTypeRate"         //用户评价界面
#define MSTypeVideo               "MSTypeVideo"        //视频广告界面
#define MSTypeVideoReward         "MSTypeVideoReward"  //奖励的视频广告
#define MSTypeInterstitial        "MSTypeInterstitial" //插屏广告界面
#define MSTypeNative              "MSTypeNative"       //原生广告

// General-Umeng Level Analysis
#define MSStartLevel              "MSStartLevel"       //关卡开始调用
#define MSFailLevel               "MSFailLevel"        //关卡失败,结束调用
#define MSFinishLevel             "MSFinishLevel"      //关卡成功,结束调用

//General-Invoke Code
#define MA_SETADLOAD              0x01//启动广告加载
#define MA_SETNATIVE_CONFIG       0x02//设置原生参数
#define MA_HIDEBANNER             0x03//隐藏banner
#define MA_SHOWBANNER             0x04//显示banner
#define MA_BANNERPOSITION         0x05//设置banner位置
#define MA_SHOWGAMEAD             0x06//显示插屏广告,增加位置参数后会返回开发者这次播放的是什么类型的广告
#define MA_SHOWMOREGAMES          0x07//显示更多游戏
#define MA_NATIVEICONCACHE        0x08//请求原生广告
#define MA_NATIVEICONCLICKED      0x09//原生广告被点击
#define MA_EXIT                   0x0a//显示退出广告
#define MA_PUZZLE                 0x0b//显示退出广告

#define MP_GETITEMKEY             0x100//根据名字获取Key值
#define MP_UPLOADSCORE            0x101//上传榜单分数
#define MP_UPLOADARCHIVE          0x102//上传成就点数
#define MP_MOREGAME               0x103//展示appstore更多游戏
#define MP_SHOWRANK               0x104//跳转到榜单界面
#define MP_SHOWRATE               0x105//跳转到市场评分界面
#define MP_SHOWSHARE              0x106//展示普通分享
#define MP_FBLIKE                 0x107//跳转fb喜欢
#define MP_TWITTERFOLLOW          0x108//跳转twitter追随
#define MP_TWITTERSHARE           0x109//展示twitter分享
#define MP_GETIEMIKEY             0x10a//获取一唯一码
#define MP_BUY                    0x10b//购买
#define MP_RESTORE                0x10c//恢复购买
#define MP_BUY_SUC                0x10d//回调:购买成功
#define MP_BUY_FAIL               0x10e//回调:购买失败
#define MP_RESTORE_SUC            0x10f//回调:恢复成功
#define MP_REMOVEADS              0x110//写入去掉广告
#define MP_ISREMOVEADS            0x111//获取是否去掉广告
#define MP_VIBRATE                0x112//震动
#define MP_CLIPBOARD              0x113//获取剪切板内容
#define MP_EVENTCOUNT             0x114//事件统计
#define MP_GETSHARELINK           0x115//获取分享link
#define MP_GETISCHINESEUSER       0x116//获取是否是大陆佬
#define MP_ADD_LOCALNOTICE        0x117//增加一条本地通知
#define MP_REMOVE_LOCALNOTICE     0x118//删除一条本地通知
#define MP_ISOPENMENURATE         0x119//获取是否打开菜单的Rate
#define MP_GETUSERNAME            0x120//获取GooglePlay/GameCenter的用户名
#define MP_GETLEADERSCORE         0x121//获取当前Google/apple帐号的排行榜分数
#define MP_SHOWACHIEVEMENT        0x122//展示成就
#define MP_ISPOPRATE              0x123//是否弹出Rate
#define MP_GOGLTRACKER            0x124//GoogleAnalytics event tracker
#define MP_HAVEMOREGAME           0x125//是否有moreGame
#define MP_GAME_SIGN_IN           0x126//sign in GooglePlay/GameCenter
#define MP_GETSKUDETAIL           0x127//get google puchase sku detils
#define MP_EVENTCALC              0x128//umeng event of calc
#define MP_LEVEL_ANALYSIS         0x129//umeng level analysis
#define MP_MAIL_US                0x130//mail us
#define MP_GET_MAIL_SUBJECT       0x131//get mail feedback subject

#define MV_ISREADY_REWARD         0x200//奖励视频是否准备好
#define MV_SHOW_REWARD            0x201//展示奖励视频
#define MV_SUCWATCH               0x202//观看视频回调接口，将返回广告类型，是否成功观看

#define MFB_FBLOGIN               0x300//facebook登入
#define MFB_FBLOGOUT              0x301//facebook登出
#define MFB_FBISLOGIN             0x302//facebook是否登入
#define MFB_FBSHARE               0x303//facebook分享
#define MFB_FBINVITE              0x304//facebook邀请
#define MFB_FBGETUSERINFO         0x305//facebook获取用户信息
#define MFB_FBGETRANK             0x306//facebook获取排行榜
#define MFB_UPLOADSCORE           0x307//facebook上传分数
#define MFB_UPLOADARCHIVE         0x308//facebook上传成就
#define MFB_ADDDOWNLOAD           0x309//增加一条头像下载
#define MFB_GETHEADIMGPATH        0x30a//获取一个头像

#define MR_AUTORECORD             0x400//自动记录
#define MR_STARTRECORD            0x401//开始记录
#define MR_PAUSERECORD            0x402//暂停记录
#define MR_RESUMERECORD           0x403//恢复记录
#define MR_STOPRECORD             0x404//停止记录
#define MR_PLAYLASTRECORD         0x405//停止记录
#define MR_CALL_SHOW              0x406//everyplay界面打开
#define MR_CALL_HIDE              0x407//everyplay界面关闭
#define MR_CALL_SCORE             0x408//提供计分类数据
#define MR_CALL_LEVEL             0x409//提供关卡等级类数据
#define MR_CALL_PLAYRECORD        0x40a//播放最后的录制视频

class MetaCocos
{
protected: 
	MetaCocos(){};
	~MetaCocos(){};
public:
    static MetaCocos* getInstance();
    
    //初始化
    virtual void initMeta(void* meta) = 0;

    //游戏调用，调用其他平台接口
	virtual std::string invokeMeta(int type, std::string msg = "") = 0;

	//游戏调用,即时设置平台回调游戏函数
	void setOnInvokeGame(std::function<std::string(int code, std::string msg)> func);
    
	//平台调用获取当前被设置回调游戏函数
	std::function<std::string(int code, std::string msg)> getOnInvokeGame();
};

#endif /* defined(__METACOCOS__) */
