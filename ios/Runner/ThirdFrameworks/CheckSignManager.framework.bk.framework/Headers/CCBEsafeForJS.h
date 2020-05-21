//
//  CCBKeyboardForJS.h
//  UIWebDemo
//
//  Created by ccb on 14-4-17.
//  Copyright (c) 2014年 wlx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CheckSignManager.h"
//代理定义
@protocol CCBKeyboardForJSDelegate

//输入框编辑完成回调接口
- (void)htmlFieldDidEndEditing:(NSString *)textFieldid info:(NSDictionary *)infoDicMsg;

@end

@interface CCBEsafeForJS : NSObject<UIWebViewDelegate,UITextFieldDelegate>

//初始化密码键盘

+ (id)initKeyBoardWithDelegate:(id <CCBKeyboardForJSDelegate>)delegate dealWebView:(UIWebView *)webview associateView:(UIView *)view;


- (BOOL)filterUrl:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType;






@end
