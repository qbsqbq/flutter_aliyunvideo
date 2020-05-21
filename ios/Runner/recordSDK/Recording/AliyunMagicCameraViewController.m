//
//  AliyunMagicCameraViewController.m
//  AliyunVideoClient_Entrance
//
//  Created by wanghao on 2019/2/20.
//  Copyright © 2019年 Alibaba. All rights reserved.
//

#import "AliyunMagicCameraViewController.h"
#import <AliyunVideoSDKPro/AliyunIRecorder.h>
#import <AliyunVideoSDKPro/AliyunErrorCode.h>
#import <CoreMotion/CoreMotion.h>

#import "AVC_ShortVideo_Config.h"
#import "AlivcDefine.h"
#import "AliyunPathManager.h"
#import "AlivcUIConfig.h"
#import "MBProgressHUD+AlivcHelper.h"
#import "AlivcShortVideoRoute.h"
#import "AliyunReachability.h"
//view
#import "AlivcRecordNavigationBar.h"
#import "QUProgressView.h"
#import "AlivcRecordBottomView.h"     //底部按钮
#import "AlivcRecordFocusView.h"      //焦点

@interface AliyunMagicCameraViewController ()<AliyunIRecorderDelegate,AlivcRecordBottomViewDelegate,
AlivcRecordNavigationBarDelegate>
//SDK
@property (nonatomic, strong) AliyunIRecorder *recorder;        //录制
//system
@property (nonatomic, strong) CMMotionManager *motionManager;   //陀螺仪
//view
@property (nonatomic, strong) QUProgressView *progressView;                 //进度条
@property (nonatomic, strong) AlivcRecordNavigationBar *navigationBar;      //顶部导航栏
@property (nonatomic, strong) AlivcRecordBottomView *bottomView;        //底部view
@property (nonatomic, strong) AlivcRecordFocusView *focusView;          //聚焦框
//data
@property (nonatomic, strong) AliyunReachability *reachability;         //网络监听

@property (nonatomic, assign) BOOL shouldStartPreviewWhenActive;    //跳转其他页面停止预览，返回开始预览，退后台进入前台则一直在预览。这2种情况通过此变量区别。

@property (nonatomic, assign) CGFloat recorderDuration; //本地记录的视频录制时长

@property (nonatomic, strong) NSOperationQueue *queue;
@end

@implementation AliyunMagicCameraViewController
{
    NSInteger _cameraRotate; //相机旋转角度
    CGSize _outputSize;     //初始输出分辨率，此值切换画幅的时候用到
    NSInteger _musicTab;   //之前选中的音乐tab：本地、远程
    //    BOOL _stopRecordActionUnfinished; //录制结束动作未完成，（有个场景需求是调用stopRecording和回调recorderDidStopRecording返回之间不响应录制按钮事件）
}
- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    self.view.backgroundColor = [UIColor blackColor];
    //开启陀螺仪获取手机旋转角度
    [self startRetainCameraRotate];
    [self updateNavigationBarTorchModeStatus];
    [[UIApplication sharedApplication] setIdleTimerDisabled:YES];//录制模块禁止自动熄屏
    [[UIApplication sharedApplication] setStatusBarHidden:YES withAnimation:UIStatusBarAnimationNone];
    self.navigationController.interactivePopGestureRecognizer.enabled = NO;
    if (self.shouldStartPreviewWhenActive) {
        [self.recorder startPreview];
        self.shouldStartPreviewWhenActive = NO;
    }
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    
    [self.motionManager stopDeviceMotionUpdates];
    [[UIApplication sharedApplication] setIdleTimerDisabled:NO];
    [[UIApplication sharedApplication] setStatusBarHidden:NO withAnimation:UIStatusBarAnimationNone];
    //关闭闪光灯
    [self.recorder switchTorchWithMode:AliyunIRecorderTorchModeOff];
    [self updateNavigationBarTorchModeStatus];
    self.navigationController.interactivePopGestureRecognizer.enabled = YES;
}

