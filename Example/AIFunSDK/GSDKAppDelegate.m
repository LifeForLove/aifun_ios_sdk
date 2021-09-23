//
//  GSDKAppDelegate.m
//  AIFunSDK
//
//  Created by LifeForLove on 02/05/2021.
//  Copyright (c) 2021 LifeForLove. All rights reserved.
//

#import "GSDKAppDelegate.h"
#import <AIFunSDK/AIFunSDK.h>
@interface GSDKAppDelegate ()

// 网络连接失败需要重新注册
@property (nonatomic,assign) BOOL needRegisterAppAgain;

@end

@implementation GSDKAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    // 注册结果
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(sdkRegisterResult:) name:AIFunSDKInitDidFinishedNotification object:nil];
    
    [self initConfig];
    [self registerSDK];
    

    return YES;
}

- (void)sdkRegisterResult:(NSNotification *)noti {
    NSDictionary *userInfo = noti.userInfo;
    int errorCode = [userInfo[kAIFunSDKKeyError] intValue];
    if (errorCode == AIFunSDKError_None) {
        NSLog(@"注册成功");
        if ([AIFunSDK defaultSDK].isLogin == NO) {
            [[AIFunSDK defaultSDK]login];
        }
    } else {
    }
}

- (void)initConfig {
}


- (void)registerSDK {
    AIFunSDK * sdk = [AIFunSDK defaultSDK];
    [sdk registerApp:@"20210130063322148466" sdkKey:@"VA51/p5AU/+wWQ8i3ndNLPl/hnrQcnzHvKrNKdX3McI=" channelId:@"1"];
    sdk.openDebugLog = YES;
}

- (void)registerAppAgain {
    if (self.needRegisterAppAgain) {
        [self registerSDK];
    }
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    [[AIFunSDK defaultSDK]applicationWillEnterForeground:application];
}

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options {
    [[AIFunSDK defaultSDK]application:app openURL:url options:options];
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    [[AIFunSDK defaultSDK]applicationWillResignActive:application];
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    [[AIFunSDK defaultSDK] applicationDidBecomeActive:application];
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    [[AIFunSDK defaultSDK]applicationDidEnterBackground:application];
}

- (void)applicationWillTerminate:(UIApplication *)application {
    [[AIFunSDK defaultSDK] applicationWillTerminate:application];
}

@end
