//
//  VideoViewController.h
//  OpenCV Tutorial
//
//  Created by BloodAxe on 6/26/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GLESImageView.h"
#import "VideoSource.h"

@interface VideoViewController : BaseSampleViewController<VideoSourceDelegate,UIActionSheetDelegate>

@property (weak, nonatomic) IBOutlet UIView *containerView;
@property (weak, nonatomic) IBOutlet UIBarButtonItem *options;

@property (nonatomic, strong) GLESImageView *imageView;
- (IBAction)captureReferenceFrame:(id)sender;
- (IBAction)clearReferenceFrame:(id)sender;

@property (weak, nonatomic) IBOutlet UIBarButtonItem *captureReferenceFrameButton;
@property (weak, nonatomic) IBOutlet UIBarButtonItem *clearReferenceFrameButton;

- (IBAction)showActionSheet:(id)sender;

@end

