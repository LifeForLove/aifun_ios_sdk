//
//  AIFunSDKDefines.h
//  AIFunSDK
//
//  Created by shannon on 2021/2/18.
//

#ifndef AIFunSDKDefines_h
#define AIFunSDKDefines_h

typedef enum {
    AIFunSDKError_None                      = 0,     /* 没有错误 */
  
    AIFunSDKError_Init_Failed               = -300,   /* 初始化失败*/
    AIFunSDKError_Not_Login                 = -301,  /* 没有登录用户 */
    AIFunSDKError_Logout_Failed             = -303,  /* 用户登出失败 */
    AIFunSDKError_Login_Failed              = -304,  /* 用户登录失败 */
    AIFunSDKError_AuthName_Failed           = -305,  /* 用户实名认证失败 */
    
    AIFunSDKError_Paying                    = 70101, /* 购买中 */
    AIFunSDKError_Jailbroken                = 70102, /* 越狱设备 */
    AIFunSDKError_Parameter                 = 70103, /* 参数错误 */
    AIFunSDKError_Permission                = 70104, /* 无权限 */
    AIFunSDKError_ProductId                 = 70105, /* 没有购买的物品 */
    AIFunSDKError_Receipt                   = 70106, /* 凭据错误 */
    AIFunSDKError_VerifyInvalid             = 70107, /* 验证订单失败 */
    AIFunSDKError_Net                       = 70108, /* 网络错误 */
    AIFunSDKError_NotRegistered             = 70109, /* 未注册IAP */
    AIFunSDKError_HasUnfinishedTransaction  = 70110, /* 有未验证完的订单 */
    AIFunSDKError_Products_Null             = 70111, /* 未查询到该商品 */
    AIFunSDKError_Pay_Error                 = 70112, /* 支付失败 */
    
    AIFunSDKError_PayTypeNull_Error         = 70113, /* 未找到后台设置的支付方式 */
    AIFunSDKError_AppNotExits_Error         = 70114, /* APP不存在 */
    AIFunSDKError_ProductId_Error           = 70115, /* 不存在此计费点 */
    AIFunSDKError_PayPrice_Error            = 70116, /* 价格错误 */
    AIFunSDKError_MinAge_Error              = 70117, /* 未达到年龄，不能付费 */
    AIFunSDKError_TrueName_Error            = 70118, /* 未完成实名认证，不能付费 */
    AIFunSDKError_MaxAmount_Error           = 70119, /* 未成年人，付费金额大于规定金额 */
    AIFunSDKError_MaxMonthAmount_Error      = 70120, /* 未成年人，本月付费已达上限 */
    
} AIFunDKError_Code;

typedef enum {
    AIFunSDKStayTimeTypeOneMinute, //首次进入停留一分钟
    AIFunSDKStayTimeTypeTwoMinute, //首次进入停留两分钟
    AIFunSDKStayTimeTypeFiveMinutes, //首次进入停留五分钟
    AIFunSDKStayTimeTypeTenMinutes, //首次进入停留十分钟
} AIFunSDKFirstStayTimeType;//首次进入事件

typedef enum {
    AIFunSDKGuideTypeStart, //引导开始
    AIFunSDKGuideTypeStep, //到达特定引导步骤 到达指定步骤 徐传入pageNo字段
    AIFunSDKGuideTypeSkip, //跳过引导
    AIFunSDKGuideTypeComplete, //完成引导
} AIFunSDKGuideType;//引导事件

typedef enum {
    AIFunSDKMissionTypeStart, //关卡开始
    AIFunSDKMissionTypeHeart, //心跳
    AIFunSDKMissionTypeFail, //关卡失败
    AIFunSDKMissionTypeComplete, //通关成功
} AIFunSDKMissionType;//关卡事件类型


#endif /* AIFunSDKDefines_h */
 
