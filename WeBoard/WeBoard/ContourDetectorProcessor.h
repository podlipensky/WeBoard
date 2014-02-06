//
//  ContourDetectorProcessor.h
//  WeBoard
//
//  Created by Pavlo Pidlypenskyi on 2/2/14.
//  Copyright (c) 2014 Pavlo Pidlypenskyi. All rights reserved.
//

#ifndef __WeBoard__ContourDetectorProcessor__
#define __WeBoard__ContourDetectorProcessor__

#include <iostream>
#include "BaseVideoProcessor.h"

class ContourDetectorProcessor : public BaseVideoProcessor {
    //! Processes a frame and returns output image
    virtual bool processFrame(const cv::Mat& inputFrame, cv::Mat& outputFrame);
    
private:
    cv::Mat gray, edges;
};
#endif /* defined(__WeBoard__ContourDetectorProcessor__) */
