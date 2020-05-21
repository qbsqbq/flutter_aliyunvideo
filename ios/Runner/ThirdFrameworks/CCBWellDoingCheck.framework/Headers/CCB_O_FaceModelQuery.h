//
//  CCB_O_LIV01.h
//  CCBMobileBank
//
//  Created by zhuqimin on 17/3/1.
//  Copyright © 2017年 ccbdeveloper. All rights reserved.
//
//#import "CCBBaseModel.h"


@interface CCB_O_FaceModelQuery : CCBBaseModel

@property (nonatomic, strong) NSString *Res_Rtn_Code;

@property (nonatomic, strong) NSString *Res_Rtn_Msg;

@property (nonatomic, strong) NSString *Ret_Enc_Inf;
/** 返回码 */
@property (nonatomic, strong) NSString *Return_code;

/** 提示信息 */
@property (nonatomic, strong) NSString *Return_msg;

/** 验证结果 */
@property (nonatomic, strong) NSString *Rslt_Ret_Inf;

@end
