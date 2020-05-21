//
//  AlivcImage.m
//  AliyunVideoClient_Entrance
//
//  Created by Zejian Cai on 2018/10/10.
//  Copyright © 2018年 Alibaba. All rights reserved.
//

#import "AlivcImage.h"

static NSString *theBundleName = @"Null";

@implementation AlivcImage

+ (void)setImageBundleName:(NSString *)bundleName{
    theBundleName = bundleName;
    
}

+ (UIImage *)imageNamed:(NSString *)imageName{
    
    NSString *fullPath =  [AlivcImage pathOfImageName:imageName];
    UIImage *image = [UIImage imageWithContentsOfFile:fullPath];
    
    
//    NSString *path = [NSString stringWithFormat:@"%@.bundle/%@",theBundleName,imageName];
//    UIImage *image = [UIImage imageNamed:path];
//    NSString *imagePath = [currentBundle pathForResource:imageName ofType:@"png" inDirectory:@"AlivcCore.bundle"];
//     NSString *imagePath = [currentBundle pathForResource:imageName ofType:@""];
    
    return image;
}

+ (NSString *__nullable)pathOfImageName:(NSString *)imageName {
    NSBundle *currentBundle = [NSBundle bundleForClass:[self class]];
     NSString *imagePath = [NSString stringWithFormat:@"AlivcShortVideoImage.bundle/%@",imageName];
     NSString *fullPath = [[currentBundle resourcePath] stringByAppendingPathComponent:imagePath];
    return fullPath;
}

+ (UIImage *__nullable)imageInSmartVideoNamed:(NSString *)imageName {
    NSBundle *currentBundle = [NSBundle bundleForClass:[self class]];
    NSString *imagePath = [NSString stringWithFormat:@"AlivcSmartVideo.bundle/%@",imageName];
    NSString *fullPath = [[currentBundle resourcePath] stringByAppendingPathComponent:imagePath];
    return [UIImage imageWithContentsOfFile:fullPath];
}

@end
