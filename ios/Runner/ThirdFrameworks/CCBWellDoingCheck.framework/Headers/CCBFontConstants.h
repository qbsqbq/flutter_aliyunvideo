//
//  CCBFontConstants.h
//  CCBMobileBank
//
//  字体相关的宏
//
//  Created by jinhong on 16/4/11.
//  Copyright © 2016年 CCB. All rights reserved.
//
#import "M.h"

#ifndef CCBFontConstants_h
#define CCBFontConstants_h

#define CCBImage(string) [M C:(string)]
// 获取当前屏幕的scale值，或许有想法的人需要。
//#define WScale ([UIScreen mainScreen].bounds.size.width >= 375.0 ? 1 : [UIScreen mainScreen].bounds.size.width/375.0)
//#define WScale ([UIScreen mainScreen].bounds.size.width/375.0)
#define WScale M.A
//#define WScale 1

//  计算在当前屏幕实际的宽度，用于‘屏幕适配’
#define WS(v) ((v)*WScale)

//字体大小调节
//#define kLabelFontRate ([[[NSUserDefaults standardUserDefaults] objectForKey:@"KEY_fontsize"] doubleValue])
#define kLabelFontRate M.B

// 方便字体统一管理
#define kLabelSquareFont [M F:13]
#define kLabelFontSize18_5 [M F:18.5]
#define kLabelFontSize17_5 [M F:17.5]
#define kLabelFontSize16_5 [M F:16.5]
#define kLabelFontSize15_5 [M F:15.5]
#define kLabelFontSize14_5 [M F:14.5]
#define kLabelFontSize13_5 [M F:13.5]
#define kLabelFontSize12_5 [M F:12.5]
#define kLabelFontSize45 [M F:45]
#define kLabelFontSize30 [M F:30]
#define kLabelFontSize24 [M F:24]
#define kLabelFontSize21 [M F:21]
#define kLabelFontSize20 [M F:20]
#define kLabelFontSize19 [M F:19]
#define kLabelFontSize18 [M F:18]
#define kLabelFontSize17 [M F:17]
#define kLabelFontSize16 [M F:16]
#define kLabelFontSize15 [M F:15]
#define kLabelFontSize14 [M F:14]
#define kLabelFontSize13 [M F:13]
#define kLabelFontSize12 [M F:12]
#define kLabelFontSize11 [M F:11]
#define kLabelFontSize10 [M F:10]
#define kLabelFontSize9 [M F:9]
#define kLabelFontSize8 [M F:8]

// 自定义字体大小
#define kLabelFontSize(size) [M F:(size)]

// 创建缩放好的点
CG_INLINE CGPoint CCBPointMake(CGFloat x, CGFloat y)
{
    CGPoint p; p.x = x; p.y = y; return p;
}

// 创建缩放好的size
CG_INLINE CGSize CCBSizeMake(CGFloat width, CGFloat height)
{
    CGSize size; size.width = WS(width); size.height = WS(height); return size;
}

// 创建缩放好的frame
CG_INLINE CGRect CCBRectMake(CGFloat x, CGFloat y, CGFloat width, CGFloat height)
{
    CGRect rect;
    rect.origin.x = WS(x); rect.origin.y = WS(y);
    rect.size.width = WS(width); rect.size.height = WS(height);
    return rect;
}

#endif /* CCBFontConstants_h */
