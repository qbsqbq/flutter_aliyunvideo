//
//  CCBCommunicationProtocol.h
//  CCBMobileBankFoundation
//
//  Created by Ansonyc on 16/4/22.
//  Copyright © 2016年 CCB. All rights reserved.
//

@class CCBBaseModel;
@class CCBBaseRequestModel;
@class CCBBaseError;

/**
 *  接口访问的回调
 */
@protocol CCBCommandManagerDelegate <NSObject>

@optional
/**
 *  接口访问返回
 *
 *  @param input  接口的输入参数
 *  @param output 接口返回的数据
 *  @param error  接口访问出现的错误
 */
- (void)requestFinished:(nullable CCBBaseRequestModel *)input
                 output:(nullable CCBBaseModel *)output
                  error:(nullable CCBBaseError *)error;
@end


