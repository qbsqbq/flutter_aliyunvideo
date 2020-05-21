//
//  ISBankCardController.h
//  ISBankCard
//
//  Created by Simon Liu on 17/09/12.
//  Copyright (c) 2017年 xzliu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ISOpenSDKFoundation/ISOpenSDKFoundation.h>
#import <CoreMedia/CoreMedia.h>

typedef NS_ENUM(NSInteger, ISBankCardType) {
    ISBankCardTypeNone = 0,
    ISBankCardTypeCreditCard, //贷记卡
    ISBankCardTypeDebitCard, //借记卡
    ISBankCardTypeQuasiCreditCard //准贷记卡
};

typedef NS_ENUM(NSInteger, ISCreditCardType) {
    ISCreditCardTypeNone = 0,
    ISCreditCardTypeVISA,         // Visa
    ISCreditCardTypeMASTER,       // MasterCard
    ISCreditCardTypeMAESTRO,      // Maestro
    ISCreditCardTypeAMEX,         // American Express
    ISCreditCardTypeDINERS,       // Diners Club
    ISCreditCardTypeDISCOVER,     // Discover
    ISCreditCardTypeJCB,          // JCB
    ISCreditCardTypeUNIONPAY      // China UNIONPAY
};

typedef void(^ConstructResourcesFinishHandler)(ISOpenSDKStatus status);
typedef void(^DetectCardFinishHandler)(int result, NSArray *borderPointsArray);
typedef void(^RecognizeCardFinishHandler)(NSDictionary *cardInfo);
typedef void(^AccessRawDataFinishHandler)(uint8_t *rawData, int rawDataWidth, int rawDataHeight);
typedef void(^RecorgnizeInstitutionFinishHandler)(NSString *institutionName, NSString *institutionID);

extern NSString *const kBankCardType;//bank card type, defined in ISBankCardType(银⾏行卡类型)
extern NSString *const kCreditCardType;//credit card type, defined in ISCreditCardType(信用卡类型)
extern NSString *const kCardNumber;//card number(卡号)
extern NSString *const kExpiryDate;//expire date(过期时间)
extern NSString *const kHolderName;//holder name(持卡⼈)
extern NSString *const kBankName;//bank name(银⾏名)
extern NSString *const kBankID;//bank ID(发卡机构ID)
extern NSString *const kCardNumberRect;//the card number rect in cropped card image(卡号在银行卡截图上的矩形位置)
extern NSString *const kCardNumberOriginalBorderPoints;//the four points of card number rect in original image(卡号在原图上的位置)
extern NSString *const kBankNumberImage;//bank card number image(卡号截图)

@interface ISBankCardController : NSObject<ISPreviewSDKProtocol>

+ (ISBankCardController *)sharedISOpenSDKController;

/*
 Call this method to get the built in ISOpenSDKCameraViewController that defined in <ISOpenSDKFoundation.framework/ISOpenSDKCameraViewController.h>
 调用该方法获取内置的拍照界面，拍照界面详细定义请参见<ISOpenSDKFoundation.framework/ISOpenSDKCameraViewController.h>
 */
- (ISOpenSDKCameraViewController *)cameraViewControllerWithAppkey:(NSString *)appKey
                                                        subAppkey:(NSString *)subAppKey;

#pragma mark --

/* 
 You should call this method to construct resources before call other APIs in the SDK,calling this API will cause an online authorization for the first time this SDK is used.Once authorized successfully, this API will be returned immediately within expire time and try to update authorization status in background
 */
- (void)constructResourcesWithAppKey:(NSString *)appKey
                           subAppkey:(NSString *)subAppKey
                       finishHandler:(ConstructResourcesFinishHandler)handler;

/*
 Use this method to recognize one card.
 */
- (ISOpenSDKStatus)detectCardWithOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer
                                           cardRect:(CGRect)rect//rect should be a golden rect for credit cards that are shaped with its proportions
                            detectCardFinishHandler:(DetectCardFinishHandler)detectCardFinishHandler
                         recognizeCardFinishHandler:(RecognizeCardFinishHandler)recognizeFinishHandler;

/*
 Use this mothod to release SDK resources
 */
- (void)destructBankCardResources;

/*
  get SDK Version
 */
+ (NSString *)getSDKVersion;
@end
