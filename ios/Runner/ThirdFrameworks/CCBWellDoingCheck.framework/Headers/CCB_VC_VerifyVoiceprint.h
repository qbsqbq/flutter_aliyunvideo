//
//  CCB_13_VC_VerifyVoiceprint.h
//  CCBMobileBank
//
//  Created by zhuqimin on 16/7/21.
//  Copyright © 2016年 CCB. All rights reserved.
//
#import "CCBViewController.h"


typedef NS_ENUM(NSUInteger, CCBVoiceprintVerifyStatus) {
    CCBVoiceprintVerifySuccess,
    CCBVoiceprintVerifyFail,
    CCBVoiceprintVerifyCancel,
    CCBVoiceprintVerifyError,
    CCBVoiceprintVerifyShift,
    CCBVoiceprintVerifyToLivness,
};

@interface CCB_VC_VerifyVoiceprint : CCBViewController

@property (nonatomic, copy) void (^callbackBlock)(BOOL success, CCBBaseError *error, CCBVoiceprintVerifyStatus);

@property (nonatomic, assign) BOOL canVerifySMS;

@property (nonatomic, assign) BOOL canVerifyLivness;

@property (nonatomic, strong) NSString *verifyFailMsg;

- (void) showSMBAlert:(NSString *)title withMsg:(NSString *)msg withButton:(NSArray *)button withTag:(NSInteger)tag;

- (void) goInCodeFile;

@end
