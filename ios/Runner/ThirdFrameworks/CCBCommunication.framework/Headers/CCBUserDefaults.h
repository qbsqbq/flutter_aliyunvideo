//
//  NTUserDefaults.h
//  CCBClientV2
//
//  Created by cyg on 14/12/16.
//  Copyright (c) 2014年 llbt. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface CCBUserDefaults : NSObject

+ (instancetype)instance;
+ (instancetype)standardUserDefaults;

- (id)objectForKey:(NSString *)defaultName;
- (id)valueForKey:(NSString *)defaultName;
- (void)setObject:(id)value forKey:(NSString *)defaultName;
- (void)setValue:(id)value forKey:(NSString *)key;
- (void)removeObjectForKey:(NSString *)defaultName;

- (NSString *)stringForKey:(NSString *)defaultName;
- (NSArray *)arrayForKey:(NSString *)defaultName;//
- (NSDictionary *)dictionaryForKey:(NSString *)defaultName;
- (NSInteger)integerForKey:(NSString *)defaultName;
- (BOOL)boolForKey:(NSString *)defaultName;
- (float)floatForKey:(NSString *)defaultName;//
- (double)doubleForKey:(NSString *)defaultName;//

- (BOOL)synchronize;

- (void)setInteger:(NSInteger)value forKey:(NSString *)defaultName;
- (void)setBool:(BOOL)value forKey:(NSString *)defaultName;
- (void)setFloat:(float)value forKey:(NSString *)defaultName;//
- (void)setDouble:(double)value forKey:(NSString *)defaultName;//

-(void)selfTest;

@end
