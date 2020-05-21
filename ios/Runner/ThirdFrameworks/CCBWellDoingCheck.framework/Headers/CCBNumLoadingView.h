//
//  CCBNumLoadingView.h
//  CCBMobileBank
//
//  Created by Yuga.L on 17/4/26.
//  Copyright © 2017年 ccbdeveloper. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface  CCBNumLoadingViewParam : NSObject

/**  是否是重要交易   **/
@property (nonatomic, assign) BOOL isImportant;
/**  计算的时间   **/
@property (nonatomic, assign) NSInteger dismissTimes;
/**  默认的时间   **/
@property (nonatomic, assign) NSInteger defaultDismissTimes;
@end

@class CCBNumLoadingView;
@protocol CCBNumLoadingViewDelegate <NSObject>

@optional

- (void)didShowLoadingView:(CCBNumLoadingView *)numLoadingView;
/*
 *  框架自动消除菊花或自己点击消除菊花时会调用该委托
 *
 */
- (void)didDismissLoadingView:(CCBNumLoadingView *)numLoadingView;

@end


/* 中间带数字倒数的loading菊花 */

@interface CCBNumLoadingView : UIView
/** 是否是超时消的菊花    **/
@property (nonatomic, assign) BOOL autoHideHud;
/**
 检测父视图是否已经显示了菊花

 @param superView 父视图
 @return 如果已经显示了, 返回当前菊花, 如果没有显示, 返回nil
 */
+ (CCBNumLoadingView *)checkDidShowNumLoadingView:(UIView *)superView;

/**
 显示中间带数字倒数的loading菊花

 @param superView 添加loading菊花的父视图
 */
+ (void)showNumLoadingView:(UIView *)superView dismissParam:(CCBNumLoadingViewParam*)dismissParam delegate:(id<CCBNumLoadingViewDelegate>)delegate;


/**
 销毁带数字倒数的loading菊花
 
 @param superView 添加loading菊花的父视图
 */
+ (void)dismissLoadingView:(UIView *)superView immediate:(BOOL)immediate;

@end
