//
//  CCBKeyboardLibDelegate.h
//  CCBKeyboardLib
//
//  Created by ccb on 14-10-15.
//  Copyright (c) 2014年 tendyron. All rights reserved.
//

#import <Foundation/Foundation.h>

//密码键盘输入代理定义
@protocol CCBKeyboardLibDelegate <NSObject>

//1-输入框输入有改变回调接口
- (void)textField:(id)textView textHasChange:(NSString *)currentText ;

//2-该接口是只有用户明确点击“完成”按钮才会触发，该接口回调完毕后最后还会回调- (void)textFieldDidEndEditing:(UITextField *)textField接口
-(void)customTextFieldDidEndEditing:(UITextField *)textField;

//3-该接口是只有用户明确点击“取消”按钮才会触发，该接口回调完毕后最后还会回调- (void)textFieldDidEndEditing:(UITextField *)textField接口
-(void)cancleTextFieldDidEndEditing:(UITextField *)textField;

//4-如用户不点击“完成”“取消”按钮导致输入框失去焦点情况的，只会回调- (void)textFieldDidEndEditing:(UITextField *)textField接口

//清空输入域的回调
-(BOOL) kbtextFieldShouldClear:(UITextField *)textField;

@end
