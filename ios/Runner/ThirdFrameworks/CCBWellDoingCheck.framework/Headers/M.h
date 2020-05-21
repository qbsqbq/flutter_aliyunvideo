//
//  M.h
//  CCBMobileBankFoundation
//
//  Created by ios zixin on 6/9/17.
//  Copyright © 2017 CCB. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface M : NSObject

// 获取当前屏幕的scale值，或许有想法的人需要。
+(double) A;

//字体大小调节
+(double) B;

//ccbImage
+(UIImage*) C:(NSString*)name;

//ccbString
+(NSString *) D:(NSString*)string;

//fonts
+(UIFont *) F:(CGFloat)size;

//ccbString E
+(NSString*) E:(NSString*)string;
@end
