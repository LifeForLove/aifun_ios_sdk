//
//  GSDKAppDelegate.m
//  AIFunSDK
//
//  Created by LifeForLove on 02/05/2021.
//  Copyright (c) 2021 LifeForLove. All rights reserved.
//

#import "GSDKAppDelegate.h"
#import <AIFunSDK/AIFunSDK.h>
#import <AFNetworking.h>
@interface GSDKAppDelegate ()

// 网络连接失败需要重新注册
@property (nonatomic,assign) BOOL needRegisterAppAgain;

@end

@implementation GSDKAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    // Override point for customization after application launch.
    [self addObserver];
    [self initConfig];
    [self registerSDK];

    return YES;
}

- (void)addObserver {
    // 注册结果
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(sdkRegisterResult:) name:AIFunSDKInitDidFinishedNotification object:nil];
    
    // 登录结果
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(sdkLoginResult:) name:AIFunSDKLoginResultNotification object:nil];
    
    // 退出登录结果
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(sdkLogoutResult:) name:AIFunSDKLogOutResultNotification object:nil];
}

- (void)registerSDK {

    AIFunSDK * sdk = [AIFunSDK defaultSDK];
    [sdk registerApp:@"2020181818" sdkKey:@"KBKCcehoHurLkkFA2rdTwhUwqezdUDexUccrW7BvXfs=" channelId:@"1"];
    //    [sdk registerApp:@"20210130063322148466" sdkKey:@"VA51/p5AU/+wWQ8i3ndNLPl/hnrQcnzHvKrNKdX3McI=" channelId:@"1"];
}

- (void)sdkRegisterResult:(NSNotification *)noti {
    NSDictionary *userInfo = noti.userInfo;
    int errorCode = [userInfo[kAIFunSDKKeyError] intValue];
    if (errorCode == AIFunSDKRequestError_None) {
        NSLog(@"注册成功");
    } else {
        if (![AFNetworkReachabilityManager sharedManager].isReachable) {
            NSLog(@"网络连接失败");
            self.needRegisterAppAgain = YES;
        }
    }
}

- (void)sdkLoginResult:(NSNotification *)noti {
    NSDictionary *userInfo = noti.userInfo;
    int errorCode = [userInfo[kAIFunSDKKeyError] intValue];
    if (errorCode == AIFunSDKRequestError_None) {
        NSLog(@"登录成功");
    }
}

- (void)sdkLogoutResult:(NSNotification *)noti {
    NSDictionary *userInfo = noti.userInfo;
    int errorCode = [userInfo[kAIFunSDKKeyError] intValue];
    if (errorCode == AIFunSDKRequestError_None) {
        NSLog(@"退出登录成功");
    }
}

- (void)initConfig {
    AFNetworkReachabilityManager *manager = [AFNetworkReachabilityManager sharedManager];
    [manager setReachabilityStatusChangeBlock:^(AFNetworkReachabilityStatus status) {
        // 当网络状态改变时调用
        switch (status) {
                case AFNetworkReachabilityStatusUnknown://未知网络
                NSLog(@"未知网络");
                break;
                case AFNetworkReachabilityStatusNotReachable://没有网络
                break;
                case AFNetworkReachabilityStatusReachableViaWWAN://手机自带网络
                [self registerAppAgain];
                break;
                case AFNetworkReachabilityStatusReachableViaWiFi://WIFI
                [self registerAppAgain];
                break;
        }
    }];
    //开始监控
    [manager startMonitoring];
}

- (void)registerAppAgain {
    if (self.needRegisterAppAgain) {
        [self registerSDK];
    }
}


@end
