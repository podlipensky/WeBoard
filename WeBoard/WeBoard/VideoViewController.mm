//
//  VideoViewController.m
//  WeBoard
//
//  Created by Pavlo Pidlypenskyi on 2/1/14.
//  Copyright (c) 2014 Pavlo Pidlypenskyi. All rights reserved.
//

#import "VideoViewController.h"
#import "UIImage2OpenCV.h"
#import "ProcessorFacade.h"
#import "ContourDetectorProcessor.h"
#import "HumanDetectionProcessor.h"

#define kTransitionDuration	0.75

@interface VideoViewController () {
    VideoSource * videoSource;
    cv::Mat outputFrame;
}
@end

@implementation VideoViewController
@synthesize imageView;
@synthesize containerView;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.currentProcessor = [[ProcessorFacade alloc] initWithSample:  new HumanDetectionProcessor()];
	// Init the default view (video view layer)
    self.imageView = [[GLESImageView alloc] initWithFrame:self.containerView.bounds];
    [self.imageView setAutoresizingMask:(UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight)];
    [self.containerView addSubview:self.imageView];
    
    // Init video source:
    videoSource = [[VideoSource alloc] init];
    
    videoSource.delegate = self;
}

- (void) viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    [videoSource startRunning];
}

- (void) viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    [videoSource stopRunning];
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewDidUnload
{
    [super viewDidUnload];
}

#pragma mark - VideoSourceDelegate

- (void) frameCaptured:(cv::Mat) frame
{
    bool isMainQueue = dispatch_get_current_queue() == dispatch_get_main_queue();
    
    if (isMainQueue)
    {
        [self.currentProcessor processFrame:frame into:outputFrame];
        [imageView drawFrame:outputFrame];
    }
    else
    {
        dispatch_sync( dispatch_get_main_queue(),
                      ^{
                          [self.currentProcessor processFrame:frame into:outputFrame];
                          [imageView drawFrame:outputFrame];
                      }
                      );
    }
}

#pragma mark - Capture reference frame

- (IBAction) captureReferenceFrame:(id) sender
{
    bool isMainQueue = dispatch_get_current_queue() == dispatch_get_main_queue();
    
    if (isMainQueue)
    {
        [self.currentProcessor setReferenceFrame:outputFrame];
    }
    else
    {
        dispatch_sync( dispatch_get_main_queue(),
                      ^{
                          [self.currentProcessor setReferenceFrame:outputFrame];
                      }
                      );
    }
}

#pragma mark - Clear reference frame

- (IBAction) clearReferenceFrame:(id) sender
{
    bool isMainQueue = dispatch_get_current_queue() == dispatch_get_main_queue();
    
    if (isMainQueue)
    {
        [self.currentProcessor resetReferenceFrame];
    }
    else
    {
        dispatch_sync( dispatch_get_main_queue(),
                      ^{
                          [self.currentProcessor resetReferenceFrame];
                      }
                      );
    }
}

- (BOOL)shouldAutorotateToInterfaceOrientation: (UIInterfaceOrientation)interfaceOrientation {
    return (interfaceOrientation == UIInterfaceOrientationLandscapeRight);
}

@end
