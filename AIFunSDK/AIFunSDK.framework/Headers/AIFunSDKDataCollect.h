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





NS_ASSUME_NONNULL_END
