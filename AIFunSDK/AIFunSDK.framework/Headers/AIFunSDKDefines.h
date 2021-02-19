//
//  AIFunSDKDefines.h
//  AIFunSDK
//
//  Created by shannon on 2021/2/18.
//

#ifndef AIFunSDKDefines_h
#define AIFunSDKDefines_h

typedef enum : NSUInteger {
    GSDKIAPVerifyFailed = 0,           // 验证请求网络错误
    GSDKIAPVerifyValid,                // 票据有效
    GSDKIAPVerifyInvalid,              // 票据无效
    GSDKIAPVerifyNeedRefreshReceipt ,  // 票据异常
} GSDKIAPVerifyResult;

typedef enum : NSUInteger {
    GSDKIAPLoadingStatus_None = 0,               // 非购买流程状态
    GSDKIAPLoadingStatus_CheckingProduct = 1,    // 查询商品中
    GSDKIAPLoadingStatus_Paying,                 // 正在购买中
    GSDKIAPLoadingStatus_Restoring,              // 恢复购买中
    GSDKIAPLoadingStatus_Verifying,              // 订单验证中
} GSDKIAPLoadingStatus;

typedef enum : NSUInteger {
    GSDKIAPError_Paying = 70101,                  // 购买中
    GSDKIAPError_Jailbroken = 70102,              // 越狱设备
    GSDKIAPError_Parameter = 70103,               // 参数错误
    GSDKIAPError_Permission= 70104,               // 无权限
    GSDKIAPError_ProductId= 70105,                // 没有购买的物品
    GSDKIAPError_Receipt = 70106,                 // 凭据错误
    GSDKIAPError_VerifyInvalid = 70107,           // 验证订单失败
    GSDKIAPError_Net = 70108,                     // 网络错误
    GSDKIAPError_NotRegistered = 70109,           // 未注册IAP
    GSDKIAPError_HasUnfinishedTransaction = 70110,// 有未验证完的订单
} GSDIAPErrorCode;

typedef NS_ENUM(NSUInteger, TransactionStatus){
    TransactionStatusWaitApple,       // 等待支付
    TransactionStatusAppleCancel,     // 取消支付
    TransactionStatusAppleFailed,     // 支付失败
    TransactionStatusAppleSucc,       // 支付成功
    TransactionStatusSeriverError,    // 钥匙串中验证报错
    TransactionStatusSeriverFailed,   // 钥匙串中验证失败
    TransactionStatusSeriverSucc,     // 钥匙串中验证成功
};

typedef enum {
    AIFunSDKRequestError_None                      = 0,    /* 没有错误 */
    AIFunSDKRequestError_Unknown                   = -1,    /* 未知错误 */
    AIFunSDKRequestError_Network                   = -2,    /* 网络连接错误 */
    AIFunSDKRequestError_Param                     = -10,   /* 参数错误 */
    AIFunSDKRequestError_Not_Init                  = -20,   /* 还没有初始化 */
    AIFunSDKRequestError_Init_Failed               = -21,   /* 初始化失败*/
    
    AIFunSDKRequestError_Not_login                 = -301,  /* 没有登录用户 */
    AIFunSDKRequestError_Had_login                 = -302,  /* 已有登录用户 */
    AIFunSDKRequestError_Logout_failed             = -303,  /* 用户登出失败 */
    AIFunSDKRequestError_Login_failed              = -304,  /* 用户登录失败 */

} AIFunDKRequestError_Code;

/**
 *  授权，分享，UserProfile等操作的回调
 *
 *  @param result 表示回调的结果
 *
 *  @param error  表示回调的错误码
 */
typedef void (^GSDKRequestCompletionHandler)(id result,NSError *error);
/**
 *  用户登录的回调
 *
 *  @param result 表示回调的结果
 *
 *  @param error  表示回调的错误码
 */
typedef void (^GSDKLoginCompletionHandler)(id result,NSError *error);

#endif /* AIFunSDKDefines_h */
