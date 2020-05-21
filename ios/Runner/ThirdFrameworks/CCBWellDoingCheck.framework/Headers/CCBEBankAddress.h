//
//  CCBEBankAddress.h
//  CloudAuthentication
//
//  Created by zhuqimin on 2018/5/31.
//  Copyright © 2018年 ccbMobileBank. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CCBEBankAddress : NSObject

//供具体功能保存通道使用，可添加一种请求类型：dynamicrequest，该请求类型的交易使用设置的通道号。若未有通道号的取随机通道
+ (void)saveDynamicTransUrl:(NSString*)url;
+ (NSString*)getDynamicTransUrl;

+ (NSString*)tmpGetEBankChannel;
@end
