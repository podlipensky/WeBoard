//
//  VideoViewController.h
//  WeBoard
//
//  Created by Pavlo Pidlypenskyi on 2/1/14.
//  Copyright (c) 2014 Pavlo Pidlypenskyi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GLESImageView.h"
#import "VideoSource.h"
#import "BaseVideoProcessor.h"
#import "ProcessorFacade.h"

@interface VideoViewController : UIViewController <VideoSourceDelegate>
@property (strong, nonatomic) IBOutlet UIView *containerView;

@property (nonatomic, strong) GLESImageView *imageView;
@property ProcessorFacade *currentProcessor;
@end
