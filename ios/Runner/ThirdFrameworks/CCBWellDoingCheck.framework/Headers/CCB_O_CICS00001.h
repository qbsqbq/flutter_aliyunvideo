//
//  CCB_O_CICS00001.h
//  testIdCheck
//
//  Created by 李朝军 on 2018/7/11.
//  Copyright © 2018年 李朝军. All rights reserved.
//

//#import "CCBBaseModel.h"

@interface CCB_O_CICS00001_Param:NSObject
//@property (nonatomic,strong) NSString *Trans_Flow_ID;
//@property (nonatomic,strong) NSString *MERCHANTNO;
//@property (nonatomic,strong) NSString *MERCHANTNAME;
//@property (nonatomic,strong) NSString *Rslt_Ret_Inf;
@property (nonatomic,strong) NSString *Cmp_Rslt_Ind;
@property (nonatomic,strong) NSString *Smlr_Dgr_Cmnt;
@property (nonatomic,strong) NSString *Enc_Rslt_Info;
@end

@interface CCB_O_CICS00001 : CCBBaseModel
@property (nonatomic,strong) NSString *Res_Rtn_Code;
@property (nonatomic,strong) NSString *Res_Rtn_Msg;
@property (nonatomic,strong) NSString *Ret_Enc_Inf;
@end
