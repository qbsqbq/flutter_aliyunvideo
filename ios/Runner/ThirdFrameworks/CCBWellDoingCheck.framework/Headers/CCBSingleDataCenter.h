//
//  CCBSingleDataCenter.h
//  CCBMobileBankFoundation
//
//  Created by lwj on 16/8/18.
//  Copyright © 2016年 CCB. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CCBSingleDataCenter : NSObject

+ (instancetype)instance;
/*
 *
 *关于包内需要使用到的参数请通过该类赋值，该类只缓存在内存中，随app周期性消失。
 *
 */
-(void)addUserData:(NSString*)key data:(id)data;
-(void)delUserData:(NSString*)key;
-(id)getUserData:(NSString*)key;

@end
