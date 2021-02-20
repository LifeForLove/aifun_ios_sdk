//
//  AIFunSDKPayInfo.h
//  AIFunSDK
//
//  Created by shannon on 2021/2/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AIFunSDKPayInfo : NSObject

@property(nonatomic,copy) NSString *goodsID;    //商品ID IAP时为苹果开发者后台配置的商品id，必填
@property(nonatomic,copy) NSString *productName;  //商品名称，必填
@property(nonatomic,assign) NSUInteger count;     //商品数量，必填
@property(nonatomic,assign) float amount;         //商品总价,必填，这个很重要

@end

NS_ASSUME_NONNULL_END
