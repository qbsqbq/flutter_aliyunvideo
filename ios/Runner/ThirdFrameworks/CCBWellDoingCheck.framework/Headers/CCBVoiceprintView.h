//
//  CCBVoiceprintView.h
//  CCBMobileBank
//
//  Created by zhuqimin on 16/12/20.
//  Copyright © 2016年 ccbdeveloper. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface CCBVoiceprintView : UIView

- (instancetype)initWithFrame:(CGRect)frame;

- (void)updateWithMeter:(CGFloat)meter;

//设置线条颜色，默认为kColorSectionHeaderTitle
- (void)setThreadColor:(UIColor*)color;

//设置振幅，默认为0.5
- (void)setThreadAmplitude:(CGFloat)amplitude;

@end
