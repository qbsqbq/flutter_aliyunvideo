//
//  CCBBaseFormViewModel+Private.h
//  CCBMobileBank
//
//  Created by Ansonyc on 16/4/14.
//  Copyright © 2016年 CCB. All rights reserved.
//

#import "CCBBaseFormViewModel.h"

@interface CCBBaseFormViewModel (Private)

/** * 表单数组 */
@property (nonatomic, strong) NSArray *formItems;

@end

/**
 *  NSString的简便方法
 */
@interface NSString (Util)

/*
 参数 aString：需要比较的string
 返回：YES 相等，NO 不相符
 
 忽略大小写的对照，两个字符串知否相等
 */
//-(BOOL) isEqualToIgnoreCaseString: (NSString *) aString;


//判断字符串是否为空
- (BOOL)isEmpty;

//判断输入string是否不合法
+ (BOOL)isEmptyString:(NSString *)string;

//- (NSString *) urlEncodeValue;
//
///**
// *  3des 加解密
// *
// *  @param plainText        需要进行加解密数据
// *  @param encryptOrDecrypt 加密还是解密
// *  @param key              加解密key
// *
// *  @return 加解密后数据
// */
//+ (NSString*)TripleDES:(NSString*)plainText encryptOrDecrypt:(CCOperation)encryptOrDecrypt key:(NSString*)key;
//
///**
// *  3des 加解密
// *
// *  @param plainText        需要进行加解密数据
// *  @param encryptOrDecrypt 加密还是解密
// *  @param key              加解密key
// *  @param initVec
// *
// *  @return 加解密后数据
// */
//+ (NSData*)TripleDESForData:(NSData*)plainText encryptOrDecrypt:(CCOperation)encryptOrDecrypt key:(NSString*)key initVec:(NSString *)initVec;
//
///**
// *  3des 加解密
// *
// *  @param plainText        需要进行加解密数据
// *  @param encryptOrDecrypt 加密还是解密
// *  @param key              加解密key
// *  @param initVec
// *
// *  @return 加解密后数据
// */
//+ (NSString*)TripleDES:(NSString*)plainText encryptOrDecrypt:(CCOperation)encryptOrDecrypt key:(NSString*)key initVec:(NSString *)initVec;
//
//- (NSString *)subStringBetween:(NSString *)beginStr with:(NSString *)endStr;
//
//- (NSArray *)subStringArrayBetween:(NSString *)beginStr with:(NSString *)endStr;
//
////加密字符串
//+(NSString *)isEncryptStr:(NSString *)str;
//
////去除空格
//- (NSString *)trim;
////去除空格
//+ (NSString *)trimUtil:(NSString *)str;
//
////字符串434格式
//+(NSString *)accountFormat:(NSString *)accNO;
//
////将账号每4位加一个空格
//+(NSString *)accountFillSpace:(NSString *)accStr;
//
//- (BOOL)containsString:(NSString *)str;
//
////将楼层ID转化成int型
//-(NSInteger)flooridConversion;

@end
