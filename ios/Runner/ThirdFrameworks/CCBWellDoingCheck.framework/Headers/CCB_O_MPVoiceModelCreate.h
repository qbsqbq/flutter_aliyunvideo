//
//  CCB_O_MPVoiceModelCreate.h
//  CCBUIKit
//
//  Created by zhuqimin on 2018/1/9.
//  Copyright © 2018年 CCB. All rights reserved.
//

//#import "CCBBaseModel.h"

@interface CCB_O_MPVoiceModelCreate : CCBBaseModel

/** 返回码*/
@property (nonatomic, strong) NSString *Res_Rtn_Code;

/** 提示信息*/
@property (nonatomic, strong) NSString *Res_Rtn_Msg;

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