- (void)viewDidAppear:(BOOL)animated{
    [super viewDidAppear:animated];
    
    if (isRace) {
        NSString *watermarkPath = [AlivcImage pathOfImageName:@"watermark"];
        AliyunEffectImage *watermark =
        [[AliyunEffectImage alloc] initWithFile:watermarkPath];
        CGFloat outsizex = 44;
        CGFloat outsizey = 132;
        watermark.frame = CGRectMake(outsizex, outsizey, 42, 30);
        [self.recorder applyImage:watermark];
    }
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor redColor];
    
    //设置默认视频角度为
    //    _cameraRotate =90;
    //VC布局
    [self setupSubviews];
    //添加通知
    [self addNotification];
    //开始预览
    [self.recorder startPreviewWithPositon:AliyunIRecorderCameraPositionFront];

    //添加手势
    [self addGesture];
    //开启网络监听
    [self startNetworkReachability];
    //默认值设置
    self.shouldStartPreviewWhenActive = NO;
    self.recorderDuration = 0;
    
    self.queue = [[NSOperationQueue alloc] init];
    
}
- (void)setupSubviews{
    if (!_uiConfig) {
        _uiConfig =[[AlivcRecordUIConfig alloc]init];
    }
    self.view.backgroundColor = _uiConfig.backgroundColor;
   
    //添加预览view
    [self.view addSubview:self.recorder.preview];
    //添加顶部录制进度条
    [self.view addSubview:self.progressView];
    //添加顶部导航条
    _navigationBar =[[AlivcRecordNavigationBar alloc]initWithUIConfig:_uiConfig];
    _navigationBar.delegate =self;
    [self.view addSubview:_navigationBar];
  
    //添加底部view
    [self.view addSubview:self.bottomView];
   

}
// 监听通知
- (void)addNotification
{
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(appWillResignActive:) name:UIApplicationWillResignActiveNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(appDidBecomeActive:) name:UIApplicationDidBecomeActiveNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(resourceDelete:) name:AliyunEffectResourceDeleteNotification object:nil];
}
- (void)startNetworkReachability{
    //网络状态判定
    _reachability = [AliyunReachability reachabilityForInternetConnection];
    [_reachability startNotifier];
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(reachabilityChanged)
                                                 name:AliyunSVReachabilityChangedNotification
                                               object:nil];
}
// 资源被删除的通知
- (void)resourceDelete:(NSNotification *)noti{
    
}

- (void)appWillResignActive:(id)sender
{
    [self.recorder switchTorchWithMode:AliyunIRecorderTorchModeOff];
    if (self.recorder.isRecording) {
        [self.recorder stopRecording];
    }
    [self updateViewsStatus];
}


- (void)appDidBecomeActive:(id)sender
{
    //刷新闪光灯按钮状态
    [self updateNavigationBarTorchModeStatus];
}

#pragma mark - 网络变化
//网络状态判定
- (void)reachabilityChanged{
    AliyunSVNetworkStatus status = [self.reachability currentReachabilityStatus];
    if (status != AliyunSVNetworkStatusNotReachable) {
    }
}
//预览view的坐标大小计算
- (CGRect)previewFrame{
    CGFloat ratio =_quVideo.outputSize.width / _quVideo.outputSize.height;
    CGRect finalFrame = CGRectMake(0, NoStatusBarSafeTop+44+10, ScreenWidth, ScreenWidth /ratio);
    if ([_quVideo mediaRatio] == AliyunMediaRatio9To16){
        finalFrame =CGRectMake((ScreenWidth - ScreenHeight * ratio)/2.f , 0, ScreenHeight * ratio, ScreenHeight);
    }
    return finalFrame;
}


//更新UI状态
- (void)updateViewsStatus{
    //更新录制按钮下方的删除按钮状态
    [self.bottomView updateViewsWithVideoPartCount:[self partCount]];
    //更新录制时间
    [self.bottomView refreshRecorderVideoDuration:self.recorderDuration];
    //更新录制UI
    [self.bottomView updateRecorderUI];
    //更新导航栏完成按钮状态
    [self.navigationBar setFinishButtonEnabled:(self.recorderDuration >= [self finishButtonEnabledMinDuration])];
    //更新右侧按钮显示/隐藏状态
       [_navigationBar setHidden:(self.recorder.isRecording)];
    //更新定时录制按钮的可点击状态
    [_navigationBar setTimerButtonEnabled:(self.recorderDuration < [self maxDuration])];
}

