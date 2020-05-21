//
//  CCB_ZXQYFaceModelVerify.h
//  CCBMobileBank
//
//  Created by zhuqimin on 17/8/24.
//  Copyright © 2017年 ccbdeveloper. All rights reserved.
//

#import <UIKit/UIKit.h>
//

@interface CCB_I_ZXQYFaceModelVerify : CCBBaseRequestModel

/** 客户端当前时间 */
@property (nonatomic, strong) NSString *SYSTEM_TIME;

/** 客户端唯一标识 */
@property (nonatomic, strong) NSString *HARDWARESN;

/** P6客户号 */
@property (nonatomic, strong) NSString *Cst_ID;

/** 客户名称 */
@property (nonatomic, strong) NSString *Cst_Nm;

/** 证件类型 */
@property (nonatomic, strong) NSString *Crdt_TpCd;

/** 证件号码 */
@property (nonatomic, strong) NSString *Crdt_No;

/** 渠道客户号 */
@property (nonatomic, strong) NSString *CHNL_CUST_NO;

/** 相片 */
@property (nonatomic, strong) NSString *base64_Ecrp_Txn_Inf;

/** 电子渠道平台流水号 */
@property (nonatomic, strong) NSString *PLAT_FLOW_NO;

/** 启用标志2：业务类型*/
@property (nonatomic, strong) NSString *StrUsInd_2;
@end
