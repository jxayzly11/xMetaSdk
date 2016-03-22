using UnityEngine;
using System.Runtime.InteropServices;

public abstract class MetaUnity: MonoBehaviour {
	// meta invoke type begin
	//General-Position
	internal  const string MA_BANNER_CENNER_TOP    = "0";//banner位置为顶部中央值
	internal  const string MA_BANNER_CENNER_BOTTOM = "1";//banner位置为底部中央值
	
	//General-Location
	internal  const string MSLocationPauseBefore  = "MSLocationPauseBefore";//暂停动画之前调用
	internal  const string MSLocationPauseAfter   = "MSLocationPauseAfter" ;//暂停动画之后调用
	internal  const string MSLocationOverBefore   = "MSLocationOverBefore" ;//结束动画之前调用
	internal  const string MSLocationOverAfter    = "MSLocationOverAfter"  ;//结束动画之后调用
	
	//General-AdType
	internal  const string MSTypeNull             = "MSTypeNull"         ;//啥也没有
	internal  const string MSTypeRate             = "MSTypeRate"         ;//用户评价界面
	internal  const string MSTypeVideo            = "MSTypeVideo"        ;//视频广告界面
	internal  const string MSTypeVideoReward      = "MSTypeVideoReward"  ;//奖励的视频广告
	internal  const string MSTypeInterstitial     = "MSTypeInterstitial" ;//插屏广告界面
	
	//General-Invoke Code
	internal  const int MA_SETADLOAD         = 0x01;//启动广告加载
	internal  const int MA_HIDEBANNER        = 0x02;//隐藏banner
	internal  const int MA_SHOWBANNER        = 0x03;//显示banner
	internal  const int MA_BANNERPOSITION    = 0x04;//设置banner位置
	internal  const int MA_SHOWGAMEAD        = 0x05;//显示插屏广告,增加位置参数后会返回开发者这次播放的是什么类型的广告
	internal  const int MA_SHOWMOREGAMES     = 0x06;//显示更多游戏
	internal  const int MA_NATIVEICONCACHE   = 0x07;//请求原生广告
	internal  const int MA_NATIVEICONCLICKED = 0x08;//原生广告被点击
	internal  const int MA_EXIT              = 0x09;//显示退出广告
	
	internal  const int MP_GETITEMKEY        = 0x100;//根据名字获取Key值
	internal  const int MP_UPLOADSCORE       = 0x101;//上传榜单分数
	internal  const int MP_UPLOADARCHIVE     = 0x102;//上传成就点数
	internal  const int MP_MOREGAME          = 0x103;//展示appstore更多游戏
	internal  const int MP_SHOWRANK          = 0x104;//跳转到榜单界面
	internal  const int MP_SHOWRATE          = 0x105;//跳转到市场评分界面
	internal  const int MP_SHOWSHARE         = 0x106;//展示普通分享
	internal  const int MP_FBLIKE            = 0x107;//跳转fb喜欢
	internal  const int MP_TWITTERFOLLOW     = 0x108;//跳转twitter追随
	internal  const int MP_TWITTERSHARE      = 0x109;//展示twitter分享
	internal  const int MP_GETIEMIKEY        = 0x10a;//获取一唯一码
	internal  const int MP_BUY               = 0x10b;//购买
	internal  const int MP_RESTORE           = 0x10c;//恢复购买
	internal  const int MP_BUY_SUC           = 0x10d;//回调:购买成功
	internal  const int MP_BUY_FAIL          = 0x10e;//回调:购买失败
	internal  const int MP_RESTORE_SUC       = 0x10f;//回调:恢复成功
	internal  const int MP_REMOVEADS         = 0x110;//写入去掉广告
	internal  const int MP_ISREMOVEADS       = 0x111;//获取是否去掉广告
	internal  const int MP_VIBRATE           = 0x112;//震动
	internal  const int MP_CLIPBOARD         = 0x113;//获取剪切板内容
	internal  const int MP_EVENTCOUNT        = 0x114;//事件统计
	internal  const int MP_GETSHARELINK      = 0x115;//获取分享link
	internal  const int MP_GETISCHINESEUSER  = 0x116;//获取是否是大陆佬
	internal  const int MP_ADD_LOCALNOTICE   = 0x117;//增加一条本地通知
	internal  const int MP_REMOVE_LOCALNOTICE= 0x118;//删除一条本地通知
	internal  const int MP_ISOPENMENURATE    = 0x119;//获取是否打开菜单的Rate
	internal  const int MP_GETUSERNAME       = 0x120;//获取GooglePlay/GameCenter的用户名
	internal  const int MP_GETLEADERSCORE    = 0x121;//获取当前Google/apple帐号的排行榜分数
	internal  const int MP_SHOWACHIEVEMENT   = 0x122;//展示成就
	internal  const int MP_ISPOPRATE         = 0x123;//是否弹出Rate
	
