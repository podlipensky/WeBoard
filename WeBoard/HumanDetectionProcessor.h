//
//  HumanDetectionProcessor.h
//  WeBoard
//
//  Created by Pavlo Pidlypenskyi on 2/2/14.
//  Copyright (c) 2014 Pavlo Pidlypenskyi. All rights reserved.
//

#ifndef __WeBoard__HumanDetectionProcessor__
#define __WeBoard__HumanDetectionProcessor__

#include <iostream>
#include "BaseVideoProcessor.h"

class HumanDetectionProcessor : public BaseVideoProcessor {
    //! Processes a frame and returns output image
    virtual bool processFrame(const cv::Mat& inputFrame, cv::Mat& outputFrame);
    virtual cv::Mat CVMat3Channels(const cv::Mat& rgbaMat);
private:
    cv::Mat gray, edges;
};
#endif /* defined(__WeBoard__HumanDetectionProcessor__) */
