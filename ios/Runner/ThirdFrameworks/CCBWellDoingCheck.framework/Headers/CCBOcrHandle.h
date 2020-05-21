//
//  ISeAuth.h
//  ISIDReaderCameraPreviewSDKDemo
//
//  Created by Simon Liu on 2018/1/17.
//  Copyright © 2018年 柳宣泽. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
typedef NS_ENUM(NSInteger, cardType) {
    CARD_ID, //身份证
    CARD_BANK //银行卡
};

typedef NS_ENUM(NSInteger, cardSide) {
    CARD_SIDE_FONT = 1, //身份证正面
    CARD_SURFACE_BACK//身份证反面
};


typedef void (^IDCardInfoCallback) (NSDictionary *cardInfoDic,NSError* error);


typedef void (^BankCardInfoCallback) (NSDictionary *cardInfoDic,NSError* error);

@interface CCBOcrHandle : NSObject

/* @abstract
 初始化SDK，并且根据需求配置相关参数选项
 @param
 customDictionary:参数字典，具体参数详见接口说明
 
 */

- (instancetype)initWithAuth:(NSDictionary*)customDictionary ;

//身份证、银行卡
- (void)eAuthOcrScan:(id)sender ocrScanType:(cardType)ocrScanType idCardSurface:(cardSide)idCardSurface cardInfocb:(IDCardInfoCallback)cardInfocb ;


- (NSString*)eAuthSDKVesion ;

@end
