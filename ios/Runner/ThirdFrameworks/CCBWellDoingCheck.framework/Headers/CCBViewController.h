//
//  CCBViewController.h
//  CCBMobileBank
//
//  Created by jinhong on 16/3/30.
//  Copyright © 2016年 CCB. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CCBCommunication/CCBBaseViewModel.h>
//#import "CCBBaseViewModel.h"
//#import "ComConstants.h"
typedef enum {
    BaseAlertViewDefault = 0,   // 默认样式，显示提示内容，可以有标题，可以没有，无图片
    BaseAlertViewBig,            // 大型提示框 不带图片
    BaseAlertViewBySelf,        //成功页面弹出来的大字体alert框
    BaseAlertViewMessage,       // 废置。提示发送一条短信，显示短信图片
    BaseAlertViewWarn,          // 废置。带叹号图片的提示框
    BaseAlertViewCommon         // 废置。带勾图片的提示框
} BaseAlertViewType;

#pragma mark - CCBViewController
@interface CCBViewController : UIViewController<CCBViewModelDelegate>

/**  功能码   **/
@property(nonatomic,strong,nonnull)NSString *funcTradeId;

/**  功能title   **/
@property(nonatomic,strong,nonnull)NSString *funcTradeName;

/**
 *  是否显示左上角返回按钮
 *
 *  @param isVisible
 */
- (void)setNavLeftButtonVisible:(BOOL)isVisible;

/**
 *  点击NAV的右侧按钮,如果需要自己控制返回，请覆盖本方法。
 */
- (void)onTouchNavLeftButton;

- (void)setLeftButtonImg:(UIImage*)img;

/**
 *  通过参数配置创建当前的视图控制器
 *
 *  @param param 配置参数，用于设置当前视图控制器的属性
 *
 *  @return 当前视图控制器的实例
 */
- (nonnull instancetype)initWithParam:(nullable NSDictionary *)param;

/**
 *  通过键值对创建业务控制器（纯虚方法，由子类提供实现）
 *
 *  @param param 键值对
 *
 *  @return 业务控制器
 */
- (nullable CCBBaseViewModel *)createViewModelWithParam:(nullable NSDictionary *)param;

/**
 *  点击空白区域以取消编辑状态(子类重写本方法前需要先调用super)
 *
 *  @param gesture 点击事件
 */
- (void)didTapToHideKeyboard:(nullable UITapGestureRecognizer *)gesture;

/**
 *  点击弹出框的按钮后会调用本方法
 *
 *  @param index        点击的按钮的index
 *  @param title        弹出框标题
 *  @param message      弹出框的消息
 *  @param buttonTitles 弹出框的按钮文本数组
 *  @param tag          提示框标示
 */
- (void)alertViewDidClickedButtonAtIndex:(NSInteger)index
                                   title:(nullable NSString *)title
                                 message:(nullable NSString *)message
                            buttonTitles:(nullable NSArray *)buttonTitles
                                     tag:(NSUInteger)tag;

/**
 *  切换当前的VM
 *
 *  @param currentViewModel 当前使用的VM
 */
- (void)changeCurrentViewModel:(nullable CCBBaseViewModel *)currentViewModel;

/**
 *  刷新登录状态，需要根据登录状态刷新界面的地方，请重写该方法
 *  viewWillAppear 及  全局CCBLoginManager的isLogin变化时，会触发该方法
 *
 *  @param isLogin， 全局登录状态
 */
-(void) refreshLoginStatus:(bool)isLogin;

-(nonnull CCBViewController *)getCurrentVc;

/**  菊花是否需要显示 登录弹出来，菊花是否还需要展示的状态*/
@property (nonatomic, assign) BOOL hudIsNeedShow;

@end

#pragma mark - toast扩展
/**
 *  显示Toast时候的位置枚举类型
 */
typedef NS_ENUM(NSUInteger, CCBToastPostion) {
    /**
     *  上部
     */
    CCBToastPostionTop,
    /**
     *  下部
     */
    CCBToastPostionCenter,
    /**
     *  底部
     */
    CCBToastPostionBottom
};

/**
 *  toast扩展
 */
@interface CCBViewController (toast)

/**
 *  显示toast文本信息，显示3秒后消失
 *
 *  @param message 文字信息
 */
