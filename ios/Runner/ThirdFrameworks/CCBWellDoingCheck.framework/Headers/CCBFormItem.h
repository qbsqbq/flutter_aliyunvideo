//
//  CCBFormItem.h
//  CCBMobileBank
//
//  Created by Ansonyc on 16/4/14.
//  Copyright © 2016年 CCB. All rights reserved.
//

//#import "CCBBaseModel.h"
//#import "CCBBaseError.h"
#import <UIKit/UIKit.h>

/** *  表单tableview的每一个单元格的数据表示 */
@interface CCBFormItem : CCBBaseModel

/** *  是否显示分隔线默认为NO */
@property (nonatomic, assign) BOOL showSeparateLine;

/** *  背景色 */
@property (nonatomic, strong) UIColor *backgroundColor;

/** *  左边图片是否选中，默认否 */
@property (nonatomic, assign) BOOL leftImageIsSelected;

/** *  左边图片名称 */
@property (nonatomic, strong) NSString *leftImageName;
/** *  左边图片，与leftImageName互斥 */
@property (nonatomic, strong) UIImage *leftImage;

/** *  左边标题 */
@property (nonatomic, strong) NSString *leftText;

/** *  左边标题 */
@property (nonatomic, strong) NSAttributedString *leftAttributeText;

/** *  右边按钮的图片名 */
@property (nonatomic, strong) NSString *rightImageName;
/** *  右边图片，与rightImageName互斥 */
@property (nonatomic, strong) UIImage *rightImage;

/** *  右边按钮标题 */
@property (nonatomic, strong) NSString *rightTitle;

/** * 右边按钮标题颜色 */
@property (nonatomic, strong) UIColor *rightTitleColor;

/** * 右边按钮边框颜色,设置了就表示加上边框 */
@property (nonatomic, strong) UIColor *rightBtnBorderColor;

/** *  当前元素是否是firstResponder */
@property (nonatomic, assign) BOOL isFirstResponder;

/** *  是否允许编辑 */
@property (nonatomic, assign) BOOL canBecomeFirstResponder;

/** *  重用标识字符串 */
+ (NSString *)reuseCellIdentifier;

@property (nonatomic, strong) UIColor *middleLabelColor;

/**
 *  用作标识的tag
 */
@property (nonatomic, assign) NSInteger tag;
/** 粘贴时执行的正则。会把正则匹配的东西拿出来使用   **/
@property (nonatomic, strong) NSString *pasteRegex;
/** 粘贴时执行的正则。可以在匹配前把不想要的东西替换掉  **/
@property (nonatomic, strong) NSArray *replaceArrStr;
/** 设置右按钮图片是否跟着换肤，默认否   **/
@property (nonatomic, assign) BOOL rightBtnCanChangeColor;

@end



@interface CCBFormItem (Constraints)

/** *  左边标题的宽度与父视图宽度的比例 */
@property (nonatomic, strong) NSNumber *widthRatio;
/** *  左边标题的宽度(注：当widthRatio非nil时，width值将被忽略) */
@property (nonatomic, strong) NSNumber *width;

@end


@interface CCBFormItem (CheckValidation)

/**
 *  数据不正确时的错误提示语，此值被设置后，子类的isDataValid方法会根据具体的类型进行有效性检查
 */
@property (nonatomic, strong) NSString *errorMessageDataInvalid;
/**  数据不正确时的错误码   **/
@property (nonatomic,strong) NSString *dataInvalidErrorCode;

/**
 *  判断是否允许更新到新的value
 *
 *  @param value 新值
 *
 *  @return 允许修改为新的value则返回YES，否则返回NO
 */
- (BOOL)shouldChangeToValue:(id)value;

/**
 *  判断当前formitem的值是否正确
 *
 *  @return 值正确返回YES，否则返回NO
 */
- (BOOL)isDataValid;

/**
 *  判断当前formItem的值是否正确，如果不正确，返回错误提示语
 *
 *  @param error 接收错误提示语的返回
 *
 *  @return 值正确返回YES,否则返回NO,并在*error中存放错误信息
 */
- (BOOL)isDataValid:(CCBBaseError **)error;

@end
