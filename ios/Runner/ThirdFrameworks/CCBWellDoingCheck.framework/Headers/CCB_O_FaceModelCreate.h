//
//  CCB_O_LIV02.h
//  CCBMobileBank
//
//  Created by zhuqimin on 17/3/1.
//  Copyright © 2017年 ccbdeveloper. All rights reserved.
//

//#import "CCBBaseModel.h"

@interface CCB_O_FaceModelCreate : CCBBaseModel

@property (nonatomic, strong) NSString *Res_Rtn_Code;

@property (nonatomic, strong) NSString *Res_Rtn_Msg;

@property (nonatomic, strong) NSString *Ret_Enc_Inf;
/** 验证结果 */
@property (nonatomic, strong) NSString *Rslt_Ret_Inf;

/** 客户姓名 */
@property (nonatomic, strong) NSString *Idv_Lql_Nm;

/** 证件类型 */
@property (nonatomic, strong) NSString *Crdt_TpCd;

/** 证件号码 */
@property (nonatomic, strong) NSString *Crdt_No;

/** P6客户号 */
@property (nonatomic, strong) NSString *Cst_ID;


@end
