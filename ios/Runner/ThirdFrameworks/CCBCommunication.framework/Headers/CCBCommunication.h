//
//  CCBCommunication.h
//  CCBCommunication
//
//  Created by songrz on 2018/1/1.
//  Copyright © 2018年 srz. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CCBBaseRequestModel.h"
#import "CCBCommandManager.h"
#import "CCBBaseViewModel.h"
#import "CCBBaseModel.h"
#import "CCBWapCommTime.h"
#import "CCBBaseError.h"
#import "CCBFunctionUtil.h"
#import "CCBUserDefaults.h"

//是否打印Log日志，否注释掉下行
#define _SHOW_DEBUG_LOG_

#ifdef _SHOW_DEBUG_LOG_
#define CCBLogDebug(...) NSLog(__VA_ARGS__)
#else
#define CCBLogDebug(...)
#endif

//! Project version number for CCBCommunication.
FOUNDATION_EXPORT double CCBCommunicationVersionNumber;

//! Project version string for CCBCommunication.
FOUNDATION_EXPORT const unsigned char CCBCommunicationVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <CCBCommunication/PublicHeader.h>


