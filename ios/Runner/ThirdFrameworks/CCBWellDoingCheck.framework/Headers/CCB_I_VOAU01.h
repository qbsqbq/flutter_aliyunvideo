//
//  CCB_I_VOAU01.h
//  CCBMobileBank
//
//  Created by zhuqimin on 16/7/25.
//  Copyright © 2016年 CCB. All rights reserved.
//

//

@interface CCB_I_VOAU01 : CCBBaseRequestModel

/** 时间戳 */
@property (nonatomic, strong) NSString *SYSTEM_TIME;

/** 操作类型 */
@property (nonatomic, strong) NSString *Txn_TpCd;

/** 客户号 */
@property (nonatomic, strong) NSString *Cst_ID;

/** 设备信息 */
@property (nonatomic, strong) NSString *Tokn_Expd_Inf;

@end
