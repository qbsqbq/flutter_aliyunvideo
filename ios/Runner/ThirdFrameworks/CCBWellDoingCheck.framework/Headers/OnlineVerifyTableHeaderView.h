//
//  OnlineVerifyTableHeaderView.h
//  CloudAuthentication
//
//  Created by zhuqimin on 2018/5/31.
//  Copyright © 2018年 ccbMobileBank. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface OnlineVerifyTableHeaderView : UIView

/** *  header显示的标题 */
@property (nonatomic, strong) NSString *title;
/** *  是否显示底部分割线 */
@property (nonatomic, assign) BOOL showBottomLine;
/**  左侧标题   **/
@property (nonatomic, strong) CCBLabel *leftTitleLabel;

@end
