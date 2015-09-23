———————————————————————————————————————MetaSdk——————————————————————————
MetaSdk是Metafun旗下的SDK组合包，分为 Android 版和 Ios 版，主要包含以下部分：

1.MetaAds         广告SDK
2.MetaPlatform    平台SDK
3.MetaVideo       视频广告SDK
4.MetaFacebook    facebook功能SDK
5.MetaCocos       cocos平台帮助SDK
6.MetaReplay      游戏过程视频回放功能
 
开发者可以根据自己的需求来自定义的选择集成SDK,使用cocos开发的游戏可以使用MetaCocos来提升自己的开发效率
———————————————————————————————————————MetaSdk—————————————————————end——
                                                        ————Allen@Metafun
                                                        ————20150706














—————————————————————————MetaCocos————————————————————v006——
MetaCocos是针对使用cocos2d引擎的开发者提升集成SDK效率的组件
更新前请先阅读 CHANGELOG.txt


————————————————————————环境配置————————————————————————
根据需求，选择需要的组件
—————————————IOS———————————————
1.打开工程将xMetaSdk以Group的方式添加进游戏
2.删除 platform-android,Doc,README.txt 等不需要的组件的引用
3.在info.plist中增加字段来适应 IOS9 的 ATS：
<key>NSAppTransportSecurity</key>
<dict>
    <key>NSAllowsArbitraryLoads</key>
    <true/>
</dict>

4.假如用到以下组件，则在info.plist中增加对应字段

MetaVideo:
<key>LSApplicationQueriesSchemes</key>
    <array>
        <string>fb</string>
        <string>instagram</string>
        <string>tumblr</string>
        <string>twitter</string>
    </array>
</key>

MetaFacebook:
<key>LSApplicationQueriesSchemes</key>
<array>
    <string>fbapi</string>
    <string>fbapi20130214</string>
    <string>fbapi20130410</string>
    <string>fbapi20130702</string>
    <string>fbapi20131010</string>
    <string>fbapi20131219</string>    
    <string>fbapi20140410</string>
    <string>fbapi20140116</string>
    <string>fbapi20150313</string>
    <string>fbapi20150629</string>
    <string>fbauth</string>
    <string>fbauth2</string>
    <string>fb-messenger-api20140430</string>
</array>

5.以下为组件相应需要的添加的额外的 Frameworks 以及 设置：

MetaAds:
	libz.tbd
	AdSupport
	AudioToolbox
	AVFoundation
	CoreGraphics
	CoreMotion
	CoreTelephony
	CoreLocation
	EventKit
	EventKitUI
	Foundation
	MessageUI
	Security
	StoreKit
	SystemConfiguration
	QuarzCore
	UIKit
	MediaPlayer        （非必需，若cocos游戏报错添加）
	GameController     （非必需，若cocos游戏报错添加）	
	项目Target -> Build Settings -> Other Linker Flags 分别添加两个参数：-ObjC, -lstdc++

MetaVideo:
	libz.tbd
	libz.1.2.5.tbd
	libsqlite3.tbd
	AdSupport
	AudioToolbox
	AVFoundation
	CFNetwork
	CoreGraphics
	CoreMedia
	CoreTelephony
	EventKit
	EventKitUI
	Foundation
	MediaPlayer
	MessageUI
	QuartzCore
	Social (Set to Optional)
	StoreKit
	SystemConfiguration
	UIKit
	WebKit                 (Set to Optional)

MetaPlatform:
	Social
	GameKit
	StoreKit

MetaReplay:
	AdSupport 
	AssetsLibrary
	AudioToolbox
	AVFoundation
	CoreGraphics
	CoreImage(iOS 5+, set to Optional link for pre-iOS 5 compatibility)
	CoreMedia
	CoreVideo
	Foundation
	MessageUI
	MobileCoreServices
	OpenGLES
	QuartzCore
	Security
	Social 
	StoreKit
	SystemConfiguration
	Twitter (iOS 5+, set to Optional link for pre-iOS 5 compatibility)
	UIKit

