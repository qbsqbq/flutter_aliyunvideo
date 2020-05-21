//
//  CCB_FaceModelVerify_Result.h
//  CCBMobileBankFoundation
//
//  Created by zhuqimin on 17/3/20.
//  Copyright © 2017年 CCB. All rights reserved.
//

//#import "CCBBaseModel.h"
#import <UIKit/UIKit.h>

@interface CCB_FaceModelVerify_Result : CCBBaseModel

/** 验证结果 */
@property (nonatomic, strong) NSString *Rslt_Ret_Inf;

/** P6客户号 */
@property (nonatomic, strong) NSString *Cst_ID;

/** 客户名称 */
@property (nonatomic, strong) NSString *Cst_Nm;

/** 证件类型 */
@property (nonatomic, strong) NSString *CrdTp_Cd;

/** 证件号码 */
@property (nonatomic, strong) NSString *Crdt_No;

/** 手机号码 */
@property (nonatomic, strong) NSString *Rmrk_1_Rcrd_Cntnt;

/** 相片特征值 */
@property (nonatomic, strong) NSString *base64_ECD_Txn_Inf;

/** 相片相似度 */
@property (nonatomic, strong) NSString *Rslt_Ret_Inf1;

/** 密文信息 */
@property (nonatomic, strong) NSString *Enc_Rslt_Info;

@property (nonatomic, strong) UIImage *img;

@end
