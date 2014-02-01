//
//  GLESImageView.h
//  WeBoard
//
//  Created by Pavlo Pidlypenskyi on 1/31/14.
//  Copyright (c) 2014 Pavlo Pidlypenskyi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GLESImageView : UIView

- (void)drawFrame:(const cv::Mat&) bgraFrame;

@end
