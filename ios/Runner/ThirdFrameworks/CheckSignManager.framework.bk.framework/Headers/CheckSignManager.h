//
//  CheckSignManager.h
//  CheckSignManager
//
//  Created by ccb on 16/7/2.
//  Copyright © 2016年 ccb. All rights reserved.
//

//#import <Foundation/Foundation.h>
//

#import <CoreLocation/CoreLocation.h>

#define DATE "20170307"
#define APPLYVERSION "1.0.1"
#define TYPEE  "online"
#define BUNDLEID "com.ccb.szfh"
#define BUNDLENAME "B+银行"
#define CERTACC "N/A"

#define AES_DBNAMIC_E_TYPE              @"DYNAMIC"
#define AES_NETCRYPTO_E_TYPE            @"NETCRYPTO"
#define AES_DYNAMIC_TIME_E_TYPE         @"DYNAMIC_TIME"

#import <Foundation/Foundation.h>

@interface CheckSignManager : NSObject<CLLocationManagerDelegate>
{
    int  check_flag;//检查标志开关 :0－不执行检查  1－执行检查
    bool verify_result;//检查结果标志:false－检查失败    true－检查成功
}

+ (CheckSignManager*) shared;

- (int) checkSign:(NSString*) uniqueid appSecretS:(NSString*)SeS;

- (int) check;
- (void) makeParas:(NSString*) cipherS;

@property(atomic,assign)int check_flag;
@property(atomic,assign)bool verify_result;

+ (NSString*) tranEncrypt:(NSString*)plainText;
+ (NSString*) tranDecrypt:(NSString*)cipherText;
+ (NSString*) localEncrypt:(NSString*) plainText;
+ (NSString*) localDecrypt:(NSString*) plainText;
+ (NSString*) jumpEncrypt:(NSString*) plainText;
+ (NSString*) jumpDecrypt:(NSString*) plainText;
+ (NSString*) calc_HMAC:(NSString*) plain;
+ (NSString*) getVersion;
+ (NSString*) getSysCode;
+ (NSString*) getMpCode;
+ (NSString*) getAppName;
+ (NSString*) getDevicdId;
+ (NSString*) getAppUUID;
+ (NSString*) getGPSInfo;

@end
