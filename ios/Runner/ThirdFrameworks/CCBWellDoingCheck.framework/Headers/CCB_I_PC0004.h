//
//  CCB_I_PC0004.h
//  CCBMobileBank
//
//  Created by pengchenyi on 16/7/4.
//  Copyright © 2016年 CCB. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface CCB_I_PC0004 : CCBBaseRequestModel
@property(nonatomic,strong)NSString *UserId; //用户登陆标识号，如：手机号等
@property(nonatomic,strong)NSString *ChanelType; //00 手机银行客户端;01 善融买家版客户端;02 移动服务平台;03 Pad版客户端;04 企业手机银行;05 驾驶舱;06 运营宝;07 龙卡信息汇;
@property(nonatomic,strong)NSString *DeviceId; //设备号
@property(nonatomic,strong)NSString *Type; //1：查询；2：更新；3：删除
@property(nonatomic,strong)NSString *ParamName; //如果多个参数名用“|”分隔；如：Param1|Param2|Param3
@property(nonatomic,strong)NSString *ParamValue; //如果多个参数值用“|”分隔；如：Value1|Value2|Value3。如果有Type类型为2，参数值不能为空，参数值的个数和参数名称的个数一一对应
@property(nonatomic,strong)NSString *GroupId; //"3.44版的声纹开关：001；3.45版之后的声纹开关：002；
@property(nonatomic,strong)NSString *Time; //如：201506101710
@end
