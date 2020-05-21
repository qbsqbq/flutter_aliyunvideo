//
//  CCBRoundButton.h
//  CCBMobileBank
//
//  Created by Ansonyc on 16/4/19.
//  Copyright © 2016年 CCB. All rights reserved.
//

#import "CCBButton.h"

//@protocol CCBThemeProtocol;

@interface CCBRoundButton : CCBButton
/**
 *  @return 大字体版蓝色圆角边框按钮
 */
+ (CCBRoundButton *)bigBlueButton;
/**
 *  蓝色圆角边框按钮(对应"CCB-Mobile-Guidelines-2016-411.pdf"里的线体主要按钮)
 *
 *  @return 蓝色圆角边框按钮
 */
+ (CCBRoundButton *)blueButton;

/**
 *  灰色圆角边框按钮(对应"CCB-Mobile-Guidelines-2016-411.pdf"里的线体次要按钮)
 *
 *  @return 灰色圆角边框按钮
 */
+ (CCBRoundButton *)grayButton;

/**
 *  白色背景灰色标题无边框圆角按钮(对应"CCB-Mobile-Guidelines-2016-411.pdf"里的实体主要按钮)
 *
 *  @return 实体主要按钮
 */
+ (CCBRoundButton *)solidMajorButton;

/**
 *  灰色背景白色标题无边框圆角按钮(对应"CCB-Mobile-Guidelines-2016-411.pdf"里的实体次要按钮)
 *
 *  @return 实体次要按钮
 */
+ (CCBRoundButton *)solidMinorButton;

/**
 *  灰色略圆角边框按钮(对应"CCB-Mobile-Guidelines-2016-411.pdf"里的辅助按钮)
 *
 *  @return 辅助按钮
 */
+ (CCBRoundButton *)assistingButton;

/**
 *  绘制边框的圆角按钮
 *
 *  @param color            边框颜色
 *  @param highlightedColor 高亮时的边框颜色
 *
 *  @return 使用指定颜色绘制边框的按钮
 */
+ (CCBRoundButton *)strokedColorButtonWithColor:(UIColor *)color
                               highlightedColor:(UIColor *)highlightedColor;

/**
 *  自定义绘制按钮
 *
 *  @param strokeColor            秒变颜色
 *  @param highlightedStrokeColor 高亮的描边颜色
 *  @param fillColor              填充颜色
 *  @param highlightedFillColor   高亮的填充颜色
 *  @param cornerRadius           圆角大小
 *
 *  @return 根据参数自定义的绘制按钮
 */
+ (CCBRoundButton *)roundButtonWithStrokeColor:(UIColor *)strokeColor
                        highlightedStrokeColor:(UIColor *)highlightedStrokeColor
                                     fillColor:(UIColor *)fillColor
                          highlightedFillColor:(UIColor *)highlightedFillColor
                                  cornerRadius:(CGFloat)cornerRadius;

/**
 *  设置按钮的各种颜色
 *
 *  @param strokeColor     描边颜色
 *  @param fillColor       填充颜色
 *  @param textColor       文字颜色
 *  @param state           设置颜色的状态
 *  @param cornerRadius    圆角大小
 */
- (void)setStrokeColor:(UIColor *)strokeColor
             fillColor:(UIColor *)fillColor
             textColor:(UIColor *)textColor
              forState:(UIControlState)state
          cornerRadius:(CGFloat)cornerRadius;

@end