	internal  const int MV_ISREADY_REWARD    = 0x200;//奖励视频是否准备好
	internal  const int MV_SHOW_REWARD       = 0x201;//展示奖励视频
	internal  const int MV_SUCWATCH          = 0x202;//观看视频回调接口，将返回广告类型，是否成功观看
	
	internal  const int MFB_FBLOGIN          = 0x300;//facebook登入
	internal  const int MFB_FBLOGOUT         = 0x301;//facebook登出
	internal  const int MFB_FBISLOGIN        = 0x302;//facebook是否登入
	internal  const int MFB_FBSHARE          = 0x303;//facebook分享
	internal  const int MFB_FBINVITE         = 0x304;//facebook邀请
	internal  const int MFB_FBGETUSERINFO    = 0x305;//facebook获取用户信息
	internal  const int MFB_FBGETRANK        = 0x306;//facebook获取排行榜
	internal  const int MFB_UPLOADSCORE      = 0x307;//facebook上传分数
	internal  const int MFB_UPLOADARCHIVE    = 0x308;//facebook上传成就
	internal  const int MFB_ADDDOWNLOAD      = 0x309;//增加一条头像下载
	internal  const int MFB_GETHEADIMGPATH   = 0x30a;//获取一个头像
	
	internal  const int MR_AUTORECORD        = 0x400;//自动记录
	internal  const int MR_STARTRECORD       = 0x401;//开始记录
	internal  const int MR_PAUSERECORD       = 0x402;//暂停记录
	internal  const int MR_RESUMERECORD      = 0x403;//恢复记录
	internal  const int MR_STOPRECORD        = 0x404;//停止记录
	internal  const int MR_PLAYLASTRECORD    = 0x405;//停止记录
	internal  const int MR_CALL_SHOW         = 0x406;//everyplay界面打开
	internal  const int MR_CALL_HIDE         = 0x407;//everyplay界面关闭
	internal  const int MR_CALL_SCORE        = 0x408;//提供计分类数据
	internal  const int MR_CALL_LEVEL        = 0x409;//提供关卡等级类数据
	internal  const int MR_CALL_PLAYRECORD   = 0x40a;//播放最后的录制视频

	// meta invoke type end

	[DllImport("__Internal")]
	private static extern string _invokeMeta(int type, string msg);
	
	public static string invokeMeta (int type, string msg = "")
	{
	#if UNITY_IPHONE
		return _invokeMeta (type, msg);
	#endif

	#if UNITY_ANDROID
		AndroidJavaClass jc = new AndroidJavaClass("com.unity3d.player.UnityPlayer");
		AndroidJavaObject jo = jc.Get<AndroidJavaObject>("currentActivity");
		string ret = jo.Call<string>("_invokeMeta", new object[]{type,msg});
		Debug.Log ("invokeMeta done! ret : " + ret);
		return ret;
	#endif

		return "";
	}

	internal abstract void invokeMetaCallback(int type, string msg);

	// invokeMeta callback
	void invokeMetaCallback (string msg)
	{
		//do what u want split msg
		int firstSplit = msg.IndexOf(',');
		int type = int.Parse(msg.Substring(0, firstSplit));
		string v = msg.Substring(firstSplit);
		invokeMetaCallback (type, v);
	}
}
