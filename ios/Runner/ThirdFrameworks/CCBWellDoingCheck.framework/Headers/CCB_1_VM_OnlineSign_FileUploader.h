//
//  CCB_1_VM_OnlineSign_FileUploader.h
//  CCBMobileBank
//
//  Created by zhuqimin on 17/8/15.
//  Copyright © 2017年 ccbdeveloper. All rights reserved.
//

//#import <CCBViewModel/CCBViewModel.h>
//#import "CCBBaseViewModel.h"

@interface CCB_1_VM_OnlineSign_FileUploader : CCBBaseViewModel

@property (nonatomic, strong) CCBBaseError *errorObj;

@property (nonatomic, assign) BOOL uploadSuccessed;

//- (void)uploadFile:(NSString*)name withCardID:(NSString*)cardID dateStr:(NSString*)dateStr;
- (void)uploadFile:(NSString*)name withCardID:(NSString*)cardID url:(NSString*)url params:(NSDictionary*)paramsDic;

//- (BOOL)uploadFile:(NSString*)name withDate:(NSString*)dateStr;
- (BOOL)uploadFile:(NSString*)name withUrl:(NSString*)url params:(NSDictionary*)paramsDic;

@end
