//
//  CCBSetVarManager.h
//  CCBMobileBank
//
//  Created by zhuqimin on 16/5/5.
//  Copyright © 2016年 CCB. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CCBSetVarManager : NSObject

+ (instancetype)getInstance;

- (void)setLocalValue:(id)value forKey:(NSString*)key;

- (id)localObjectForKey:(NSString*)key;

- (void)clearAllValue;

@end
