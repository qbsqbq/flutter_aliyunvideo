//
//  CCBButton.h
//  CCBMobileBank
//
//  Created by jinhong on 16/3/30.
//  Copyright © 2016年 CCB. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CCBViewController.h"

typedef enum {
    CCBButtonLayoutDirectionDefault = 0,
    CCBButtonLayoutDirectionHorizontal = CCBButtonLayoutDirectionDefault,
    CCBButtonLayoutDirectionVertical = 2
} CCBButtonLayoutDirection;

/**
 *  按钮基类
 */
@interface CCBButton : UIButton
/** *  按钮的布局方向(horizontal:图片左，文字右；vertical:文字下，图片上) */
@property (nonatomic, assign) CCBButtonLayoutDirection layoutDirection;

/**
 *  通过设置urlString获取网络图片
 */
//@property (nonatomic, strong) NSString *imageUrlString;
/**  点击后是否不等待1秒，默认否   **/
@property (nonatomic, assign) BOOL notWaittingAfterClick;
//额外获得button的title，处理button另外添加label显示文字的情况
-(NSString *) getExtenTitle;
@end
