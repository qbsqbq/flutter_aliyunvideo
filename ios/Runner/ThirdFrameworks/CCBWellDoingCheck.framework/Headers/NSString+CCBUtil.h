//
//  NSString+CCBUtil.h
//  CloudAuthentication
//
//  Created by Guy on 2018/3/23.
//  Copyright © 2018年 ccbMobileBank. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (CCBUtil)
//判断字符串是否为空
- (BOOL)ccb_isEmpty;

//判断输入string是否不合法
+ (BOOL)ccb_isEmptyString:(NSString *)string;
@end
