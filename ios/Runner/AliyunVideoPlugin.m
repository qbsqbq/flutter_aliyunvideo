//
//  AliyunVideoPlugin.m
//  Runner
//
//  Created by HopeSoft on 2020/4/1.
//  Copyright © 2020 The Chromium Authors. All rights reserved.
//

#import "AliyunVideoPlugin.h"
#import "AlivcShortVideoRoute.h"


@interface AliyunVideoPlugin()
@property(nonatomic,strong)FlutterResult Flutterresult;
@end

@implementation AliyunVideoPlugin

-(void)handleMethodCall:(FlutterMethodCall *)call result:(FlutterResult)result{
    
    if ([@"startVideo" isEqualToString:call.method]) {
        
        self.Flutterresult = result;
        
        AliyunMediaConfig *defauleMedia = [AliyunMediaConfig defaultConfig];
           
        defauleMedia.minDuration = 2;
        defauleMedia.maxDuration = 15;
        defauleMedia.gop = 30;
        [[AlivcShortVideoRoute shared]registerMediaConfig:defauleMedia];
        UIViewController *record = [[AlivcShortVideoRoute shared] alivcViewControllerWithType:AlivcViewControlRecord];
    
        //注册通知
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(callResult:) name:@"callResultValue" object:nil];
        
        //跳转
        record.modalPresentationStyle = 0;
        [[UIApplication sharedApplication].windows.firstObject.rootViewController presentViewController:record animated:YES completion:nil];
        
    }
}


+ (void)registerWithRegistrar:(NSObject <FlutterPluginRegistrar> *)registrar {
    

    FlutterMethodChannel *channel = [FlutterMethodChannel methodChannelWithName:@"aliyun_video" binaryMessenger:[registrar messenger] ];
    AliyunVideoPlugin* instance = [[AliyunVideoPlugin alloc] init];
    [registrar addMethodCallDelegate:instance channel:channel];
 }

 
-(void)callResult:(NSNotification*)center
{
    NSDictionary *dic = center.object;

    NSError *err;
    NSData *data = [NSJSONSerialization dataWithJSONObject:dic options:NSJSONWritingPrettyPrinted error:&err];
    NSString *str =  [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];

      NSLog(@"------%@",str);
    
    self.Flutterresult(str);
    
  
}


@end
