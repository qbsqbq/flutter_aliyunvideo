//
//  CCBAlertSMBVerifyView.h
//  CCBClientV2
//
//  Created by zhuqimin on 14-11-19.
//  Copyright (c) 2014年 llbt. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>


typedef enum {
    ////验证声密保，没有小型手势图形提示框
    SMBViewType_Verify = 0,
    //设置声密保，有小型手势图形提示框
    SMBViewType_Setting,
    //重置声密保
    SMBViewType_Resetting,
    //登录之后重置声密保,其实我也不知道这是什么
    SMBViewType_LoginResetting,
    //
    SMBViewType_NewSwitchSetting
} SMBViewType;

typedef enum {
    VPVerifySuccessTag,
    VPVerifyFailTag,
    VPVerifyAgainTag,
    VPVerifyErrorTag,
    VPVerifyCancelTag,
    VPSetSuccessTag,
    VPSetFailTag,
    VPSetRollbackTag,
    VPSetStartTag
} VPAlertType;

@protocol SMBRecordViewDelegate <NSObject>

- (void)showSMBAlert:(NSString *)title withError:(CCBBaseError*)error withButton:(NSArray *)button withTag:(VPAlertType)tag;
@end

@interface CCB_SMBRecordView_Voiceprint : CCBView<AVAudioRecorderDelegate>

@property (retain, nonatomic) NSString* title;

@property (nonatomic, retain) NSString* verifyFailMsg;

@property (nonatomic, assign) BOOL isReplacable;

@property (copy, nonatomic) void (^verifyPassBlock)(NSString *param);
@property (copy, nonatomic) void (^verifyFailBlock)();
@property (copy, nonatomic) void (^settingDismissBlock)(BOOL);
//
@property (copy, nonatomic) void (^settingErrorCallback)();

@property(nonatomic,strong) id<SMBRecordViewDelegate> delegate;
@property(nonatomic,strong) void (^alertCallback)(NSDictionary *dic);
@property(nonatomic,strong) NSString *alertTitle;
@property(nonatomic,strong) NSString *alertMsg;
@property(nonatomic,strong) NSArray *alertBtn;

@property (nonatomic, assign) BOOL verifySucess;
@property (nonatomic,assign) NSUInteger verifyTryTimes;

@property (nonatomic, assign) BOOL loading;

- (id)initWithType:(SMBViewType)type frame:(CGRect)frame;
- (void)getVerificationTextFromMBS;
- (void)rollBackProgress;
- (void)getText;
- (void)isVoiceprintExistedInMBS;
@end
