//
//  AIFunSDK.h
//  AIFunSDK
//
//  Created by 高欣 on 2021/2/6.
//

#import <Foundation/Foundation.h>
#import "AIFunSDKDefines.h"
#import "AIFunSDKPayInfo.h"
#import "AIFunSDKGameRoleInfo.h"
#import <UIKit/UIKit.h>
extern NSString * _Nullable const AIFunSDKInitDidFinishedNotification;      //初始化成功
extern NSString * _Nullable const AIFunSDKLogOutResultNotification;        //退出登录通知
extern NSString * _Nullable const AIFunSDKLoginResultNotification;         //登录结果通知
extern NSString * _Nullable const AIFunSDKUserTimeOutNotification;         //用户超时通知
extern NSString * _Nullable const AIFunSDKApplePayNotification;            //苹果支付结果通知
extern NSString * _Nullable const AIFunSDKNotiRealAuthNotification;        //用户实名认证


extern NSString* _Nullable const kAIFunSDKKeyError;    /*Notification userinfo error Key */
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
 登录成功会返回token
 */
@property (nonatomic,copy,readonly) NSString *token;

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
- (void)payOrderInfo:(AIFunSDKPayInfo *)orderInfo roleInfo:(AIFunSDKGameRoleInfo *)roleInfo;

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
