//
//  CCB_O_PC0002.h
//  CCBMobileBank
//
//  Created by pengchenyi on 16/7/4.
//  Copyright © 2016年 CCB. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "CCBBaseModel.h"

@interface CCB_O_PC0002_ParamObj : NSObject

@property(nonatomic,strong)NSString *ParamName; //
@property(nonatomic,strong)NSString *ParamValue; //
@property(nonatomic,strong)NSString *GroupId; //"3.44版的声纹开关：001；3.45版之后的声纹开关：002；"
@property(nonatomic,strong)NSString *Time; //

@end

@interface CCB_O_PC0002 : CCBBaseModel
@property(nonatomic,strong)NSString *Result; //0:失败；1：成功
@property(nonatomic,strong)NSArray <CCB_O_PC0002_ParamObj *> *ParamArray; //Result为true时，ParamArray不能为空
@property(nonatomic,strong)NSString *errMsg; //Result为false时，errMsg不能为空
@property(nonatomic,strong)NSString *Type; //0：插入；1：更新;2:插入与更新
@end
