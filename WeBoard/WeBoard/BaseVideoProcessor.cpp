//
//  BaseVideoProcessor.cpp
//  WeBoard
//
//  Created by Pavlo Pidlypenskyi on 2/2/14.
//  Copyright (c) 2014 Pavlo Pidlypenskyi. All rights reserved.
//

#include "BaseVideoProcessor.h"
#include <iostream>

//! Returns true if this sample requires setting a reference image for latter use
bool BaseVideoProcessor::isReferenceFrameRequired() const
{
    return false;
}

//! Sets the reference frame for latter processing
void BaseVideoProcessor::setReferenceFrame(const cv::Mat& reference)
{
    // Does nothing. Override this method if you need to
}

// Resets the reference frame
void BaseVideoProcessor::resetReferenceFrame() const
{
    // Does nothing. Override this method if you need to
}

void BaseVideoProcessor::getGray(const cv::Mat& input, cv::Mat& gray)
{
    const int numChannes = input.channels();
    
    if (numChannes == 4)
    {
        cv::cvtColor(input, gray, CV_BGRA2GRAY);
    }
    else if (numChannes == 3)
    {
        cv::cvtColor(input, gray, CV_BGR2GRAY);
    }
    else if (numChannes == 1)
    {
        gray = input;
    }
}