MetaFacebook:
       项目Target -> Info -> URL Type 添加参数 URL Schemes:fbxxxxxxxxxxx(“xx..”为facebook id) ，其他为默认参数

—————————————Android———————————————
1.打开游戏工程的 project.properties，添加（请自行修改路径）：
android.library.reference.1=../../../xMetaSdk/platform-android/MetaBase
android.library.reference.2=../../../xMetaSdk/platform-android/MetaAds
android.library.reference.3=../../../xMetaSdk/platform-android/MetaFacebook
android.library.reference.4=../../../xMetaSdk/platform-android/MetaPlatform
android.library.reference.5=../../../xMetaSdk/platform-android/MetaVideo


————————————————————————参数修改————————————————————————
1.打开 MetaCocos/MetaConfig.h，配置需要使用的组件 SDK_OFF为关闭，SDK_OPEN为打开
—————————————IOS———————————————
打开工程的Info.plist文件，根据提供的id.txt添加以下参数(部分参数没有就不添加，添加进 MetaExtra 中,可参考Doc/ios/info.plist)

创建参数词典组：MetaExtra
PRODUCT_ID             String
PRODUCT_ID_UM          String
PRODUCT_ID_U3          String
PRODUCT_ID_VG          String
PRODUCT_ID_AC          String
PRODUCT_KEY_SCORE      String
PRODUCT_ADTIME_PUASE   String      //暂停多少次出插屏
PRODUCT_ADTIME_OVER    String      //失败多少次出插屏


下面这个字段不需要放在 MetaExtra 里面，直接放在外面
FacebookAppID          String


—————————————Android———————————————
打开工程的string.xml,根据提供的id.txt添加以下参数(部分参数没有就不添加，添加进 MetaExtra 中,可参考Doc/android/strings.xml)
FacebookAppID
PRODUCT_ID
PRODUCT_ID_UM
PRODUCT_ID_U3
PRODUCT_ID_AC          
PRODUCT_KEY_SCORE     
PRODUCT_ADTIME_PUASE           //暂停多少次出插屏
PRODUCT_ADTIME_OVER            //失败多少次出插屏


————————————————————————代码接入————————————————————————
—————————————IOS———————————————
请参考提供的 Doc/ios/AppController.mm 和 Doc/ios/RootViewController.mm 对应修改 IOS 部分(建议直接引用OverrideHelper)

—————————————Android———————————————
请参考提供的 Doc/Android/AndroidManifest.xml 和 Doc/Android/AppActivity.java 对应修改 Android 部分


————————————————————————————API————————————————————————
MetatCocos所有的API都是通过以下两个方法实现的

＃调用平台方法,code为平台方法的类型，msg为需要穿进去的参数
MetatCocos::getInstance()->invokeMeta(int code, std::string msg);

＃设置回调，某些地方需要回调之后进行下一步操作，比如logo加载后的回调，facebook登入回调等等，可以通过code来判断是什么类型的回调
MetatCocos::getInstance()->setOnInvokeGame(std::function<std::string(int code, std::string msg)> func);


————————————————————————————关于Logo的回调————————————————————————
Metafun Games旗下的游戏在启动的时候必须加载Logo，以下为调用规则
1.在 Doc/logo 选择游戏对应尺寸的 logo
2.通过 setOnInvokeGame 设置一个全局的回调，处理 MA_SETADLOAD 的事件
3.渐显 logo 1.2秒，然后加载游戏资源，然后调用 MetaCocos::getInstance()->invokeMeta(MA_SETADLOAD);
4.当回调回来的时候，渐隐 logo 1.2秒，进入游戏

ps：一般在启动游戏的时候 通过 setOnInvokeGame 设置一个全局的回调，然后用这个回调去处理游戏内所有可能发生的回调事件


