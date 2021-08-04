//
//  AIFunSDKDataCollect.h
//  AIFunSDK
//
//  Created by shannon on 2021/3/19.
//

#import <Foundation/Foundation.h>
#import "AIFunSDKDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface AIFunSDKFirstData : NSObject
// 停留时长
@property (nonatomic,assign) AIFunSDKFirstStayTimeType stayTimeType;
@end

@interface AIFunSDKGuideData : NSObject
// 引导名称 例：新手引导
@property (nonatomic,copy) NSString *guideName;
// 到达引导的步数，由接入方定义 （当eventType == AIFunDKGuideType_Step） 时传入改字段
@property (nonatomic,assign) NSInteger pageNo;
// 事件类型
@property (nonatomic,assign) AIFunSDKGuideType guideType;
@end

@interface AIFunSDKMissionData : NSObject
// 事件类型
@property (nonatomic,assign) AIFunSDKMissionType missionType;
// 关卡名称
@property (nonatomic,copy) NSString *missionId;
@end

@interface AIFunSDKGameRoleData : NSObject
// 玩家等级 (非必填)
@property (nonatomic, assign) NSInteger roleLevel;
// 角色名称 (非必填)
@property (nonatomic, copy) NSString *cpRoleName;
// 区服id (非必填)
@property (nonatomic, copy) NSString *cpServerId;
// 角色创建时间 (非必填)
@property (nonatomic, copy) NSString *cpRoleCreateTime;
// 角色id (非必填)
@property (nonatomic, copy) NSString *cpRoleId;
// 区服名称 (非必填)
@property (nonatomic, copy) NSString *cpServerName;
// 战斗力 (非必填)
@property (nonatomic, assign) NSInteger comatEffectiveness;
@end


NS_ASSUME_NONNULL_END