//更新闪光灯按钮状态
- (void)updateNavigationBarTorchModeStatus{
    if (self.recorder.cameraPosition == AliyunIRecorderCameraPositionFront) {//前置摄像头禁用闪光灯
        [self.navigationBar setTorchButtonImageWithMode:AlivcRecordTorchModeDisabled];
    }else{//后置摄像头
        [self.navigationBar setTorchButtonImageWithMode:(AlivcRecordTorchMode)self.recorder.torchMode];
    }
}


- (CGFloat)finishButtonEnabledMinDuration {
    return _quVideo.minDuration;
}
#pragma mark - GET
- (AliyunIRecorder *)recorder{
    if (!_recorder) {
        //清除之前生成的录制路径
        NSString *recordDir = [AliyunPathManager createRecrodDir];
        [AliyunPathManager clearDir:recordDir];
        //生成这次的存储路径
        NSString *taskPath = [recordDir stringByAppendingPathComponent:[AliyunPathManager randomString]];
        //视频存储路径
        NSString *videoSavePath = [[taskPath stringByAppendingPathComponent:[AliyunPathManager randomString]] stringByAppendingPathExtension:@"mp4"];
        _recorder =[[AliyunIRecorder alloc] initWithDelegate:self videoSize:_quVideo.outputSize];
        _recorder.preview = [[UIView alloc]initWithFrame:self.view.bounds]; //修改过frmae
        _recorder.outputType = AliyunIRecorderVideoOutputPixelFormatType420f;//SDK自带人脸识别只支持YUV格式
        _recorder.useFaceDetect = YES;
        _recorder.faceDetectCount = 2;
        _recorder.faceDectectSync = NO;
        _recorder.frontCaptureSessionPreset = AVCaptureSessionPreset1280x720;
        _recorder.encodeMode = (_quVideo.encodeMode == AliyunEncodeModeSoftFFmpeg)?0:1;
        _recorder.GOP = _quVideo.gop;
        _recorder.videoQuality = (AliyunVideoQuality)_quVideo.videoQuality;
        _recorder.recordFps = _quVideo.fps;
        _recorder.outputPath = _quVideo.outputPath?_quVideo.outputPath:videoSavePath;
        _quVideo.outputPath = _recorder.outputPath;
        _recorder.taskPath = taskPath;
        _recorder.beautifyStatus = YES;
        _recorder.videoFlipH = _quVideo.videoFlipH;

        [self recorder:_recorder setMaxDuration:_quVideo.maxDuration];
        [self recorder:_recorder setMinDuration:_quVideo.minDuration];
    }
    return _recorder;
}

- (QUProgressView *)progressView{
    if (!_progressView) {
        _progressView =[[QUProgressView alloc] initWithFrame:CGRectMake(8, NoStatusBarSafeTop+4, ScreenWidth-16, 4)];
        _progressView.showBlink = NO;
        _progressView.showNoticePoint = YES;
        _progressView.layer.cornerRadius = CGRectGetHeight(_progressView.frame)/2;
        _progressView.layer.masksToBounds =YES;
        _progressView.backgroundColor = [UIColor colorWithWhite:0 alpha:0.34];
        _progressView.colorProgress = [UIColor colorWithHexString:@"0xFC4448"];
        _progressView.maxDuration = _quVideo.maxDuration;
        _progressView.minDuration = _quVideo.minDuration;
    }
    return _progressView;
}

- (AlivcRecordBottomView *)bottomView{
    if (!_bottomView) {
        _bottomView =[[AlivcRecordBottomView alloc] initWithFrame:CGRectMake(0, ScreenHeight-185-SafeBottom, ScreenWidth, 200) withUIConfig:self.uiConfig];
        _bottomView.delegate =self;
    }
    return _bottomView;
}

