//
//  CCBFunctionUtil.h
//  WapECommerceTest
//
//  Created by mac on 2017/12/25.
//  Copyright © 2017年 mac. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    NotAllowType = 0,//不可用
    AllowType = 1,//可用
    IndeterminacyType = 2,//不确定
    
}PolicyAllowType;

@interface CCBFunctionUtil : NSObject

/**
 *  设置版本号，通讯httpsHeader要上送的，由外部设置
 *  @param aVersion 版本号
 */
+(void)setVersion:(NSString *)aVersion;

/**
 *  获取版本号
 */
+(NSString *)getVersion;

/**
 *  日期转换为字符串
 *
 *  @param date     日期
 *  @param formater 格式，如："yyyyMMddHHmmssSS"
 *
 *  @return 格式化日期字符串
 */
+ (NSString*)stringWithDate:(NSDate*)date Formater:(NSString*)formater;
+ (PolicyAllowType)whiteCustPolicy:(NSString *)policyName;
@end
