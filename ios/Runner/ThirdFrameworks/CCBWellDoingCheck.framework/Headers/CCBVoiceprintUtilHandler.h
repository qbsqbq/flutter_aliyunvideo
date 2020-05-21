//
//  CCBVoiceprintUtilHandler.h
//  CCBMobileBankFoundation
//
//  Created by zhuqimin on 16/10/25.
//  Copyright © 2016年 CCB. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CCBVoiceprintUtilHandler : NSObject

/**
 *  获取对象实体
 *
 *  @return handler
 */
+ (instancetype)getInstance;

/**
 *  录音时候音量曲线图
 *
 *  @return 曲线图
 */
- (UIView*)generateMeterViewWithFrame:(CGRect)frame;

/**
 *  开始录音
 */
- (void)startRecord;

/**
 *  结束录音，有0.2秒延迟
 */
- (void)stopRecord;

/**
 *  获取录音文件保存路径
 *
 *  @return 录音文件保存路径
 */
- (NSString*)getFilePath;

/**
 *  权限block，若没有录音权限则调用该block
 */
@property (nonatomic, copy)PermissionBlock permissionBlock;

@end
