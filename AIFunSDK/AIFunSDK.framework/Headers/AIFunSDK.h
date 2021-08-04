//
//  AIFunSDK.h
//  AIFunSDK
//
//  Created by 高欣 on 2021/2/6.
//

#import <Foundation/Foundation.h>
#import "AIFunSDKDefines.h"
#import "AIFunSDKPayInfo.h"
#import "AIFunSDKDataCollect.h"
#import <UIKit/UIKit.h>
extern NSString * _Nullable const AIFunSDKInitDidFinishedNotification;      //初始化成功
extern NSString * _Nullable const AIFunSDKLogOutResultNotification;        //退出登录通知
extern NSString * _Nullable const AIFunSDKLoginResultNotification;         //登录结果通知
extern NSString * _Nullable const AIFunSDKUserTimeOutNotification;         //用户超时通知
extern NSString * _Nullable const AIFunSDKApplePayNotification;            //苹果支付结果通知
extern NSString * _Nullable const AIFunSDKNotiRealAuthNotification;        //用户实名认证

extern NSString* _Nullable const kAIFunSDKKeyError;    /*Notification userinfo error Key */
extern NSString* _Nullable const kAIFunSDKKeyErrorMessage;    /*Notification userinfo error Key Message */
NS_ASSUME_NONNULL_BEGIN

@interface AIFunSDK : NSObject

+(instancetype)defaultSDK;
/**
 开发者ID
 */
@property(nonatomic,copy,readonly)NSString *appId;

/**
 开发者sdkKey
 */
@property(nonatomic,copy,readonly)NSString *sdkKey;

/**
 渠道id
 */
@property(nonatomic,copy,readonly)NSString *channelId;

/**
 判断是否登录
 */
@property (nonatomic,assign,readonly) BOOL isLogin;

/**
 判断在线时长是否超时
 */
@property (nonatomic,assign,readonly) BOOL isTimeOut;

/**
 登录成功会返回token
 */
@property (nonatomic,copy,readonly) NSString *token;

/**
 打开debug log
 */
@property (nonatomic,assign) BOOL openDebugLog;

/**
 @brief 注册第三方应用。
 
 @param appId 开发者ID
 
 @param sdkKey 开发者sdkKey
 
 @param channelId 渠道id
 */
- (void)registerApp:(NSString *)appId sdkKey:(NSString *)sdkKey channelId:(NSString *)channelId;

/**
 @brief 登录接口
 @note  登录结果监听AIFunSDKLoginResultNotification
 */
- (int)login;

/**
 @brief 登出接口 代码调用注销
 @note  成功调用该接口后，SDK会发出AIFunSDKLogOutResultNotification通知
 */
- (int)logout;

/**
 @brief 隐藏悬浮窗
 @result 错误码
 */
- (int)hiddenFloatView;

/**
 @brief 显示悬浮窗
 @result 错误码
 */
- (int)showFloatView;

/**
 @brief 检查aifun是否已被用户安装
 
 @return 微信已安装返回YES，未安装返回NO。
 */
+ (BOOL)isAIFunInstalled;

/**
 @brief 商品购买
 @param orderInfo 订单信息
 @param roleInfo 角色信息
 */
- (void)payOrderInfo:(AIFunSDKPayInfo *)orderInfo roleInfo:(AIFunSDKGameRoleData *)roleInfo;

/**
 @brief 显示超时弹窗
 */
- (void)showTimeOutAlert;

/**
 @brief 拉起实名认证页面
 */
- (void)showVerifyViewController;

/**
 @brief 开始用户超时检测
 */
- (void)beginUserTimeOutRecord;

//***********************数据采集*******************//
/**
 @brief 首次进入
 @result YES表示是首次进入,sdk会进行数据统计; NO 则表示非首次进入或者其他错误
 */
+ (BOOL)dataCollectFirstEnter;

/**
 @brief 首次进入停留时长
 @result YES表示是首次进入,sdk会进行数据统计; NO 则表示非首次进入或者其他错误
 */
+ (BOOL)dataCollectFirstEnterWithStayTypeData:(AIFunSDKFirstData *)data;

/**
 @brief 引导页面数据统计 (该数据会暂时写入本地,延时上传)
 @result YES表示,sdk数据统计成功; NO 则表示统计失败
 */
+ (BOOL)dataCollectWithGuideData:(AIFunSDKGuideData *)data;

/**
 @brief 关卡数据统计 (该数据会暂时写入本地,延时上传)
 @result YES表示,sdk数据统计成功; NO 则表示统计失败
 */
+ (BOOL)dataCollectWithMissionData:(AIFunSDKMissionData *)data;

/**
 区服角色信息数据统计
 */
+ (BOOL)dataCollectWithGameRoleData:(AIFunSDKGameRoleData *)data;

//***********************应用生命周期的回调*******************//
//在应用对应的生命周期回调中调用
/**
 @brief  渠道处理应用跳转
 @note 必接
 */
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options;
- (void)applicationWillResignActive:(UIApplication *)application;
- (void)applicationDidEnterBackground:(UIApplication *)application;
- (void)applicationWillEnterForeground:(UIApplication *)application;
- (void)applicationDidBecomeActive:(UIApplication *)application;
- (void)applicationWillTerminate:(UIApplication *)application;

@end

NS_ASSUME_NONNULL_END
