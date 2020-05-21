//
//  CCB_1_VM_OnlineSign_FileUploader.h
//  CCBMobileBank
//
//  Created by zhuqimin on 17/8/15.
//  Copyright © 2017年 ccbdeveloper. All rights reserved.
//

//#import <CCBViewModel/CCBViewModel.h>
#import "CCB_OnlineSign_Model.h"

#import "CCB_UpModel0001.h"

@interface CCBOnlineSignFileUploader : CCBBaseViewModel

@property (nonatomic, strong) CCBBaseError *errorObj;

@property (nonatomic, assign) BOOL uploadSuccessed;

@property (nonatomic, strong) NSString *mbsAddr;
@property (nonatomic, strong) NSString *safeConsoleAddr;
@property (nonatomic, strong) NSString *enterpriceAuthAddr;

//- (void)uploadFile:(NSString*)name withCardID:(NSString*)cardID dateStr:(NSString*)dateStr;
- (void)uploadFile:(NSString*)name withCardID:(NSString*)cardID url:(NSString*)url params:(NSDictionary*)paramsDic;

//- (BOOL)uploadFile:(NSString*)name withDate:(NSString*)dateStr;
- (BOOL)uploadFile:(NSString*)name withUrl:(NSString*)url params:(NSDictionary*)paramsDic;

//-(void)sendCICS00001withModel:(CCB_OnlineSign_Model*)model withFile:(NSDictionary*)fielNameDic;
-(void)sendCICS00001withModel:(CCB_OnlineSign_Model*)model withComm_Auth_Fields:(NSString*)Comm_Auth_Fields;
-(void)sendCICS00001withVerify:(CCB_UpModel0001*)model;
-(void)sendCICS00001withEBSFaceModelVerify:(CCB_UpModel0001*)model;

@property (nonatomic, copy) void(^callback)(BOOL isSuccess, CCBBaseError *error);

@end