————————————————————————————关于插屏广告和主动请求Rate——————————————————————————
插屏广告的显示规则由组件控制，游戏只要完成以下功能
1.配置 PRODUCT_ADTIME_PUASE 的参数，当参数为 3 的时候意味着暂停3次会出现一次插屏
2.配置 PRODUCT_ADTIME_OVER 的参数，当参数为 3 的时候意味着结束3次会出现一次插屏
3.为了用户体验要求开发者在用户点击暂停和结束游戏的时候有一个动画过渡，不能直接出现结束界面，并且在相应的节点调用以下方法

暂停动画之前：MetaCocos::getInstance()->invokeMeta(MA_SHOWGAMEAD,MSLocationPauseBefore);
暂停动画之后：MetaCocos::getInstance()->invokeMeta(MA_SHOWGAMEAD,MSLocationPauseAfter);
结束动画之前：MetaCocos::getInstance()->invokeMeta(MA_SHOWGAMEAD,MSLocationOverBefore);
结束动画之后：MetaCocos::getInstance()->invokeMeta(MA_SHOWGAMEAD,MSLocationOverAfter);

4.方法会有返回值，返回当前显示的什么类型的元素，开发者只需要处理返回值为 MSTypeRate 的时候
5.当返回值为 MSTypeRate 的时候，开发者需要显示一个 Rate 界面，具体界面可以在 Doc/rate 中找到
6.点击 Suggestion 和 Rate game，开发者调用 MetaCocos::getInstance()->invokeMeta(MP_SHOWRATE);



eg:
———————————————————————————————————————METAADS———————————————————————
01.隐藏banner
    MetaCocos::getInstance()->invokeMeta(MA_HIDEBANNER);
02.显示banner
    MetaCocos::getInstance()->invokeMeta(MA_SHOWBANNER);
03.设置banner条位置
    MetaCocos::getInstance()->invokeMeta(MA_BANNERPOSITION,MA_BANNER_CENNER_TOP);
    MetaCocos::getInstance()->invokeMeta(MA_BANNERPOSITION,MA_BANNER_CENNER_BOTTOM);
04.显示插屏广告，一般情况下只需要调用上面所述
    MetaCocos::getInstance()->invokeMeta(MA_SHOWGAMEAD);
05.显示更多游戏
    MetaCocos::getInstance()->invokeMeta(MA_SHOWMOREGAMES);
06.获取原生Icon广告
    MetaCocos::getInstance()->invokeMeta(MA_NATIVEICONCACHE,”count”);      
	count:请求求原生Icon的个数,函数将数据以json的格式返回
    MetaCocos::getInstance()->invokeMeta(MA_NATIVEICONCLICKED,”index”);
        index:被点击的原生广告的位置

———————————————————————————————————————METAPLATFORM———————————————————————
101.根据名字获取Key值，一般用于排行榜ID的获取
    MetaCocos::getInstance()->invokeMeta(MP_GETITEMKEY,"PRODUCT_KEY_SCORE");
102.上传榜单分数，category 为排行榜ID，可以根据101方法获取
    	MetaCocos::getInstance()->invokeMeta(MP_UPLOADSCORE,”{\”score\”:100,\”category\”:\”id\”}\”);
103.上传成就点数，category 为排行榜ID，可以根据101方法获取
	MetaCocos::getInstance()->invokeMeta(MP_UPLOADARCHIVE,”{\”point\”:100,\”category\”:\”id\”}\”);
104.展示App Store更多游戏
	MetaCocos::getInstance()->invokeMeta(MP_MOREGAME);
105.展示榜单
	MetaCocos::getInstance()->invokeMeta(MP_SHOWRANK, “榜单id”);
106.展示评分
	MetaCocos::getInstance()->invokeMeta(MP_SHOWRATE);