- (void)makeToast:(nonnull NSString *)message;

/**
 *  显示toast信息interval秒后消失
 *
 *  @param message  文字信息
 *  @param interval 显示多少秒
 *  @param position 位置
 */
- (void)makeToast:(nonnull NSString *)message duration:(NSTimeInterval)interval position:(CCBToastPostion)position;

@end

#pragma mark - alert功能的扩展
@interface CCBViewController (Alert)
NS_ASSUME_NONNULL_BEGIN
///**
// * 获取自己页面的PageID
// */
//- (nullable NSString *)CCBPageID;
//
/**
 弹窗显示错误信息，包括但不限于：错误信息，只能跳转提醒等。
 注意：因为存在可能的服务器配置强制转换，传入的错误信息，可能会被转换为其他错误信息。

 @param error 错误信息
 */
- (void)showError:(NSError *)error;
//
///**
// 弹窗显示错误信息，包括但不限于：错误信息，只能跳转提醒等。
// 注意：因为存在可能的服务器配置强制转换，1. 传入的错误信息，可能会被转换为其他错误信息; 2. 传入的callback回调不保证一定生效
//
// @param error 错误信息
// @param callback 弹窗操作回调
// */
- (void)showError:(NSError *)error callback:(nullable void(^)(int index))callback;
//
///**
// 弹窗显示错误信息，包括但不限于：错误信息，智能跳转提醒等。
// 注意：因为存在可能的服务器配置强制转换，1.传入的错误信息，弹窗按键文本，在此方法中可能会被转换为其他值。2. 传入的callBack回调不保证一定生效。
//
// @param aError 错误信息
// @param aTitles 弹窗按键文本数组. 缺省值为@["确定"]
// @param callBack 弹窗操作回调
// */
- (void)showError:(NSError *)aError buttonsTitles:(nullable NSArray *)aTitles
         callBack:(nullable void(^)(int index))callBack;
//
///**
// 弹窗显示与aPageID关联的错误信息
//
// @param aError 错误信息
// @param aPageID 页面ID
// */
//- (void)showError:(NSError *)aError atPage:(nullable NSString *)aPageID;
///**
// 弹窗显示与aPageID关联的错误信息
//
// @param aError 错误信息
// @param aTitles 弹窗按键文本数组. 缺省值为@["确定"]
// @param callBack 弹窗操作回调
// @param aPageID 页面ID
// */
//- (void)showError:(NSError *)aError atPage:(nullable NSString *)aPageID buttonsTitles:(nullable NSArray *)aTitles
//         callBack:(nullable void (^)(int index))callBack;
//
///**
// *  方法将遗弃，请不要使用。
// *  显示通讯错误提示语。
// *
// *  @param errCode 错误码
// *  @param errMsg  错误提示语
// */
//- (void)showCommunicationErrorMessageWithErrorCode:(nullable NSString *)errCode errMsg:(nullable NSString *)errMsg DEPRECATED_MSG_ATTRIBUTE("请使用 -(void)showError...系列方法");
//
//
///**
// *  方法将遗弃，请不要使用。
// *  显示错误提示语
// *
// *  @param message 错误提示语
// */
//- (void)showErrorMessage:(nullable NSString *)message DEPRECATED_MSG_ATTRIBUTE("请使用 -(void)showError...系列方法");
//
//
///**
// *  根据Domain显示错误提示语
// *  1.Domain == CCBCommunicationErrorDomain 显示通讯错误框（带错误码）
// *  2.Domain == 其它，显示错误提示框（无错误码）
// *
// *  @param error 错误
// */
//- (void)showErrorMessageWithDomain:(nullable NSError *)error;
//
///**
// *  显示成功提示语
// *
// *  @param message 成功提示语
// */
//- (void)showSuccMessage:(nullable NSString *)message;
//
///**
// *  显示提示框
// *
// *  @param title 提示框标题
// *  @param message 提示语
// *  @param arr  按钮文本数组
// *  @param type 提示框样式类型
// */
- (void)showWithTitle:(nullable NSString *)title
              message:(nullable NSString *)message
        btnTitleArray:(nullable NSArray *)array
            alertType:(BaseAlertViewType)type;
