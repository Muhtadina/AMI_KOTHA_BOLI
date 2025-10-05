#ifndef SUBTITLE_MODULE_H
#define SUBTITLE_MODULE_H
// Include guard.
#include <opencv2/opencv.hpp>
// For cv::Mat and drawing functions.
#include <string>
// For std::string.
void showSubtitle(cv::Mat &frame, const std::string &text); 
// Declares function to draw text on a frame.
#endif