107.展示普通分享,图片地址保存在本地，用 FileUtils::getInstance()->fullPathForFilename 获取
	MetaCocos::getInstance()->invokeMeta(MP_SHOWSHARE, "{\"text\":\"分享的内容\",\"imgPath\":\"图片的地址\"}");
108.跳转Facebook like us
	MetaCocos::getInstance()->invokeMeta(MP_FBLIKE);
109.跳转twitter follow
	MetaCocos::getInstance()->invokeMeta(MP_TWITTERFOLLOW);
110.展示twitter分享,图片地址保存在本地，用 FileUtils::getInstance()->fullPathForFilename 获取
	MetaCocos::getInstance()->invokeMeta(MP_TWITTERSHARE, "{\"text\":\"分享的内容\",\"imgPath\":\"图片的地址\"}");
111.获取唯一码
	MetaCocos::getInstance()->invokeMeta(MP_GETIEMIKEY);
112.购买
	MetaCocos::getInstance()->invokeMeta(MP_BUY, “商品id”);
113.恢复购买
	MetaCocos::getInstance()->invokeMeta(MP_RESTORE);
114.回调:购买成功
	MetaCocos::getInstance()->setOnInvokeGame(std::function<std::string(int code, std::string msg)>)
115.回调:购买失败
	MetaCocos::getInstance()->setOnInvokeGame(std::function<std::string(int code, std::string msg)>)
116.回调:恢复购买成功
	MetaCocos::getInstance()->setOnInvokeGame(std::function<std::string(int code, std::string msg)>)
117.写入广告已经移除
	MetaCocos::getInstance()->invokeMeta(MP_REMOVEADS);
118.读取广告是否移除，返回 “true” or “false”
        MetaCocos::getInstance()->invokeMeta(MP_ISREMOVEADS);
119.震动手机
	MetaCocos::getInstance()->invokeMeta(MP_VIBRATE);

———————————————————————————————————————METAVIDEO———————————————————————
201.奖励视频是否准备好，返回 “true” or “false”
	MetaCocos::getInstance()->invokeMeta(MV_ISREADY_REWARD);
202.展示奖励视频
	MetaCocos::getInstance()->invokeMeta(MV_SHOW_REWARD);
203.通知更新观看视频回调接口，将返回广告类型，是否成功观看
	MetaCocos::getInstance()->invokeMeta(MV_SUCWATCH);

———————————————————————————————————————METAFACEBOOK———————————————————————
301.facebook登入
	MetaCocos::getInstance()->invokeMeta(MFB_FBLOGIN);
302.facebook登出
	MetaCocos::getInstance()->invokeMeta(MFB_FBLOGOUT);
303.facebook是否登入，返回 “true” or “false”
	MetaCocos::getInstance()->invokeMeta(MFB_FBISLOGIN);
304.facebook分享
	MetaCocos::getInstance()->invokeMeta(MFB_FBSHARE,"{\"name\”:\”标题\”,\”text\”:\”内容\”}”);
305.facebook邀请
	MetaCocos::getInstance()->invokeMeta(MFB_FBINVITE);
306.facebook获取用户信息，返回json
	MetaCocos::getInstance()->invokeMeta(MFB_FBGETUSERINFO);
307.facebook获取排行榜，返回json
	MetaCocos::getInstance()->invokeMeta(MFB_FBGETRANK);
308.facebook上传分数
	MetaCocos::getInstance()->invokeMeta(MFB_UPLOADSCORE,”分数”);
309.facebook上传成就
	MetaCocos::getInstance()->invokeMeta(MFB_UPLOADARCHIVE);
310.增加一条头像下载
	MetaCocos::getInstance()->invokeMeta(MFB_ADDDOWNLOAD,”ID”);
311.获取一个头像
	MetaCocos::getInstance()->invokeMeta(MFB_GETHEADIMGPATH,”ID”);


———————————————————————————————————————METACOCOS—————————————————————end——
                                                        ————Allen@Metafun
                                                        ————20150923

