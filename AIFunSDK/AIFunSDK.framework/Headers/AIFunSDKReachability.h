//
//  AIFunSDKReachability.h
//  AIFunSDK
//
//  Created by shannon on 2021/9/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, AIFunSDKNetworkReachabilityStatus) {
    AIFunSDKNetworkReachabilityStatusUnknown          = -1,
    AIFunSDKNetworkReachabilityStatusNotReachable     = 0,
    AIFunSDKNetworkReachabilityStatusReachableViaWWAN = 1,
    AIFunSDKNetworkReachabilityStatusReachableViaWiFi = 2,
};

@interface AIFunSDKReachability : NSObject

/**
 当前网络状态
 */
@property (readonly, nonatomic, assign) AIFunSDKNetworkReachabilityStatus networkReachabilityStatus;

/**
 当前网络是否可访问
 */
@property (readonly, nonatomic, assign, getter = isReachable) BOOL reachable;

/**
 当前网络是否可通过WWAN访问
 */
@property (readonly, nonatomic, assign, getter = isReachableViaWWAN) BOOL reachableViaWWAN;

/**
 当前网络是否可通过WiFi访问
 */
@property (readonly, nonatomic, assign, getter = isReachableViaWiFi) BOOL reachableViaWiFi;

+ (instancetype)sharedManager;

/**
 开始检测
 */
- (void)startMonitoring;

/**
 结束检测
 */
- (void)stopMonitoring;

/**
 检测结果回调
 */
- (void)setReachabilityStatusChangeBlock:(nullable void (^)(AIFunSDKNetworkReachabilityStatus status))block;

@end

NS_ASSUME_NONNULL_END
