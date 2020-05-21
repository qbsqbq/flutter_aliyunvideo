//
//  FXPressButton.h
//  CCBClientV2
//
//  Created by zhuqimin on 14-11-7.
//  Copyright (c) 2014年 llbt. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef void (^pressbackBlock)();
typedef void (^outbackBlock)();

@interface CCB_FXPressButton_Voiceprint : CCBView

@property (nonatomic, strong) CCBImageView *imageView;
@property (nonatomic, copy) void (^pressbackBlock)();//按钮点击回调
@property (nonatomic, copy) void (^outbackBlock)();//按钮松开回调

- (id)initWithFrame:(CGRect)frame withImageName:(UIImage *)onImage pressBlock:(pressbackBlock)pressblock outBlock:(outbackBlock)outblock;
//- (id)initWithImageName:(UIImage *)onImage pressBlock:(pressbackBlock)pressblock outBlock:(outbackBlock)outblock;
@end
