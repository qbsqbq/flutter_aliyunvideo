//
//  eAuth.h
//  eAuth
//
//  Created by csl on 16/12/2.
//  Copyright © 2016年 tendyron. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

/**
 * 活体检测动作序列
 * @"MOUTH NOD YAW BLINK"
 */
extern  NSString *   const      keAuth_LivenessSequence;

/**
 * 模块超时时间
 * 可不传，默认
 */
extern  NSString *   const      keAuth_LivenessTimeOutInterval;

/**
 * 设置活体检测复杂度
 *
 */
extern  NSString *   const      keAuth_LivenessFaceComplexity;

/**
 * 设置活体检测的阈值
 * 可不传，默认
 */
extern  NSString *   const      keAuth_LivenessHacknessThresholdScore;

/**
 * 是否进行眉毛遮挡的检测，默认不检测
 *
 */
extern  NSString *   const      keAuth_LivenessBrowOcclusion;

/**
 * 语音提示状态，默认开启
 *
 */
extern  NSString *   const      keAuth_LivenessVoicePrompt;

/**
 *活体检测复杂度
 */
typedef NS_ENUM(NSUInteger, TDRIDLivenessFaceComplexity) {
    /** 简单,活体阈值低 */
    TDRIDLiveness_COMPLEXITY_EASY,
    /** 一般,活体阈值较低 */
    TDRIDLiveness_COMPLEXITY_NORMAL,
    /** 较难,活体阈较高 */
    TDRIDLiveness_COMPLEXITY_HARD,
    /** 困难,活体阈值高 */
    TDRIDLiveness_COMPLEXITY_HELL
};
/**
 * 检测模块类型
 */
typedef NS_ENUM(NSInteger, TDRIDLivenessFaceDetectionType) {
    /** 眨眼检测 */
    TDRIDLiveness_BLINK,
    /** 上下点头检测 */
    TDRIDLiveness_NOD,
    /** 张嘴检测 */
    TDRIDLiveness_MOUTH,
    /** 左右转头检测 */
    TDRIDLiveness_YAW
};

/**
 活体检测后，数据回调

 @param livenessInfoDic 获取每个步骤的一帧数据组成的数组 键值[@"picture"]
 @param error 错误信息
 */
typedef void (^LiveNessInfoCallback)(NSDictionary*livenessInfoDic,NSError* error);

@interface eAuth : NSObject


@property (nonatomic,copy) LiveNessInfoCallback livenessInfo;


/**
 初始化

 @param dicCustomConfig 配置选项 见外部字符串定义
 @return 实例对象
 */
- (instancetype) initAuth:(NSDictionary*)customDictionary;


/**
 获取SDK版本号

 @return 版本号
 */
- (NSString *)eAuthSDKVesion;


/**
 活体检测

 @param livenessinfocb 活体检测回调
 @return 活体检测的UINavigationController
 */
- (id)eAuthLivenessInfoCallback:(LiveNessInfoCallback)livenessinfocb;

@end
