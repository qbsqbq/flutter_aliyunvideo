//
//  CCBKeyboardLib.h
//  CCBKeyboardLib
//
//  Created by tdr on 13-6-27.
//  Copyright (c) 2013年 tendyron. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
//#import "KeyboardController.h"
//@class KeyboardController;

@interface CCBKeyboardLib : NSObject

//AES加解密算法
//v13
+(NSData*)doEnAES:(NSString*)plainText;

+(NSString*)doDeAES:(NSData*)cipherText;

//AES白盒算法
//v13
+(NSData*)doEnAESWhiteBox:(NSString*)plainText;

+(NSString*)doDeAESWhiteBox:(NSData*)cipherText;


//AES加解密算法
+(NSString*)doEncAES_Data:(NSData *)OCplaintextData
                      key:(NSString *)OCKEY
                 encoding:(CFStringEncoding)cfchangencode;

+(NSString*)doEncAES_Str:(NSString *)OCplaintext
                     key:(NSString *)OCKEY
                encoding:(CFStringEncoding)cfchangencode;

+(NSData*)doDecAES_Data:(NSString *)OCCipherText
                    key:(NSString *)OCKEY
               encoding:(CFStringEncoding)cfchangencode;

+(NSString*)doDecAES_Str:(NSString *)OCCipherText
                     key:(NSString *)OCKEY
                encoding:(CFStringEncoding)cfchangencode;




//注册输入框使用的密码键盘样式。
//type 0 为随机字符键盘 1为随机数字键盘 2为随机符号键盘 3为正常顺序字符键盘
//扩展为：
//type=0 为随机字母键盘
//type=1 为随机数字键盘
//type=2 为随机符号键盘
//type=3 为正常顺序字母键盘且点击切换按钮到其他键盘也是正常顺序
//type=4 为正常顺序数字键盘且点击切换按钮到其他键盘也是正常顺序
//type=5 为正常顺序符号键盘且点击切换按钮到其他键盘也是正常顺序
//type=其他值  为注册失败
-(void)registerTextView:(id<UITextInput>)textView keyBoardTyep:(int)type;

//设置输入框长度上限
-(void)registerTextView:(id<UITextInput>)textView limitLen:(int)len;

//设置输入框是否含切换到系统键盘功能
-(void)setTextView:(id<UITextInput>)textView bToSystem:(BOOL)bToSystemKeyboard;


//设置输入框当调用加密接口是否连同hash值一起返回
-(void)setTextView:(id<UITextInput>)textView bHash:(BOOL)hash;


//设置输入框的使用的加密时间-必须是服务器系统时间(格式为:yyyyMMddHHmmssSSS)
-(void)setTextView:(id<UITextInput>)textView serverTime:(NSString*)keytime;


//重新设置某输入框所使用的密码键盘样式即锁定于某一键盘样式，并做特殊限制输入
//locktype=0 不锁定当前键盘，可切换键盘。
//locktype=1 锁定当前键盘，不可切换键盘。
//locktype=其他值 不做任何处理
-(void)setTextView:(id<UITextInput>)textView keyboardLock:(int)locktype;


//输入框使用密码键盘进行编辑输入（一般在输入控件获取焦点时调用）
-(void)setInputTextView:(id<UITextInput>)textView;

//获取的输入框的密文和hash值（一次一密）
-(int)getCipherText:(NSString**)cipher getHash:(NSData**)hash;

//比对两个HASH值
-(BOOL)cmpHash:(NSData*)hash1 withHash:(NSData*)hash2;


//获取明文输入
-(NSString *)getPasswordPlaintText;

//使用随机算法加密输入明文（随机密钥随机算法加密）
-(NSString *)getPasswordCipterText:(NSString *)Password;

//使用随机算法加密输入明文 (指定密钥随机算法加密)
+(NSString *)getPasswordCipterText:(NSString *)Password keytext:(NSString*)key;

//计算密码强度,返回值－1表示密码长度不够6位，0表示弱 ，1表示中，2表示强
+(int) CalcPasswordStrength:(NSString *)Password;

-(void)setDelete:(id)obj;  //for webview
//指定展现类型，不管当初注册的时候的类型  for webview
-(void)setInputTextView:(id<UITextInput>)textView specifyType:(int) keyBoardType;

// 函数：随机密钥加密，在原有基础上修改
// 返回值：加密是否成功  0-成功 其他-失败
// plain：加密原文
// cipher：返回密文
//hash：原文hash值，若未设置返回hash值选项，返回nil
-(int)plainText:(NSString*)plain getCipherText:(NSString**)cipher getHash:(NSData**)hash;

//添加自定义按钮 v12
-(void)addCustomButton:(UIImage*)background textBtn:(NSString*)btnTitle callBack:(SEL)callBack withClass:(id)iClass;

@end
