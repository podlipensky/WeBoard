//
//  BaseVideoProcessor.h
//  WeBoard
//
//  Created by Pavlo Pidlypenskyi on 2/2/14.
//  Copyright (c) 2014 Pavlo Pidlypenskyi. All rights reserved.
//

#ifndef __WeBoard__BaseVideoProcessor__
#define __WeBoard__BaseVideoProcessor__

#include <iostream>

#endif /* defined(__WeBoard__BaseVideoProcessor__) */

class BaseVideoProcessor {

public:
    //! Returns true if this sample requires setting a reference image for latter use
    virtual bool isReferenceFrameRequired() const;
    
    //! Sets the reference frame for latter processing
    virtual void setReferenceFrame(const cv::Mat& reference);
    
    // Resets the reference frame
    virtual void resetReferenceFrame() const;
    
    //! Processes a frame and returns output image
    virtual bool processFrame(const cv::Mat& inputFrame, cv::Mat& outputFrame) = 0;

protected:
    static void getGray(const cv::Mat& input, cv::Mat& gray);
};