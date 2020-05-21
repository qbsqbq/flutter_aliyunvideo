//
//  CCB_UpModel0001.h
//  CCBeCloudIDCheck
//
//  Created by 李朝军 on 2018/10/15.
//  Copyright © 2018年 李朝军. All rights reserved.
//

#import <CCBCommunication/CCBCommunication.h>

@interface CCB_UpModel0001 : CCBBaseModel
/** 客户名称
 */
@property (nonatomic, strong) NSString *Cst_Nm;

/** 证件类型代码
 */
@property (nonatomic, strong) NSString *Crdt_TpCd;

/** 证件号码
 */
@property (nonatomic, strong) NSString *Crdt_No;

/** 性别代码
 */
@property (nonatomic, strong) NSString *Gnd_Cd;

/** 民族代码
 */
@property (nonatomic, strong) NSString *Ethnct_Cd;

/** 出生日期
 */
@property (nonatomic, strong) NSString *Brth_Dt;

/** 有效期-起始
 */
@property (nonatomic, strong) NSString *AvlDt_Dt;

/** 有效期-结束
 */
@property (nonatomic, strong) NSString *AvlDt_EdDt;

/** 签发机关
 */
@property (nonatomic, strong) NSString *Inst_Chn_FullNm;

/** 详细地址
 */
@property (nonatomic, strong) NSString *Dtl_Adr;

/** 签约组织机构代码
 */
@property (nonatomic, strong) NSString *Sign_OrCd;



/** P6客户号
 */
@property (nonatomic, strong) NSString *Cst_ID;

@property (nonatomic, strong) NSString *Stm_Chnl_ID;
@property (nonatomic, strong) NSString *Stm_Chnl_Txn_CD;
@property (nonatomic, strong) NSString *Ftr_Col_TmnlInf;
@property (nonatomic, strong) NSString *Comm_Auth_Fields;
@property (nonatomic, strong) NSString *Br_ID_Inf;
@property (nonatomic, strong) NSString *LgnID;

/** 渠道客户号
 */
@property (nonatomic, strong) NSString *CHNL_CUST_NO;

/** 身份证正面图片名称
 */
@property (nonatomic, strong) NSString *File_Nm;

/** 身份证反面图片名称 */
@property (nonatomic, strong) NSString *Upload_FlNm;

@property (nonatomic, strong) NSData *faceData;

/** 电子渠道平台流水号*/
@property (nonatomic, strong) NSString *PLAT_FLOW_NO;

/** 手机号*/
@property (nonatomic, strong) NSString *mobileNo;

@property (nonatomic, strong) NSArray *signAccount;

/** 开户分行号*/
@property (nonatomic, strong) NSString *BranchID;
@end
