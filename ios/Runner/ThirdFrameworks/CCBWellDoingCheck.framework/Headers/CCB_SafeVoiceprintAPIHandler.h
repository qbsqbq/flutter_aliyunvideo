//
//  CCB_13_SafeVoiceprintAPIHandler.h
//  CCBMobileBank
//
//  Created by zhuqimin on 16/7/25.
//  Copyright © 2016年 CCB. All rights reserved.
//
//#import "CCBBaseViewModel.h"


#define K_13_OperationResult @"result"
#define K_13_VoiceprintID @"voiceprintID"
#define K_13_isVoiceprintIDExisted @"isVoiceprintIDExisted"
#define K_13_TrainText @"trainText"
#define K_13_TrainIndex @"index"
#define K_13_VerificationID @"verificationID"
#define K_13_VerifyText @"verifyText"
#define K_13_VerifyScore @"score"
#define K_13_ErrorCode @"errorcode"
#define K_13_ErrorDescription @"errormsg"
#define K_13_EncryedString @"encryedString"
#define K_13_Voiceprint_Default_PackageMaxLength 160

@interface CCB_SafeVoiceprintAPIHandler : CCBBaseViewModel

@property (nonatomic, copy) void(^callback)(NSDictionary*);

@property (nonatomic, strong) NSString *platFormCustNO;

@property (nonatomic, strong) NSString *encryptedStr;

+ (instancetype) getInstance;

- (void)getTrainTextFromSafe;

- (void)uploadTrainVoiceToSafeWithTrainCount:(NSInteger)trainCount TrainText:(NSString*)trainText TrainIndex:(NSInteger)index recordFilePath:(NSString*)filePath;

- (void)getVerificationTextFromSafe;

- (void)uploadVerifyVoiceToSafeWithFilePath:(NSString*)filePath;

- (void)isVoiceprintExistedInSafe;

- (NSString*)getEncryptedString;
@end
