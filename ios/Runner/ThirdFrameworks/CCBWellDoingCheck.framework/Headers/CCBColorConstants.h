//
//  CCBColorConstants.h
//  CCBMobileBank
//
//  Created by Ansonyc on 16/4/13.
//  Copyright © 2016年 CCB. All rights reserved.
//

#ifndef CCBColorConstants_h
#define CCBColorConstants_h


#pragma - mark

#define kColorSquareLabel               RGBCOLOR(102, 102, 102)

#define kColorMajorGray                  RGBCOLOR(155,158,171)// 主，灰色
#define kColorMajorBlack                 RGBCOLOR(25,25,25)// 主，黑色

#define kColorDecorateLightGray          RGBCOLOR(231, 233, 235)// 衬托背景的浅灰
#define kColorDecorateGray               RGBCOLOR(211, 213, 214)// 衬托背景的灰
#define kColorDecorateLightWhite         RGBCOLOR(244, 248, 251)// 衬托背景的浅白
#define kColorDecorateGrayWhite          RGBCOLOR(235, 241, 245)// 衬托背景的灰白

#pragma - mark 控件颜色
// 标题导航栏
#define kColorNavigationBackground      RGBCOLOR(9,182,242)
// 按钮颜色
#define kColorButtonTitleNormal         RGBCOLOR(9,182,242)
#define kColorButtonTitleHilighted      RGBCOLOR(22,74,153)
#define kColorButtonTitleDisabled       RGBCOLOR(200,238,255)
// 区块内容标题栏
#define kColorSectionHeaderTitle        RGBCOLOR(9,182,242)
// 内容金额
#define kColorAmountText                RGBCOLOR(9,182,242)
// Tab栏选择状态
#define kColorSegmentSelected           RGBCOLOR(9,182,242)
// 主题文字颜色
#define kColorLabelText                 RGBCOLOR(9,182,242)
// 灰黑色文字颜色 多彩版：#666666 RBG:102,102,102 素色版相同
#define kColorLabelTextBlack            RGBCOLOR(102, 102, 102)
// 近似黑色文字颜色 多彩版：#333333 RBG:51,51,51 素色版相同
#define kColorLabelTextDefaultBlack     RGBCOLOR(51, 51, 51)
// 浅蓝背景色 多彩版：#f1f6fa RBG:241,246,250 素色版相同
#define kColorBackgroundLight           RGBCOLOR(241, 246, 250)
// 浅灰色文字颜色 多彩版：#999999 RBG:153，153，153 素色版相同
#define kColorLabelTextGray             RGBCOLOR(153,153,153)


#pragma - mark 系统颜色
#define kColorBlackColor                [UIColor blackColor]
#define kColorDarkGrayColor             [UIColor darkGrayColor]
#define kColorLightGrayColor            [UIColor lightGrayColor]
#define kColorWhiteColor                [UIColor whiteColor]
#define kColorGrayColor                 [UIColor grayColor]
#define kColorRedColor                  [UIColor redColor]
#define kColorGreenColor                [UIColor greenColor]
#define kColorBlueColor                 [UIColor blueColor]
#define kColorCyanColor                 [UIColor cyanColor]
#define kColorYellowColor               [UIColor yellowColor]
#define kColorMagentaColor              [UIColor magentaColor]
#define kColorOrangeColor               [UIColor orangeColor]
#define kColorPurpleColor               [UIColor purpleColor]
#define kColorBrownColor                [UIColor brownColor]
#define kColorClearColor                [UIColor clearColor]

#pragma - mark 换肤色块颜色
#define kColorBlock01Color [UIColor colorWithRed:253/255.0f green:95/255.0f blue:139/255.0f alpha:1]
#define kColorBlock02Color [UIColor colorWithRed:255/255.0f green:125/255.0f blue:158/255.0f alpha:1]
#define kColorBlock03Color [UIColor colorWithRed:255/255.0f green:118/255.0f blue:200/255.0f alpha:1]
#define kColorBlock04Color [UIColor colorWithRed:145/255.0f green:113/255.0f blue:238/255.0f alpha:1]
#define kColorBlock05Color [UIColor colorWithRed:115/255.0f green:128/255.0f blue:250/255.0f alpha:1]
#define kColorBlock06Color [UIColor colorWithRed:70/255.0f green:144/255.0f blue:234/255.0f alpha:1]
#define kColorBlock07Color [UIColor colorWithRed:57/255.0f green:175/255.0f blue:234/255.0f alpha:1]
#define kColorBlock08Color [UIColor colorWithRed:30/255.0f green:195/255.0f blue:145/255.0f alpha:1]
#define kColorBlock09Color [UIColor colorWithRed:43/255.0f green:180/255.0f blue:104/255.0f alpha:1]
#define kColorBlock10Color [UIColor colorWithRed:67/255.0f green:190/255.0f blue:54/255.0f alpha:1]
#define kColorBlock11Color [UIColor colorWithRed:105/255.0f green:200/255.0f blue:25/255.0f alpha:1]
#define kColorBlock12Color [UIColor colorWithRed:227/255.0f green:170/255.0f blue:20/255.0f alpha:1]
#define kColorBlock13Color [UIColor colorWithRed:255/255.0f green:145/255.0f blue:90/255.0f alpha:1]
#define kColorBlock14Color [UIColor colorWithRed:253/255.0f green:113/255.0f blue:110/255.0f alpha:1]
#define kColorBlock15Color [UIColor colorWithRed:253/255.0f green:85/255.0f blue:80/255.0f alpha:1]
#define kColorBlock16Color [UIColor colorWithRed:50/255.0f green:54/255.0f blue:56/255.0f alpha:1]



//颜色

#define RGBCOLOR(r,g,b)             [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define RGBACOLOR(r,g,b,a)          [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]
#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
#endif /* CCBColorConstants_h */
