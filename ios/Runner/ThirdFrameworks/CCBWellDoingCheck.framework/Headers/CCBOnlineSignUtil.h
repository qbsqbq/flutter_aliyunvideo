//
//  CCBOnlineSignUtil.h
//  CCBMobileBank
//
//  Created by zhuqimin on 17/8/18.
//  Copyright © 2017年 ccbdeveloper. All rights reserved.
//

//#import <CCBModel/CCBModel.h>
//#import "CCBBaseModel.h"

#define kOnlineSignEBSChannel @"OnlineSignEBSChannel"

@interface CCBOnlineSignUtil : CCBBaseModel

+ (NSString*)getNationCodeWithDesc:(NSString*)nation;

//+ (NSString*)getUploadUrl;

+ (NSString *)transferBranchID:(NSString *)branchID;

#pragma mark - 保存图片至沙盒
+ (void) saveImage:(UIImage *)currentImage InJPEGWithName:(NSString*)imageName;

+ (void) saveImage:(UIImage *)currentImage withName:(NSString *)imageName;

+ (void)deleteFileWithName:(NSString*)name;

+ (UIImage*)imageWithFileName:(NSString*)name;
@end
