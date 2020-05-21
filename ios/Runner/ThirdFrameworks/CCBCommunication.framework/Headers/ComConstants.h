//
//  ComConstants.h
//  CCBMobileBank
//
//  Created by mac on 16/3/30.
//  Copyright © 2016年 CCB. All rights reserved.
//
#ifndef ComConstants_h
#define ComConstants_h

typedef enum {
    FinishTypeSuccess = 0,
    FinishTypeTimeOut,
    FinishTypeError,
    FinishTypeUnableAnalysis,
    FinishTypeNeedLogin,
    FinishTypeReLogin,
    FinishTypeNeedCookie
}FinishType;

typedef enum {
    PhoneCommType = 0,
    EBankCommType,
    WapCommType,
    ETradeCommType,
    OldCommType,
    WechatCommType,
    YinXinCommType,
    VoicePrintCommType,
    WapECommerceType,

}CommunicationType;

////////////--------------------------通讯封包关键字----------------///////////////////////
#define K_BASE_status @"status"
#define K_BASE_params @"params"
#define K_BASE_txCode @"txCode"
#define K_BASE_result @"result"
#define K_BASE_id @"id"
#define K_BASE_header @"header"
#define K_BASE_request @"request"
#define K_BASE_JSON @"JSON"
#define K_BASE_version @"version"
#define K_BASE_preassociated @"preassociated"
#define K_BASE_statusSucc @"01"
#define K_BASE_statusFail @"00"
#define K_BASE_errMessage @"errMessage"
#define K_BASE_errCode @"errCode"
#define K_BASE_response @"response"

#define K_BASE_Code_Prefix @"!![C#C%B*K�e£y¥B$o&a11r22d]!!::"

#define MBS_Comm_TimeOutInterval 30


#endif /* ComConstants_h */
