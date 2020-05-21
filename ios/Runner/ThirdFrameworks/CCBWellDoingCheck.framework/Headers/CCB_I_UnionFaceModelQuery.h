//
//  CCB_I_UnionFaceModelQuery.h
//  CCBUIKit
//
//  Created by zhuqimin on 2018/1/9.
//  Copyright © 2018年 CCB. All rights reserved.
//


@interface CCB_I_UnionFaceModelQuery : CCBBaseRequestModel

/** 客户端当前时间 */
@property (nonatomic, strong) NSString *SYSTEM_TIME;

/** 客户端唯一标识 */
@property (nonatomic, strong) NSString *HARDWARESN;

/** 业务查询类型 */
@property (nonatomic, strong) NSString *Biz_Type;

/** #系统渠道编号 */
@property (nonatomic, strong) NSString *Stm_Chnl_ID;

/** #系统渠道交易码 */
@property (nonatomic, strong) NSString *Stm_Chnl_Txn_CD;

/** 客户编号 */
@property (nonatomic, strong) NSString *Cst_ID;

/** 客户名称 */
@property (nonatomic, strong) NSString *Cst_Nm;

/** 卡种代码 */
@property (nonatomic, strong) NSString *CrdTp_Cd;

/** 证件号码 */
@property (nonatomic, strong) NSString *Crdt_No;

/** #备注1记录内容 */
@property (nonatomic, strong) NSString *Rmrk_1_Rcrd_Cntnt;

/** 网点编号信息 */
@property (nonatomic, strong) NSString *Br_ID_Inf;

/** #地理位置编号 */
@property (nonatomic, strong) NSString *Geo_Lo_ID;

/** #厂商标识码 */
@property (nonatomic, strong) NSString *Mftr_Idr_CD;

/** #厂商库版本号 */
@property (nonatomic, strong) NSString *Mftr_Str_VNo;

/** #特征采集终端信息 */
@property (nonatomic, strong) NSString *Ftr_Col_TmnlInf;

/** #终端设备号 */
@property (nonatomic, strong) NSString *Tmnl_Eqmt_No;

/** #终端设备版本号 */
@property (nonatomic, strong) NSString *Tmnl_Eqmt_VNo;

/** #设备型号版本号 */
@property (nonatomic, strong) NSString *Eqmt_Modl_VNo;

/** #设备认证码 */
@property (nonatomic, strong) NSString *Eqmt_Ctfn_CD;

/** #用户信息描述 */
@property (nonatomic, strong) NSString *Usr_Inf_Dsc;

/** #设备信息描述 */
@property (nonatomic, strong) NSString *Eqmt_Inf_Dsc;

/** #附属信息描述 */
@property (nonatomic, strong) NSString *Aflt_Inf_Dsc;

@end
