//
//  CCBWapCommCheckStatus.h
//  CCBMobileBankFoundation
//
//  Created by mac on 16/5/7.
//  Copyright © 2016年 CCB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HttpRequestDelegate.h"

typedef void (^ServerTimeBlock) (BOOL isSucc,NSString *reqTime);


@interface CCBWapCommTime : NSObject
/**
 *  获取网站交易所需要的时间值
 */
-(void)getServerTime;

@property (nonatomic, copy) ServerTimeBlock timeBlock;


@end
