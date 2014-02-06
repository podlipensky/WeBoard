//
//  ProcessorFacade.m
//  WeBoard
//
//  Created by Pavlo Pidlypenskyi on 2/2/14.
//  Copyright (c) 2014 Pavlo Pidlypenskyi. All rights reserved.
//

#import "ProcessorFacade.h"
#import "NSString+StdString.h"
#import "UIImage2OpenCV.h"

@interface ProcessorFacade()
{
    BaseVideoProcessor * _processor;
}

@end

@implementation ProcessorFacade

- (id) initWithSample:(BaseVideoProcessor*) p
{
    assert(p);
    
    if (self = [super init])
    {
        _processor = p;
    }
    
    return self;
}

- (bool) processFrame:(const cv::Mat&) inputFrame into:(cv::Mat&) outputFrame
{
    return _processor->processFrame(inputFrame, outputFrame);
}

- (UIImage*) processFrame:(UIImage*) source
{
    cv::Mat inputImage = [source toMat];
    cv::Mat outputImage;
    
    _processor->processFrame(inputImage, outputImage);
    UIImage * result = [UIImage imageWithMat:outputImage andImageOrientation:[source imageOrientation]];
    return result;
}

- (bool) getIsReferenceFrameRequired
{
    return _processor->isReferenceFrameRequired();
}

- (void) setReferenceFrame:(cv::Mat&) referenceFrame
{
    _processor->setReferenceFrame(referenceFrame);
    
}

- (void) resetReferenceFrame
{
    _processor->resetReferenceFrame();
}


@end
