//
//  CCB_I_SJPX03.h
//  CCBMobileBank
//
//  Created by zhuqimin on 17/8/17.
//  Copyright © 2017年 ccbdeveloper. All rights reserved.
//

//#import <CCBModel/CCBModel.h>
//
//#import "CCBBaseModel.h"

@interface ACCT_GROUP_ELEMENT : CCBBaseModel

@property (nonatomic, strong) NSString *EBNK_SIGN_ACCNO;

@end

@interface CCB_I_SJPX03 : CCBBaseRequestModel

/** 0:新签约 */
@property (nonatomic, strong) NSString *Rsrv_TpCd;

/** 客户编号
 */
@property (nonatomic, strong) NSString *Cst_ID;

/** 渠道客户号
 */
@property (nonatomic, strong) NSString *CHNL_CUST_NO;

/** 渠道类型代码
 */
@property (nonatomic, strong) NSString *Chnl_TpCd;

/**
 */
@property (nonatomic, strong) NSArray<ACCT_GROUP_ELEMENT*> *ACCT_GROUP;

/** 电子银行签约账号
 */
@property (nonatomic, strong) NSString *EBNK_SIGN_ACCNO;

/** 电子渠道平台流水号 */
@property (nonatomic, strong) NSString *PLAT_FLOW_NO;

@end
