//
//  ProcessorFacade.h
//  WeBoard
//
//  Created by Pavlo Pidlypenskyi on 2/2/14.
//  Copyright (c) 2014 Pavlo Pidlypenskyi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BaseVideoProcessor.h"

@interface ProcessorFacade : NSObject

- (id) initWithSample:(BaseVideoProcessor*) p;

- (bool) processFrame:(const cv::Mat&) inputFrame into:(cv::Mat&) outputFrame;

- (UIImage*) processFrame:(UIImage*) source;

@property (getter = getIsReferenceFrameRequired, readonly) bool isReferenceFrameRequired;

- (void) setReferenceFrame:(cv::Mat&) referenceFrame;
- (void) resetReferenceFrame;


@end
