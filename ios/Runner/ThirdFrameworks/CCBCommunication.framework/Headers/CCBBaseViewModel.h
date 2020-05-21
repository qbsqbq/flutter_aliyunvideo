//
//  CCBBaseViewModel.h
//  CCBMobileBank
//
//  Created by Ansonyc on 16/4/5.
//  Copyright © 2016年 CCB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCBCommunicationProtocol.h"
#import "CCBCommandManager.h"

@class CCBBaseModel;
@class CCBBaseError;
@class CCBBaseViewModel;

@protocol CCBViewModelDelegate <NSObject>
@optional
/**
 *  VM访问接口时出错了
 *
 *  @param viewModel    发出此消息的VM
 *  @param requestModel 出错的请求对象
 *  @param error        错误描述
 */
- (void)viewModel:(CCBBaseViewModel *)viewModel
    requestFailed:(CCBBaseRequestModel *)requestModel
            error:(CCBBaseError *)error;

/**
 *  VM访问接口成功返回
 *
 *  @param viewModel 发出此消息的VM
 *  @param input     接口访问输入的对象
 *  @param output    接口返回的数据对象
 */
- (void)viewModel:(CCBBaseViewModel *)viewModel
          request:(CCBBaseRequestModel *)input
      didFinished:(CCBBaseModel *)output;

@end

@interface CCBBaseViewModel : NSObject<CCBCommandManagerDelegate>
/**
 *  请使用本方法构造
 *
 *  @param delegate 请把本model对应的VC传进来
 *
 *  @return 当前实例
 */
- (instancetype)initWithDelegate:(id<CCBViewModelDelegate>)delegate;

/**
 *  委托
 */
@property (nonatomic, weak) id<CCBViewModelDelegate> delegate;

/**
 *  业务控制器的接口请求管理器
 */
@property (nonatomic, strong) CCBCommandManager *requestManager;

/** *  是否正在加载数据 */
@property (nonatomic, assign) BOOL loading;


@end
