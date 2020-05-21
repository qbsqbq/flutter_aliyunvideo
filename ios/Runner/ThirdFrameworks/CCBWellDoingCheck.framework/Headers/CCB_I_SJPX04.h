//
//  CCB_I_SJPX04.h
//  CCBMobileBank
//
//  Created by zhuqimin on 2017/10/24.
//  Copyright © 2017年 ccbdeveloper. All rights reserved.
//

//#import <CCBModel/CCBModel.h>


@interface CCB_I_SJPX04 : CCBBaseRequestModel

/** 客户编号
 */
@property (nonatomic, strong) NSString *Cst_ID;

/** 渠道客户号
 */
@property (nonatomic, strong) NSString *CHNL_CUST_NO;

/** 渠道类型代码
 */
@property (nonatomic, strong) NSString *Chnl_TpCd;

/**旧签约手机号
 */
@property (nonatomic, strong) NSString *EBnkModBfrRsv1MblPhNo;

/**新签约手机号
 */
@property (nonatomic, strong) NSString *EBnkModAfRsrv1MblPhNo;

/** 电子渠道平台流水号 */
@property (nonatomic, strong) NSString *PLAT_FLOW_NO;

@end
