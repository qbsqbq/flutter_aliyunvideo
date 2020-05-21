//
//  CCBLivnessInterfaceHandler.h
//  CCBMobileBank
//
//  Created by zhuqimin on 17/3/8.
//  Copyright © 2017年 ccbdeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCB_FaceModelVerify_Result.h"
//#import "CCBBaseViewModel.h"
//#import "CCBBaseError.h"
#import "CCBViewController.h"

@interface CCBLivnessInterfaceHandler : CCBBaseViewModel

@property (nonatomic, strong) CCBBaseError *error;
@property (nonatomic, strong) NSNumber *qualityNumber;
@property (nonatomic, assign)  bool isThreeAction;
/*
 *用于获取三个随机动作序列
 */
+ (NSString*)getThreeRandomVerifyActions;

/*
 * 客户是否设置了优先使用刷脸验证
 */
+ (BOOL)isPreferLivnessVerify;

/*
 * 是否提示成功页刷脸广告
 */
+ (BOOL)shouldShowLivnessGuide;

/*
 * 是否在成功页提示刷脸弹框
 */
+ (BOOL)shouldShowAlertInSuccessView;

/*
 * 是否在首页提示刷脸引导
 */
+ (BOOL)shouldShowMainPageLivnessGuide;

/*
 * 设置不再提示成功页刷脸弹框
 */
+ (void)setNotShowAlertAgain;

/*
 * 设置不再提示首页刷脸弹框
 */
+ (void)setNotShowMainPageAgain;

+ (BOOL)shouldVerifyLivnessWithBioSwithDic:(NSDictionary*)switchDict bindFlag:(NSString*)bindFlag;

+ (instancetype)getInstance;

- (void)createLivnessModelInViewController:(CCBViewController*)vc withCallback:(void (^)(BOOL isSuccess, CCBBaseError* error))callback;

- (void)canVerifyWithLivness:(void(^)(BOOL isExisted, CCBBaseError *error))callback;

- (void)verifyInViewController:(CCBViewController*)vc WithLivness:(void(^)(BOOL isSuccess, CCBBaseError *error, CCB_FaceModelVerify_Result* model))callback;

- (void)pickInViewController:(CCBViewController*)vc WithLivness:(void(^)(BOOL isSuccess, CCBBaseError *error, NSData* imgData))callback;

- (void)compareInViewController:(CCBViewController*)vc withCustID:(NSString*)custID callback:(void (^)(BOOL isSuccess, CCBBaseError *error, CCB_FaceModelVerify_Result *model))callback;

- (NSString*)getLivnessVerifyEncryptedString;

@end
