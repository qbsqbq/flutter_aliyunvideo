//
//  CCB_13_VC_SetVoiceprint.h
//  CCBMobileBank
//
//  Created by pengchenyi on 16/7/6.
//  Copyright © 2016年 CCB. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "ComConstants.h"
#import "CCBViewController.h"

typedef enum {
    ////验证声密保，没有小型手势图形提示框
    CCBSMBViewType_Verify = 0,
    //设置声密保，有小型手势图形提示框
    CCBSMBViewType_Setting,
    //重置声密保
    CCBSMBViewType_Resetting,
    //登录之后重置声密保,其实我也不知道这是什么
    CCBSMBViewType_LoginResetting,
    //
    CCBSMBViewType_NewSwitchSetting
} CCBSMBViewType;

@interface CCB_VC_SetVoiceprint : CCBViewController

@property (nonatomic, assign) BOOL setSuccess;
@property (nonatomic, copy) void (^callbackBlock)(BOOL success);

- (instancetype)initWithType:(CCBSMBViewType)type;

@end
