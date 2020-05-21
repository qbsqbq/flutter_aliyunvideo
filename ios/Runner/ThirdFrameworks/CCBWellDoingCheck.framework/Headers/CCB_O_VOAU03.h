//
//  CCB_O_VOAU03.h
//  CCBMobileBank
//
//  Created by zhuqimin on 16/7/25.
//  Copyright © 2016年 CCB. All rights reserved.
//
//#import "CCBBaseModel.h"


@interface CCB_O_VOAU03 : CCBBaseModel
/** 返回值 */
@property (nonatomic, strong) NSString *Ret_Trgt_Cd;

/** 返回信息 */
@property (nonatomic, strong) NSString *Rslt_Ret_Inf;

/** 有效时长 */
@property (nonatomic, strong) NSString *Rmrk_4_Rcrd_Cntnt;

/** 声纹预留ID */
@property (nonatomic, strong) NSString *Tokn_Ctfn_ID;

/** 声纹预留文本 */
@property (nonatomic, strong) NSString *Rmrk_2_Rcrd_Cntnt;

/** 文本索引 */
@property (nonatomic, strong) NSString *Rmrk_3_Rcrd_Cntnt;

/** 预留字段 */
@property (nonatomic, strong) NSString *Rmrk_1_Rcrd_Cntnt;

@end
