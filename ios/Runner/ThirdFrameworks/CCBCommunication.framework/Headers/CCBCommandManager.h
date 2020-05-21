//
//  CCBCommandManager.h
//  CCBMobileBank
//
//  Created by Ansonyc on 16/4/1.
//  Copyright © 2016年 CCB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HttpRequestDelegate.h"
#import "CCBCommunicationProtocol.h"

typedef NS_ENUM(NSInteger, CCBCommunicationMode) {
    CCBCommunicationModeSimulator,  // 使用挡板
    CCBCommunicationModeNetwork     // 使用真实网络请求
};


@class CCBBaseViewModel;
@class CCBBaseRequestModel;
@interface CCBCommandManager : NSObject

NS_ASSUME_NONNULL_BEGIN

@property (nonatomic ,strong) CCBBaseViewModel *viewModel;

/** *  委托 */
@property (nonatomic, weak) id<CCBCommandManagerDelegate > delegate;
/**
 *  发送请求
 *
 *  @param requestModel 交易输入参数
 *  @param type         后段类型
 *
 *  @return 成功提交发送请求返回YES，否则返回NO
 */
- (BOOL)requestWithRequestModel:(nonnull CCBBaseRequestModel *)requestModel requestType:(HttpRequestType)type;


/**
 *  设置交易模式 是否使用挡板
 *
 *  @param mode 是否使用挡板
 */
- (void)setCommunicationMode:(CCBCommunicationMode)mode;

/**
 *  测试环境交易域名，生产环境不可设置
 *
 *  @param domainDict 域名字典，key、value映射列表，com_domain：网站域名，safeConsole_domain：安全网关域名，ebank_domain：网银域名，mbs_domain：手机银行域名
 */
+ (void)setRequestDomainDict:(NSDictionary *)domainDict;


/**
 *  E路护航校验
 *
 *  @param uniqueid 客户身份信息。
 *  @param secret 正确secret信息（建行提供）。
 */
+ (void)CCBSafeCheckSign:(NSString *)uniqueid appSecret:(NSString *)secret;

/**
 *  获取网站cookie
 *
 *  @param complete 回调,responseData正常返回值为cookie类型是NSString；如报错，返回类型是CCBBaseError。
 */
+ (void)requestForCookie:(void(^_Nullable)(id responseData))complete;

/**
 *  将模型转成字典
 *  @return 字典
 */
+ (NSMutableDictionary *)mj_keyValues:(id)obj;
+ (NSMutableDictionary *)mj_keyValuesWithKeys:(NSArray *)keys modelObject:(id)obj;
+ (NSMutableDictionary *)mj_keyValuesWithIgnoredKeys:(NSArray *)ignoredKeys modelObject:(id)obj;

/**
 *  通过字典来创建一个模型
 *  @param  keyValues 字典(可以是NSDictionary、NSData、NSString)
 *  @param  name 模型名
 *  @return 新建的对象
 */
+ (instancetype)objectWithKeyValues:(id)keyValues modelName:(NSString *)name;

/**
 *  通过字典数组来创建一个模型数组
 *  @param keyValuesArray 字典数组(可以是NSDictionary、NSData、NSString)
 *  @param  name 模型名
 *  @return 模型数组
 */
+ (NSMutableArray *)mj_objectArrayWithKeyValuesArray:(id)keyValuesArray modelName:(NSString *)name;

/**
 *  将属性名换为其他key去字典中取值
 *
 *  @param modelName 模型名
 *
 *  @param dict 属性名替换字典
 */
+ (void)mj_setupReplacedKeyFromPropertyName:(NSString *)modelName replacedKeyFromPropertyNameDict:(NSDictionary *)dict;

/**
 *  数组中需要转换的模型类
 *
 *  @param  modelName 模型名
 *  @param dict 需要转换的模型类字典
 */
+ (void)mj_setupObjectClassInArray:(NSString *)modelName objectClassInArrayDict:(NSDictionary *)dict;

NS_ASSUME_NONNULL_END

@end
