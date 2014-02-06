//
//  ContourDetectorProcessor.cpp
//  WeBoard
//
//  Created by Pavlo Pidlypenskyi on 2/2/14.
//  Copyright (c) 2014 Pavlo Pidlypenskyi. All rights reserved.
//

#include <iostream>
#include "ContourDetectorProcessor.h"

//! Processes a frame and returns output image
bool ContourDetectorProcessor::processFrame(const cv::Mat& inputFrame, cv::Mat& outputFrame)
{
    getGray(inputFrame, gray);
    
    cv::Mat edges;
    cv::Canny(gray, edges, 50, 150);
    
    std::vector< std::vector<cv::Point> > c;
    
	cv::findContours(edges, c, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    
    inputFrame.copyTo(outputFrame);
    cv::drawContours(outputFrame, c, -1, CV_RGB(0,200,0));
    
    return true;
}