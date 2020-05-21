//
//  CCBBaseError.h
//  CCBMobileBank
//
//  Created by mac on 16/4/19.
//  Copyright © 2016年 CCB. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN NSString *CCBCommunicationErrorDomain;
FOUNDATION_EXTERN NSString *CCBCommunicationErrorCode;
FOUNDATION_EXTERN NSString *CCBCommunicationErrorMsg;
FOUNDATION_EXTERN NSString *CCBBaseErrorTransformSymbol;

@interface CCBBaseError : NSError

/**
 *  错误域
 */
@property(nonatomic,strong,nullable) NSString *errDomain;
/**
 *  错误码
 */
@property(nonatomic,strong,nullable) NSString *errCode;
/**
 *  错误内容
 */
@property(nonatomic,strong,nullable) NSString *errMsg;


/**
 *  初始化方法
 *
 *  @param errMsg  错误描述
 *  @param errCode 错误码
 *
 *  @return CCBBaseError对象
 */
- (nullable instancetype)initWithErrorMsg:(nullable NSString*)errMsg ErrorCode:(nullable NSString*)errCode;

/**
 *  初始化方法
 *
 *  @param errDomain  错误域（主要有两种：
                                    通讯返回错误域：CCBCommunicationErrorDomain
                                    用户自定义错误域：自定义字段(只要不等于CCBCommunicationErrorDomain)）
 *  @param errMsg  错误描述(非空)
 *  @param errCode 错误码
 *
 *  @return CCBBaseError对象
 */
- (nullable instancetype)initWithDomain:(nullable NSString *)errDomain  ErrorMsg:(nullable NSString *)errMsg ErrorCode:(nullable NSString *)errCode;

/**
 格式化输出值数组。
 注意：使用限制，当前只支持格式化符号'%@'输出。
 */
@property (nonatomic,copy,nullable)NSArray *formatValues DEPRECATED_MSG_ATTRIBUTE("将被遗弃，请使用新的属性formatParameters。");
@end

#pragma mark - Extension For Custom format error message
@interface CCBBaseError ()
/**
 格式化输出字典。
 
 限制：需替换的字符串带有前后缀，其值为定义的全局字符串变量CCBBaseErrorTransformSymbol值。CCBBaseErrorTransformSymbol值当前为"$@"。
 示例：formatParameters = @{@"key": @"Lucy"}。 与之匹配的错误提示语格式为: 你好，$@key$@。 则错误提示语最终显示为: 你好，Lucy。
 */
@property(nonatomic,copy,nullable)NSDictionary *formatParameters;
@end

NS_ASSUME_NONNULL_END