- (AlivcRecordFocusView *)focusView{
    if (!_focusView) {
        CGFloat size = 150;
        _focusView =[[AlivcRecordFocusView alloc]initWithFrame:CGRectMake(0, 0, size, size)];
        _focusView.animation =YES;
        [self.recorder.preview addSubview:_focusView];
    }
    return _focusView;
}

#pragma mark - SET
- (void)setQuVideo:(AliyunMediaConfig *)quVideo{
    //需要copy一份，不然录制模块的参数改动会保存到配置页面
    _quVideo = [quVideo copy];
    _outputSize = _quVideo.outputSize;
}

#pragma mark - AlivcRecordNavigationBarDelegate -
- (void)alivcRecordNavigationBarButtonActionType:(AlivcRecordNavigationBarType)type{
    switch (type) {
        case AlivcRecordNavigationBarTypeGoback://返回
        {
            [self.recorder stopPreview];
#warning 返回 -1
          
            [[UIApplication sharedApplication].windows.firstObject.rootViewController  dismissViewControllerAnimated:YES completion:^{
                   NSDictionary *par = @{@"fileType":@-1,@"filePath":@""};
                   [[NSNotificationCenter defaultCenter]postNotificationName:@"callResultValue" object:par];
               }];
        }
            break;
        case AlivcRecordNavigationBarTypeCameraSwitch://切换摄像头
        {
            if (![self checkAVAuthorizationStatus]) {
                return;
            }
            [self.recorder switchCameraPosition];
            [self updateNavigationBarTorchModeStatus];
        }
            break;
        case AlivcRecordNavigationBarTypeFlashMode://闪光灯
        {
            [self.recorder switchTorchWithMode:!self.recorder.torchMode];
            [self updateNavigationBarTorchModeStatus];
        }
            break;
        case AlivcRecordNavigationBarTypeFinish://完成
        {
            if(self.isMixedViedo) {
                [self recorderDidFinishRecording];
            }else{
                [self.recorder finishRecording];
            }
        }
            break;
        default:
            break;
    }
}

- (void)image:(UIImage *)image didFinishSavingWithError:(NSError *)error contextInfo:(void *)contextInfo
{
    [MBProgressHUD showMessage:@"图片已保存到相册中" inView:self.view];
}

- (void)alivcRecordBottomViewDidSelectRate:(CGFloat)rate{
    [self.recorder setRate:rate];
}

- (void)alivcRecordBottomViewDeleteVideoPart{
    [self deletePart];
    self.progressView.videoCount = [self partCount];
    self.recorderDuration =[self duration];
    [self.progressView updateProgress:[self duration]];
    [self updateViewsStatus];
}

- (BOOL)alivcRecordBottomViewStartRecord{

    if (![self checkAVAuthorizationStatus]) {
        return NO;
    }
    if ([self partCount]<=0) {
        
        self.recorder.cameraRotate = (int)_cameraRotate;
        _quVideo.videoRotate = self.recorder.cameraRotate;
    }
    if ([self.recorder startRecording] == 0) {
        [self updateViewsStatus];
        return YES;
    }else{
        return NO;
    }
}

- (void)alivcRecordBottomViewStopRecord{
   
    [self.recorder stopRecording];
    //刷新界面
    [self updateViewsStatus];
}
- (BOOL)alivcRecordBottomViewIsRecording{
    return self.recorder.isRecording;
}

//检测权限
-(BOOL)checkAVAuthorizationStatus{
    for (AVMediaType mediaType in @[AVMediaTypeVideo,AVMediaTypeAudio]) {
        if ([AVCaptureDevice authorizationStatusForMediaType:mediaType] != AVAuthorizationStatusAuthorized) {
            [self showAVAuthorizationAlertWithMediaType:mediaType];
            return NO;
        }
    }
    return YES;
}

