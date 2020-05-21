//
//  CCBOnlineVerifyInterface.h
//  CloudAuthentication
//
//  Created by zhuqimin on 2018/5/31.
//  Copyright © 2018年 ccbMobileBank. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "CCBBaseError.h"

@interface CCBOnlineVerifyInterface : NSObject

+ (void)callOnlineVerifyWithIDNo:(nonnull NSString*)idNo custName:(NSString*)name appKey:(NSString*)appKey subKey:(NSString*)subKey navigation:(UINavigationController*)navi callBack:(void (^)(BOOL isSuccess, CCBBaseError*error))callback;

@end
