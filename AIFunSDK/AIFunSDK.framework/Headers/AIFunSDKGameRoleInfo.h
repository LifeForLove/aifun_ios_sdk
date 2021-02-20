//
//  AIFunSDKGameRoleInfo.h
//  AIFunSDK
//
//  Created by shannon on 2021/2/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AIFunSDKGameRoleInfo : NSObject

@property (nonatomic,copy) NSString *serverId;         //服务器Id，必填
@property (nonatomic,copy) NSString *serverName;       //服务器名称，必填
@property (nonatomic,copy) NSString *gameRoleName;     //角色名，必填
@property (nonatomic,copy) NSString *gameRoleID;       //角色ID，必填
@property (nonatomic,copy) NSString *gameUserBalance;  //玩家虚拟货币余额，必填，可随意
@property (nonatomic,copy) NSString *vipLevel;         //玩家vip等级，必填，可随意
@property (nonatomic,copy) NSString *gameUserLevel;    //玩家等级，必填，可随意
@property (nonatomic,copy) NSString *partyName;        //公会名称，必填，可随意
@property (nonatomic, copy) NSString * creatTime;      //角色创建时间(10位时间戳)，必填,没有传0
@property (nonatomic, copy) NSString * fightPower;     //战力，可不传
@property (nonatomic, copy) NSString * profession;     //角色职业, 可不传

@end

NS_ASSUME_NONNULL_END
