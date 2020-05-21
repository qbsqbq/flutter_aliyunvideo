//
//  CCBTopProgressView.h
//  CCBClientV2
//
//  Created by zhuqimin on 15/1/4.
//  Copyright (c) 2015年 llbt. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void (^UpdateProcess) (BOOL isCompleted);

@interface CCB_ProgressView_Voiceprint : CCBView

-(void) UpdateProgressBlock:(NSInteger) count blockcompletion:(UpdateProcess)UpdateProcessBlock;

-(void) fullFillProgress:(NSInteger)count;

-(void) rollBackProgress:(NSInteger)count;

-(void) rollBackAll;

@end
