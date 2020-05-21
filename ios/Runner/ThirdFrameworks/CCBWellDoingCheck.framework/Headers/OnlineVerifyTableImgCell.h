//
//  ImgTableViewCell.h
//  CloudAuthentication
//
//  Created by zhuqimin on 2018/5/31.
//  Copyright © 2018年 ccbMobileBank. All rights reserved.
//

#import <UIKit/UIKit.h>

@class OnlineVerifyTableImgCell;

@protocol CCBImgFormCellDelegate <NSObject>

- (void)formCell:(OnlineVerifyTableImgCell*)cell imgBtnDidClicked:(UIButton*)btn;

@end

@interface OnlineVerifyTableImgCell : UIView

@property (nonatomic, weak) id<CCBImgFormCellDelegate> delegate;

- (void)setImg:(UIImage*)img;

+(CGFloat)cellHeightForImgViewCell;

@end
