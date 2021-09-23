//
//  GSDKViewController.m
//  AIFunSDK
//
//  Created by LifeForLove on 02/05/2021.
//  Copyright (c) 2021 LifeForLove. All rights reserved.
//

#import "GSDKViewController.h"
#import <AIFunSDK/AIFunSDK.h>
#import <MBProgressHUD.h>
@interface GSDKViewController ()

@end

@implementation GSDKViewController

- (void)viewDidLoad {
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    [self addObserver];
}

- (void)addObserver {
    // 登录结果
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(sdkLoginResult:) name:AIFunSDKLoginResultNotification object:nil];
    
    // 退出登录结果
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(sdkLogoutResult:) name:AIFunSDKLogOutResultNotification object:nil];
    
    // 苹果支付结果通知
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(sdkApplePayResult:) name:AIFunSDKApplePayNotification object:nil];
    
    // 用户超时通知
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(sdkTimeOutNoti) name:AIFunSDKUserTimeOutNotification object:nil];
}


- (void)sdkLoginResult:(NSNotification *)noti {
    NSDictionary *userInfo = noti.userInfo;
    int errorCode = [userInfo[kAIFunSDKKeyError] intValue];
    if (errorCode == AIFunSDKError_None) {
        NSLog(@"登录成功");
    }
}

- (void)sdkLogoutResult:(NSNotification *)noti {
    NSDictionary *userInfo = noti.userInfo;
    int errorCode = [userInfo[kAIFunSDKKeyError] intValue];
    if (errorCode == AIFunSDKError_None) {
        NSLog(@"退出登录成功");
        if ([AIFunSDK defaultSDK].isLogin == NO) {
            [[AIFunSDK defaultSDK]login];
        }
    }
}

- (void)sdkApplePayResult:(NSNotification *)noti {
    [MBProgressHUD hideHUDForView:[UIApplication sharedApplication].keyWindow animated:YES];
    NSDictionary *userInfo = noti.userInfo;
    int errorCode = [userInfo[kAIFunSDKKeyError] intValue];
    NSString * errorMsg = userInfo[kAIFunSDKKeyErrorMessage];
    if (errorCode == AIFunSDKError_None) {
        NSLog(@"苹果支付成功");
        MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:[UIApplication sharedApplication].keyWindow animated:YES];
        hud.label.text = @"苹果支付成功";
        hud.label.font = [UIFont systemFontOfSize:17.0];
        hud.label.numberOfLines = 0;
        hud.userInteractionEnabled= NO;
        hud.mode = MBProgressHUDModeCustomView;
        hud.removeFromSuperViewOnHide = YES;
        [hud hideAnimated:YES afterDelay:1.5];
    } else {
        NSLog(@"payErrorCode = %d",errorCode);
        MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:[UIApplication sharedApplication].keyWindow animated:YES];
        hud.label.text = [NSString stringWithFormat:@"error : %d \nmessage:%@",errorCode,errorMsg];
        hud.label.font = [UIFont systemFontOfSize:17.0];
        hud.label.numberOfLines = 0;
        hud.userInteractionEnabled= NO;
        hud.mode = MBProgressHUDModeCustomView;
        hud.removeFromSuperViewOnHide = YES;
        [hud hideAnimated:YES afterDelay:1.5];
    }
}

#pragma mark -  用户超时通知
- (void)sdkTimeOutNoti {
    NSLog(@"该用户已超时!");
}

#pragma mark -  开始游戏
- (IBAction)startGame:(UIButton *)sender {
    //判断是否登录
    BOOL isLogin = [self checkLoginState];
    //判断是否超时
    BOOL isTimeOut = [self checkTimeOutState];
    //判断是否已实名认证
    
    if (isLogin && !isTimeOut) {
        //开始超时检测
        [self beginTimeOutRecord];
        NSLog(@"可以开始游戏");
        
        MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:[UIApplication sharedApplication].keyWindow animated:YES];
        hud.label.text = @"可以开始游戏";
        hud.label.font = [UIFont systemFontOfSize:17.0];
        hud.label.numberOfLines = 0;
        hud.userInteractionEnabled= NO;
        hud.mode = MBProgressHUDModeCustomView;
        hud.removeFromSuperViewOnHide = YES;
        [hud hideAnimated:YES afterDelay:1.5];
    } else {
        if (!isLogin) {
            //如果未登录则拉起登录页面
            [self loginAction];
        } else if (isTimeOut) {
            //如果已超时则显示超时弹窗
            [self alertTimeOutAction];
        }
        NSLog(@"不能开始游戏");
    }
}

#pragma mark -  支付
- (IBAction)payAction:(UIButton *)sender {
    if (![AIFunSDK defaultSDK].isLogin) {
        return ;
    }
    
    MBProgressHUD* hud = [MBProgressHUD showHUDAddedTo:[UIApplication sharedApplication].keyWindow animated:YES];
    hud.mode = MBProgressHUDModeIndeterminate;
    
    AIFunSDKPayInfo * payInfo = [AIFunSDKPayInfo new];
    payInfo.count = 1; // 购买数量
    payInfo.amount = 0.1; // 购买金额
    payInfo.goodsID = @"com.aifun.sdk.001"; // 商品id
    payInfo.productName = @"复活币"; // 商品描述
    payInfo.outTradeNo = @"12345"; // 商户订单号
    payInfo.serverId = 0; // 区服id 不传或者传0代表没有区服id,示例值(1)
    AIFunSDKGameRoleData * roleInfo = [AIFunSDKGameRoleData new];
    [[AIFunSDK defaultSDK]payOrderInfo:payInfo roleInfo:roleInfo];
}

#pragma mark -  退出登录
- (IBAction)loginOutAction:(UIButton *)sender {
    if ([AIFunSDK defaultSDK].isLogin) {
        [[AIFunSDK defaultSDK] logout];
    }
}

#pragma mark -  查询登录状态
- (int)checkLoginState {
    return [AIFunSDK defaultSDK].isLogin;
}

#pragma mark -  查询超时状态
- (int)checkTimeOutState {
    return [AIFunSDK defaultSDK].isTimeOut;
}

#pragma mark -  查询是否已实名
- (int)checkAuthName {
    return [AIFunSDK defaultSDK].isAuth;
}

#pragma mark -  拉起登录页面
- (void)loginAction {
    if ([AIFunSDK defaultSDK].isLogin == NO) {
        // 登录
        [[AIFunSDK defaultSDK]login];
    }
}

#pragma mark -  超时弹窗
- (void)alertTimeOutAction {
    if ([AIFunSDK defaultSDK].isTimeOut == YES) {
        // 用户超时弹窗
        [[AIFunSDK defaultSDK] showTimeOutAlert];
    }
}

#pragma mark -  开始用户超时检测
- (void)beginTimeOutRecord {
    if ([AIFunSDK defaultSDK].isTimeOut == NO) {
        [[AIFunSDK defaultSDK]beginUserTimeOutRecord];;
    }
}



- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
