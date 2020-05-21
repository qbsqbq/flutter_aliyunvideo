//
//  CCBBaseFormViewModel.h
//  CCBMobileBank
//
//  Created by Ansonyc on 16/4/14.
//  Copyright © 2016年 CCB. All rights reserved.
//

//#import "CCBBaseViewModel.h"
@class CCBFormItem;

@interface CCBBaseFormViewModel : CCBBaseViewModel
{
    @protected
    NSArray *_formItems;
}

/** *  表单分组的数量 */
@property (nonatomic, readonly) NSInteger numberOfSections;

/**
 *  获取表单在某一个分组中的元素数量
 *
 *  @param section 分组的index
 *
 *  @return 分组中元素的数量
 */
- (NSInteger)numberOfRowsInSection:(NSInteger)section;

/**
 *  获取在特定位置的表单元素
 *
 *  @param row     所在行
 *  @param section 所在分组
 *
 *  @return 特定位置的表单元素
 */
- (nullable CCBFormItem *)formItemAtRow:(NSInteger)row inSection:(NSInteger)section;

/**
 *  获取指定item的下一个input类型的item
 *
 *  @param formItem 指定的item
 *
 *  @return 指定item后的input类型item
 */
- (nullable CCBFormItem *)nextInputItem:(nonnull CCBFormItem *)formItem;

/**
 *  获得tag为指定值的第一个formItem
 *
 *  @param tag 指定的标识值
 *
 *  @return tag为指定标识值的第一个formItem
 */
- (nullable CCBFormItem *)formItemWithTag:(NSInteger)tag;

/**
 *  获取item所在的indexPath
 *
 *  @param item 表单元素
 *
 *  @return 指定item所在indexPath,没找到时返回nil
 */
- (nullable NSIndexPath *)indexPathForItem:(nullable CCBFormItem *)item;

/**
 *  获取item所在的行在其分组内的index
 *
 *  @param item 表单元素
 *
 *  @return 指定item在其分组内的row index,不存在时返回NSNotFound
 */
- (NSUInteger)rowForFormItem:(nullable CCBFormItem *)item;

@end
