//
//  CCB_I_VOAU05.h
//  CCBMobileBank
//
//  Created by zhuqimin on 16/7/25.
//  Copyright © 2016年 CCB. All rights reserved.
//

//

@interface CCB_I_VOAU05 : CCBBaseRequestModel

/** 时间戳 */
@property (nonatomic, strong) NSString *SYSTEM_TIME;

/** 渠道号 */
@property (nonatomic, strong) NSString *CHNL_NO;

/** 操作类型 */
@property (nonatomic, strong) NSString *Txn_TpCd;

/** 客户号 */
@property (nonatomic, strong) NSString *Cst_ID;

/** 设备信息 */
@property (nonatomic, strong) NSString *Tokn_Expd_Inf;

/** 身份验证ID */
@property (nonatomic, strong) NSString *Tokn_Ctfn_ID;

/** 身份验证文本类型 */
@property (nonatomic, strong) NSString *MgTp_Ctlg_ECD;

/** 语音 */
@property (nonatomic, strong) NSString *base64_ECD_Txn_Inf;

/** 语音长度 */
@property (nonatomic, strong) NSString *Data_Cntnt_Len;

/** 预留字段 */
@property (nonatomic, strong) NSString *Rmrk_1_Rcrd_Cntnt;

@end
