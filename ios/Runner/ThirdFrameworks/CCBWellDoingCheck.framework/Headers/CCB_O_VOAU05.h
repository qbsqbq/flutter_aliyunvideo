//
//  CCB_O_VOAU05.h
//  CCBMobileBank
//
//  Created by zhuqimin on 16/7/25.
//  Copyright © 2016年 CCB. All rights reserved.
//

//#import "CCBBaseViewModel.h"

@interface CCB_O_VOAU05 : CCBBaseViewModel
/** 返回值 */
@property (nonatomic, strong) NSString *Ret_Trgt_Cd;

/** 返回信息 */
@property (nonatomic, strong) NSString *Rslt_Ret_Inf;

/** 有效时长 */
@property (nonatomic, strong) NSString *Rmrk_4_Rcrd_Cntnt;

/** 身份验证ID */
@property (nonatomic, strong) NSString *Tokn_Ctfn_ID;

/** 身份验证文本 */
@property (nonatomic, strong) NSString *Rmrk_2_Rcrd_Cntnt;

/** 得分 */
@property (nonatomic, strong) NSString *Rmrk_3_Rcrd_Cntnt;

/** 密文信息 */
@property (nonatomic, strong) NSString *Rmrk_1_Rcrd_Cntnt;

@end
