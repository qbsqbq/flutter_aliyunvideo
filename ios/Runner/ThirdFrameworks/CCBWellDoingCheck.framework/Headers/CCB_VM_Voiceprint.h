//
//  CCB_13_VM_Voiceprint.h
//  CCBMobileBank
//
//  Created by pengchenyi on 16/7/4.
//  Copyright © 2016年 CCB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCB_O_PC0002.h"
#import "CCB_O_PC0004.h"

@interface CCB_VM_Voiceprint : CCBBaseFormViewModel

@property(nonatomic,strong)CCB_O_PC0002 *O_PC0002;
@property(nonatomic,strong)CCB_O_PC0004 *O_PC0004;

@property(nonatomic,strong)CCBSwitchFormItem *openSwitch;
@property(nonatomic,assign)BOOL deviceSupport;

@property(nonatomic,strong)NSMutableArray *recordIdArray;
@property (copy, nonatomic) void(^responseBlock)(NSDictionary *dic);
//TODO:
//- (void)updateItemArray;
//- (BOOL)mainBind;
//- (BOOL)modelExist;
//- (BOOL)switchOpen;
//- (BOOL)everUse;
//- (void)isDeviceSupport;
//- (void)requestOpenPC0002;
//- (void)requestClosePC0002;
//- (void)requestOpenPC0004;
//- (void)requestCloseVoiceprintLogin;
@end
