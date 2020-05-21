//
//  HttpRequestDelegate.h
//  CCBMobileBank
//
//  Created by mac on 16/3/30.
//  Copyright © 2016年 CCB. All rights reserved.
//

// HTTP请求类型
#ifndef HTTPREQUESTDELEGATE_H
#define HTTPREQUESTDELEGATE_H
#import "ComConstants.h"
@class CCBBaseModel;
@class CCBBaseError;

typedef enum {
    HttpRequestTypeNewClient = 0, //手机银行旧总控(path:/cmccb/servlet/ccbNewClient)
    HttpRequestTypeNewClientForOther, //手机银行其他(path:/cmccb/servlet/ccbNewClient)
    HttpRequestTypeNewUIClient, //手机银行(path:/cmccb/servlet/ccbNewUIClient)
    HttpRequestTypeEbankClient, //网银(path:/CCBIS/B2CMainPlat_00_OtherApps)
    HttpRequestTypeNewEbankClient, //新网银(path:/CCBIS/B2CMainPlat_13_MB)
    HttpRequestTypeVoicePrintConsole, //声纹管理(path:/NCCB/CCBCommonProxy)
    HttpRequestTypeSafeConsole, //安全网关(path:/NCCB/CCBCommonTXRoute)
    HttpRequestTypeSafeConsoleForOther, //(path:/NCCB/CCBSessionBSRoute)
    HttpRequestTypeWapEbankClient, //网银网站 动态(path:/tran/WCCMainPlatV5)
    HttpRequestTypeWapStaticEbankClient, //网银网站 静态
}HttpRequestType;

@protocol HttpRequestDelegate <NSObject>

- (void)communicationResponseDelegate:(FinishType)type commType:(CommunicationType)commType command:(id)cmd;

@end

@protocol CCBRequestResultDelegate <NSObject>

- (void)requestData:(id)requestModel responseResult:(id)resultModel error:(CCBBaseError *)error;

@end

#endif