//显示一个权限弹窗
-(void)showAVAuthorizationAlertWithMediaType:(AVMediaType)mediaType{
     __weak typeof(self) weakSelf = self;
    NSString *title =[@"打开相机失败" localString];
    NSString *message =[@"摄像头无权限" localString];
    if (mediaType == AVMediaTypeAudio) {
        title = [@"获取麦克风权限失败" localString];
        message =[@"麦克风无权限" localString];
    }
    UIAlertController *alertController =[UIAlertController alertControllerWithTitle:title message:message preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *action1 =[UIAlertAction actionWithTitle:[@"取消" localString] style:UIAlertActionStyleDestructive handler:nil];
    UIAlertAction *action2 =[UIAlertAction actionWithTitle:[@"设置" localString] style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [weakSelf goSetting];
    }];
    [alertController addAction:action1];
    [alertController addAction:action2];
    [self presentViewController:alertController animated:YES completion:nil];
}

- (void)goSetting {
     [[UIApplication sharedApplication]openURL:[NSURL URLWithString:UIApplicationOpenSettingsURLString]];
}

#pragma mark - AliyunIRecorderDelegate -
// 设备权限
- (void)recorderDeviceAuthorization:(AliyunIRecorderDeviceAuthor)status {
    dispatch_async(dispatch_get_main_queue(), ^{
        if (status == AliyunIRecorderDeviceAuthorAudioDenied) {
            [self showAVAuthorizationAlertWithMediaType:AVMediaTypeAudio];
        } else if (status == AliyunIRecorderDeviceAuthorVideoDenied) {
            [self showAVAuthorizationAlertWithMediaType:AVMediaTypeVideo];
        }
       
    });
}
// 录制进度
- (void)recorderVideoDuration:(CGFloat)duration{
    [self.progressView updateProgress:duration];
    [self.bottomView refreshRecorderVideoDuration:duration];
    self.recorderDuration = duration;
}
// 录制停止
- (void)recorderDidStopRecording{
    _progressView.videoCount = [self partCount];
    //更新录制按钮下方的删除按钮状态
    [self.bottomView updateViewsWithVideoPartCount:[self partCount]];
}

- (void)recorderDidFinishRecording{
    [self updateViewsStatus];
    //停止预览
    [self.recorder stopPreview];
    self.shouldStartPreviewWhenActive = YES;
    //跳转处理
    NSString *outputPath = self.recorder.outputPath;
    if (self.finishBlock) {
        self.finishBlock(outputPath);
    }else{
        //如果没有编辑类证明是race的demo
        
        //保存相册
//        if (isRace) {
//             UISaveVideoAtPathToSavedPhotosAlbum(self.recorder.outputPath, self, @selector(video:didFinishSavingWithError:contextInfo:), nil);
//            return;
//        }
        [[AlivcShortVideoRoute shared]registerEditVideoPath:outputPath];
        [[AlivcShortVideoRoute shared]registerEditMediasPath:nil];
        [[AlivcShortVideoRoute shared]registerMediaConfig:_quVideo];
        
        [[AlivcShortVideoRoute shared] registerIsMixedVideo:self.isMixedViedo];
       
    
        //编辑页
//        UIViewController *editVC = [[AlivcShortVideoRoute shared]alivcViewControllerWithType:AlivcViewControlEdit];
//        if (editVC) {
//             [self.navigationController pushViewController:editVC animated:YES];
//        }else{
//             UISaveVideoAtPathToSavedPhotosAlbum(self.recorder.outputPath, self, @selector(video:didFinishSavingWithError:contextInfo:), nil);
//        }
    }
    
    NSLog(@"outputPath==%@",outputPath);
     [[UIApplication sharedApplication].windows.firstObject.rootViewController  dismissViewControllerAnimated:YES completion:^{
        NSDictionary *par = @{@"fileType":@0,@"filePath":outputPath};
        [[NSNotificationCenter defaultCenter]postNotificationName:@"callResultValue" object:par];
    }];
    [MBProgressHUD hideHUDForView:self.view animated:YES];
}

