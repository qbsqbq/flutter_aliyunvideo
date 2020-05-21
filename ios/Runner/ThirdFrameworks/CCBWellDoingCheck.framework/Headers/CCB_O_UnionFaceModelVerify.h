//
//  CCB_O_UnionFaceModelVerify.h
//  CCBUIKit
//
//  Created by zhuqimin on 2018/1/9.
//  Copyright © 2018年 CCB. All rights reserved.
//

//#import "CCBBaseModel.h"

@interface CCB_O_UnionFaceModelVerify : CCBBaseModel

@property (nonatomic, strong) NSString *Res_Rtn_Code;

@property (nonatomic, strong) NSString *Res_Rtn_Msg;

@property (nonatomic, strong) NSString *Ret_Enc_Inf;

/** 比对结果标志 */
@property (nonatomic, strong) NSString *Cmp_Rslt_Ind;

/** 返回信息 */
@property (nonatomic, strong) NSString *Rslt_Ret_Inf;

/** 相似程度说明 */
@property (nonatomic, strong) NSString *Smlr_Dgr_Cmnt;

@property (nonatomic, strong) NSString *Enc_Rslt_Info;

@end
