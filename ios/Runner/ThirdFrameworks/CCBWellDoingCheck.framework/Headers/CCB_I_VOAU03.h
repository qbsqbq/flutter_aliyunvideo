//
//  CCB_I_VOAU03.h
//  CCBMobileBank
//
//  Created by zhuqimin on 16/7/25.
//  Copyright © 2016年 CCB. All rights reserved.
//

//

@interface CCB_I_VOAU03 : CCBBaseRequestModel

/** 时间戳 */
@property (nonatomic, strong) NSString *SYSTEM_TIME;

/** 操作类型 */
@property (nonatomic, strong) NSString *Txn_TpCd;

/** 声纹预留ID */
@property (nonatomic, strong) NSString *Tokn_Ctfn_ID;

/** 客户号 */
@property (nonatomic, strong) NSString *Cst_ID;

/** 设备信息 */
@property (nonatomic, strong) NSString *Tokn_Expd_Inf;

/** 声纹预留文本类型 */
@property (nonatomic, strong) NSString *MgTp_Ctlg_ECD;

/** 声纹预留文本 */
@property (nonatomic, strong) NSString *Rmrk_2_Rcrd_Cntnt;

/** 文本索引 */
@property (nonatomic, strong) NSString *Rmrk_3_Rcrd_Cntnt;

/** 语音 */
@property (nonatomic, strong) NSString *base64_ECD_Txn_Inf;

/** 语音长度 */
@property (nonatomic, strong) NSString *Data_Cntnt_Len;

/** 预留字段 */
@property (nonatomic, strong) NSString *Rmrk_1_Rcrd_Cntnt;



@end
