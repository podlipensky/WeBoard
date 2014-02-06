//
//  HumanDetectionProcessor.cpp
//  WeBoard
//
//  Created by Pavlo Pidlypenskyi on 2/2/14.
//  Copyright (c) 2014 Pavlo Pidlypenskyi. All rights reserved.
//
#include <iostream>
#include "HumanDetectionProcessor.h"

using namespace cv;

int counter = 0;
int frameStep = 100;
int result = 0;
Mat previousFrame = Mat(2,2, CV_8UC3, Scalar(0,0,255));
Mat cachedFrame = Mat(2,2, CV_8UC3, Scalar(0,0,255));

//! Processes a frame and returns output image
bool HumanDetectionProcessor::processFrame(const Mat& inputFrame, Mat& outputFrame)
{
//    getGray(inputFrame, gray);
    Mat greyMat = inputFrame;
//    cvtColor(inputFrame, greyMat, CV_BGR2GRAY);

    
//    HOGDescriptor hog;
//    hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
//    vector<Rect> found;
//    
//    hog.detectMultiScale(CVMat3Channels(inputFrame), found, 0.2, Size(8,8), Size(16,16), 1.05, 2);
//    inputFrame.copyTo(outputFrame);
//    
//    for( int i = 0; i < (int)found.size(); i++ )
//    {
//        
//        Rect r = found[i];
//        
//        rectangle(outputFrame, r, cvScalar(255,0,0));
//        
//    }
    
//    drawContours(outputFrame, c, -1, CV_RGB(0,200,0));
//    outputFrame = cachedFrame;
    if (counter == 0) {
//        previousFrame.release();
        previousFrame = greyMat.clone();
        std::cout << "Got first one for " << result << "\n";
        counter++;
    } else if (counter == frameStep) {
        outputFrame = Mat(greyMat.size(), IPL_DEPTH_8U, 4);
        subtract(greyMat, previousFrame, outputFrame);
//        cachedFrame.release();
//        cachedFrame = outputFrame.clone();
        counter = 0;
        std::cout << "Do comparison and output results for " << result++ << "\n";
    } else {
        counter++;
    }
//    outputFrame = inputFrame;
    
    return true;
}

Mat HumanDetectionProcessor::CVMat3Channels (const Mat& rgbaMat)
{
    Mat rgbMat(300, 300, CV_8UC3); // 8 bits per component, 3 channels
    
    cvtColor(rgbaMat, rgbMat, CV_RGBA2RGB, 3);
    
    return rgbMat;
}