//
///**
// *  点击弹出框的按钮后会调用本方法
// *
// *  @param index        点击的按钮的index
// *  @param title        弹出框标题
// *  @param message      弹出框的消息
// *  @param buttonTitles 弹出框的按钮文本数组
// */
//- (void)alertViewDidClickedButtonAtIndex:(NSInteger)index
//                                   title:(nullable NSString *)title
//                                 message:(nullable NSString *)message
//                            buttonTitles:(nullable NSArray *)buttonTitles;
///**
// *  显示错误提示语
// *
// *  @param message 错误提示语
// *  @param tag     提示框标示
// */
//- (void)showErrorMessage:(nullable NSString *)message tag:(NSUInteger)tag;
//
///**
// *  显示成功提示语
// *
// *  @param message 成功提示语
// *  @param tag     提示框标示
// */
//- (void)showSuccMessage:(nullable NSString *)message tag:(NSUInteger)tag;
//
///**
// *  显示提示框带tag
// *
// *  @param title   提示框标题
// *  @param message 提示语
// *  @param array   按钮文本数组
// *  @param type    提示框样式类型
// *  @param tag     提示框标示
// */
//- (void)showWithTitle:(nullable NSString *)title
//              message:(nullable NSString *)message
//        btnTitleArray:(nullable NSArray *)array
//            alertType:(BaseAlertViewType)type
//                  tag:(NSUInteger)tag;
//
///**
// *  显示提示框带callback
// *
// *  @param title   提示框标题
// *  @param message 提示语
// *  @param array   按钮文本数组
// *  @param type    提示框样式类型
// *  @param callback 回调方法
// */
//- (void)showWithTitle:(nullable NSString *)title
//              message:(nullable NSString *)message
//        btnTitleArray:(nullable NSArray *)array
//            alertType:(BaseAlertViewType)type
//             callback:(nullable void(^)(int index))callback;
NS_ASSUME_NONNULL_END
@end

#pragma mark - ProgressHud 扩展
@interface CCBViewController (ProgressHud)

/**
 *  在当前页面中间显示loading图标
 */
- (void)showProgressHud;
/**
 *  在当前页面中间显示loading图标
 *  superView 传nil代表用self.view
 */
- (void)showProgressHudWithDismissTimes:(NSInteger)time view:(UIView*_Nullable)superView;
/**
 *  该方法供需要在特定页面展示菊花的人员使用，且弹出来了就要有发通讯的动作！未经授权随便使用后果自负-，-
 *  txcode:必输nil
 *  view:必输
 */
- (void)showProgressHudWithTxcode:(NSString*_Nullable)txcode view:(UIView*_Nullable)superView;

/**
 *  在当前页面中间显示loading图标
 *
 *  @param lockScreen 是否锁屏
 */
- (void)showProgressHud:(BOOL)lockScreen;

/**
 *  在当前页面中间显示loading图标
 *
 *  @param message    显示的文本
 *  @param lockScreen 是否锁屏
 */
- (void)showProgressHud:(nullable NSString *)message lockScreen:(BOOL)lockScreen;

/**
 *  在当前页面中间显示loading图标
 *
 *  @param message     显示的文本
 *  @param lockScreen  是否锁屏
 *  @param autoDismiss 是否自动隐藏，以秒为单位，为0时不自动隐藏
 */
- (void)showProgressHud:(nullable NSString *)message
             lockScreen:(BOOL)lockScreen
            autoDismiss:(NSTimeInterval)timeDelta;

/**
 *  延迟隐藏loading图标
 */
- (void)hideProgreddHud;
/**
 *  立刻隐藏loading图标
 */
- (void)hideProgreddHudImmediate;
/**
 *  弹出成功等待框
 *
 *  @param message    成功信息
 *  @param lookScreen 锁屏
 */
- (void)showSuccessHudWithMessage:(nullable NSString *)message lockScreen:(BOOL)lookScreen;

/**
 *  显示自定义hud，例如显示成功或者失败提示信息
 *
 *  @param customView 自定义视图
 *  @param message    文字信息
 *  @param lookScreen 是否锁屏
 */
- (void)showProgressHudWithCustomView:(nullable UIView *)customView message:(nullable NSString *)message lockScreen:(BOOL)lookScreen;

/**
 *  关闭自定义hud
 */
- (void)hideCustomProgressHud;

@end
