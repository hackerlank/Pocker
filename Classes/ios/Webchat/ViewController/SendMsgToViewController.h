//
//  SendMsgToWeChatViewController.h
//  ApiClient
//
//  Created by Tencent on 12-2-27.
//  Copyright (c) 2012年 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SendMsgToViewController : UIViewController
@property (nonatomic, copy) NSString *WeixinRES;
- (void)sendAuthRequest;
-(void)printlog:(NSString*) str;
-(void)setCode:(NSString*) str;
@end
