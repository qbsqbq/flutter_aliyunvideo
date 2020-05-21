//
//  CCB_I_MPVoiceprintModelManager.h
//  CCBUIKit
//
//  Created by zhuqimin on 2018/1/9.
//  Copyright © 2018年 CCB. All rights reserved.
//



@interface CCB_I_MPVoiceModelManager : CCBBaseRequestModel

/** 客户端当前时间 */
@property (nonatomic, strong) NSString *SYSTEM_TIME;

/** 客户端唯一标识 */
@property (nonatomic, strong) NSString *HARDWARESN;

/** 操作类型 */
@property (nonatomic, strong) NSString *Txn_TpCd;

/** 客户号 */
@property (nonatomic, strong) NSString *Cst_ID;

/** 设备信息 */
@property (nonatomic, strong) NSString *Tokn_Expd_Inf;


@end
