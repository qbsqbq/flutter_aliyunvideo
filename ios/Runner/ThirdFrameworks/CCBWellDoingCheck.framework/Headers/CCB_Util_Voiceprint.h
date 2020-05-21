//
//  CCB_13_VoiceUtil.h
//  CCBMobileBank
//
//  Created by pengchenyi on 16/7/6.
//  Copyright © 2016年 CCB. All rights reserved.
//

#import <Foundation/Foundation.h>

#define K_MBS_voiceprint_server_switch @"MobileVoiceprintServerSwitch"
#define K_MBS_voiceprint_team_threshold @"MobileVoiceprintTeamThreshold"
#define K_MBS_voiceprint_server_address @"MBSVoiceprintServiceAddress"
#define K_MBS_voiceprint_verify_maxTime @"MobileVoiceprintVerifyMaxTime"
#define K_MBS_voiceprint_verify_passScore @"MobileVoiceprintVerifyPassScore"
#define K_MBS_voiceprint_packge_maxLength @"MobilePackgeMaxLength"
#define K_MBS_voiceprint_maxRecordTime @"MobileVoiceprintMaxRecordTime"
#define K_MBS_voiceprint_verify_special_passScore @"MobileSpecialVoiceprintVerifyPassScore"
#define K_MBS_voiceprint_verify_special_list @"MobileSpecialVoiceprintList"
#define K_MBS_voiceprint_verify_special_endDate @"MobileSpecialVoiceprintEndDate"
#define K_MBS_voiceprint_train_shutdown @"VoiceServerTrainShutDown"
#define K_MBS_voiceprint_verify_shutdown @"VoiceServerVerifyShutDown"

#define K_MBS_voiceprint_support_device @"MobileVoiceprintSupportedDevice"
#define K_ECUAC_voiceprint_group_threshold @"MobileECUACVoiceprintGroupThreshold"
#define K_MBS_fingerprint_group_threshold @"MobileFingerprintGroupThreshold"
#define K_MBS_ECUAC_MODEL_IS_EFFECT_KEY @"MobileECUACVoiceprintModelISEffect"

#define K_Voiceprint_Default_MaxVerifyTimes 4
#define K_Voiceprint_Default_PassScore 60
#define K_Voiceprint_Default_ServerSwitch 0
#define K_Voiceprint_Default_TeamThreshold -1
#define K_Fingerprint_Default_Group_Threshold -1

@interface CCB_Util_Voiceprint : NSObject
//+ (id)shareInstance;
+ (BOOL)shouldVerifyVoiceprint;

+ (BOOL)willVerifyVoiceprintWithBindFlag:(NSString*)bindFlag switchFlag:(NSString*)switchFlag effectFlag:(NSString*)effectFlag;

+ (BOOL)shouldResetVoiceprint;

+ (NSString*)getVoiceprintSwitchWithDic:(NSDictionary*)dict;
@end
