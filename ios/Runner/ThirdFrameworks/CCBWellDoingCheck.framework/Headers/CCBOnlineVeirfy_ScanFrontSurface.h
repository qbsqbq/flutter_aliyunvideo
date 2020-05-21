//
//  CCBOnlineVeirfy_ScanFrontSurface.h
//  CloudAuthentication
//
//  Created by zhuqimin on 2018/5/31.
//  Copyright © 2018年 ccbMobileBank. All rights reserved.
//

//#import <CloudAuthentication/CloudAuthentication.h>
#import "CCBViewController.h"
#import "CCB_OnlineSign_Model.h"
@class CCBBaseError;
@class CCBBaseModel;

@interface CCBOnlineVeirfy_ScanFrontSurface : CCBViewController

@property (nonatomic, strong) NSString *appKey;

@property (nonatomic, strong) NSString *subKey;
@property (nonatomic, strong) NSString *Comm_Auth_Fields;

@property (nonatomic, copy) void(^callback)(BOOL isSuccess, CCBBaseError *error);

@property (nonatomic, strong) CCB_OnlineSign_Model *signModel;

@property (nonatomic, strong) NSString *cardID;

@property (nonatomic, strong) UIViewController *popToVc;
@property (nonatomic, strong) NSNumber *qualityNumber;
@property (nonatomic, assign)  bool isThreeAction;


@end
