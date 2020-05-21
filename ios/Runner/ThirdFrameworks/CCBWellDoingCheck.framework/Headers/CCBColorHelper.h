//
//  CCBColorHelper.h
//  CCBMobileBankFoundation
//
//  Created by jinhong on 16/7/4.
//  Copyright © 2016年 CCB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface CCBColorHelper : NSObject


//当前颜色按照CCB的规则转换为深色, 因子0.611073
+ (UIColor *)changeColorToDark:(UIColor *)color;
//当前颜色按照CCB的规则转换为深色, 参数因子可以配置
+ (UIColor *)changeColorToDark:(UIColor *)color factor:(float)factor;


//当前颜色按照CCB的规则转换为浅色，因子0.372328
+ (UIColor *)changeColorToLight:(UIColor *)color;
//当前颜色按照CCB的规则转换为浅色, 参数因子可以配置
+ (UIColor *)changeColorToLight:(UIColor *)color factor:(CGFloat)factor;

@end

