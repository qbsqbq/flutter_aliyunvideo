//
//  CCBBaseRequestModel.h
//  CCBMobileBank
//
//  Created by mac on 16/4/15.
//  Copyright © 2016年 CCB. All rights reserved.
//

#import <Foundation/Foundation.h>


//#import <CCBCommunication/HttpRequestDelegate.h>
/**
 *  所有接口输入对象模型的基类
 */
@interface CCBBaseRequestModel : NSObject

/**
 *  报文头字段
 */
@property (nonatomic, strong) NSDictionary *headDict;

/**
 *  通讯报文头字段
 */
@property (nonatomic, strong) NSDictionary *httpsHeadDict;

/**
 *  服务端交易码
 */
@property (nonatomic, strong) NSString *txCode;

/**
 *  交易标示，可以区分同一交易码不同请求参数的应答报文体
 */
@property (nonatomic, strong) NSString *requestID;

/**
 *  保存本请求的类型
 */
@property (nonatomic, assign) NSInteger requestType;

/**
 *  请求方式，0为GET，1为POST,HttpRequestTypeNewClient、HttpRequestTypeNewClientForOther、HttpRequestTypeNewUIClient默认为post，其他类型为get.
 */
@property (nonatomic ,assign) int reqMethod;

/**
 *  请求参数是否加密，默认YES
 */
@property (nonatomic, assign) BOOL isParamsEncrypt;

/**
 *  每一个请求参数是否编码，默认NO
 */
@property (nonatomic ,assign) BOOL isEveryParamEncode;

/**
 *  请求参数串是否编码，默认YES
 */
@property (nonatomic ,assign) BOOL isParamsStringEncode;

@end
