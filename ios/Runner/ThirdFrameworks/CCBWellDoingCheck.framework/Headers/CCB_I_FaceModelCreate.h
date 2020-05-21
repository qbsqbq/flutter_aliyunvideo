//
//  CCB_I_LIV02.h
//  CCBMobileBank
//
//  Created by zhuqimin on 17/3/1.
//  Copyright © 2017年 ccbdeveloper. All rights reserved.
//



@interface CCB_I_FaceModelCreate : CCBBaseRequestModel

/** 客户端当前时间 */
@property (nonatomic, strong) NSString *SYSTEM_TIME;

/** 客户端唯一标识 */
@property (nonatomic, strong) NSString *HARDWARESN;

/** 认证类型 */
@property (nonatomic, strong) NSString *Txn_TpCd;

///** 系统渠道号 */
//@property (nonatomic, strong) NSString *Stm_Ahn_ID;

/** P6客户号 */
@property (nonatomic, strong) NSString *Cst_ID;

///** 平台客户号 */
//@property (nonatomic, strong) NSString *Cst_PlatID;

/** 客户名称 */
@property (nonatomic, strong) NSString *Cst_Nm;

/** 证件类型 */
@property (nonatomic, strong) NSString *CrdTp_Cd;

/** 证件号码 */
@property (nonatomic, strong) NSString *Crdt_No;

/** 手机号码 */
@property (nonatomic, strong) NSString *Rmrk_1_Rcrd_Cntnt;

/** 特征值 */
@property (nonatomic, strong) NSString *base64_ECD_Txn_Inf;

/** 图片 */
@property (nonatomic, strong) NSString *base64_Ecrp_Txn_Inf;



@end