//当录至最大时长时回调
- (void)recorderDidStopWithMaxDuration{
    
    [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    [self.recorder finishRecording];
}

// 录制异常
- (void)recoderError:(NSError *)error {
    [MBProgressHUD hideHUDForView:self.view animated:YES];
    [MBProgressHUD showWarningMessage:[NSString stringWithFormat:@"录制异常：%@",error.localizedDescription] inView:self.view];
    [self updateViewsStatus];
}

//添加手势
- (void)addGesture
{
    UITapGestureRecognizer *tapGesture = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(tapToFocusPoint:)];
    [self.recorder.preview addGestureRecognizer:tapGesture];
    UIPinchGestureRecognizer *pinchGesture = [[UIPinchGestureRecognizer alloc] initWithTarget:self action:@selector(pinchGesture:)];
    [self.recorder.preview addGestureRecognizer:pinchGesture];
}

//点按手势的触发方法
- (void)tapToFocusPoint:(UITapGestureRecognizer *)tapGesture {
    UIView *tapView = tapGesture.view;
    CGPoint point = [tapGesture locationInView:tapView];
    self.recorder.focusPoint = point;
    self.focusView.center = point;
    [self.recorder.preview bringSubviewToFront:self.focusView];
}

//捏合手势的触发方法
- (void)pinchGesture:(UIPinchGestureRecognizer *)pinchGesture {
    if (isnan(pinchGesture.velocity) || pinchGesture.numberOfTouches != 2) {
        return;
    }
    self.recorder.videoZoomFactor = pinchGesture.velocity;
    pinchGesture.scale = 1;
    return;
}
- (void)startRetainCameraRotate {
    //初始化全局管理对象
    if (!self.motionManager) {
        self.motionManager = [[CMMotionManager alloc] init];
    }
    if ([self.motionManager isDeviceMotionAvailable]) {
        self.motionManager.deviceMotionUpdateInterval =1;
        [self.motionManager startDeviceMotionUpdatesToQueue:self.queue withHandler:^(CMDeviceMotion * _Nullable motion, NSError * _Nullable error) {
            // Gravity 获取手机的重力值在各个方向上的分量，根据这个就可以获得手机的空间位置，倾斜角度等
            double gravityX = motion.gravity.x;
            double gravityY = motion.gravity.y;
            double xyTheta = atan2(gravityX,gravityY)/M_PI*180.0;//手机旋转角度。
            if (xyTheta >= -45 && xyTheta <= 45) {//down
                self->_cameraRotate =180;
            } else if (xyTheta > 45 && xyTheta < 135) {//left
                self->_cameraRotate = 90;
            } else if ((xyTheta >= 135 && xyTheta < 180) || (xyTheta >= -180 && xyTheta < -135)) {//up
                self->_cameraRotate = 0;
            } else if (xyTheta >= -135 && xyTheta < -45) {//right
                self->_cameraRotate = 270;
            }
            //            NSLog(@"手机旋转的角度为 --- %d", _cameraRotate);
        }];
    }
}
 
//- (void)video:(NSString *)videoPath didFinishSavingWithError:(NSError *)error contextInfo: (void *)contextInfo {
//    [MBProgressHUD showMessage:NSLocalizedString(@"已保存到手机相册", nil) inView:self.view];
//    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//      [self.navigationController popViewControllerAnimated:YES];
//    });
//}
  

#pragma mark - 设备旋转
- (BOOL)shouldAutorotate
{
    return YES;
}

// 竖屏显示
- (UIInterfaceOrientationMask)supportedInterfaceOrientations
{
    return UIInterfaceOrientationMaskPortrait;
}

- (void)dealloc
{
    [_recorder stopPreview];
    [_recorder destroyRecorder];
    _recorder = nil;
}

- (NSInteger)partCount {
    return self.recorder.clipManager.partCount;
}

- (CGFloat)duration {
    return self.recorder.clipManager.duration;
    //    return self.recorderDuration;
}

- (void)deletePart {
    [self.recorder.clipManager deletePart];
}

- (void)recorder:(AliyunIRecorder *)recorder setMaxDuration:(CGFloat)maxDuration {
    recorder.clipManager.maxDuration = maxDuration;
}
- (CGFloat)maxDuration {
    return self.recorder.clipManager.maxDuration;
}

- (void)recorder:(AliyunIRecorder *)recorder setMinDuration:(CGFloat)minDuration {
    recorder.clipManager.minDuration = minDuration;
}


@end
