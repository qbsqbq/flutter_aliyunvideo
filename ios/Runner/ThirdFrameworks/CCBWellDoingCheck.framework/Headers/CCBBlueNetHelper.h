//
//  CCBBlueNetHelper.h
//  CCBMobileBank
//
//  Created by LATTICE on 2018/5/14.
//  Copyright © 2018年 ccbdeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CCBBlueNetHelper : NSObject

+ (instancetype)shareInstance;

// 显示logo 1s后自动关闭 自动关闭时dismissBlock才有效
- (void)showLogoAnimation:(BOOL)animation autoDismiss:(BOOL)isAuto withVc:(UIViewController*)vc dismissBlock:(void(^)(void))block;

// 手动调用关闭 上面方法自动设置YES的话不需要调用该方法
- (void)dismissLogoAnimation:(BOOL)animation completion:(void(^)(void))completion;

@end
