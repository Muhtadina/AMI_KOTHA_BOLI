#include "subtitle_module.h"
// Includes header.
void showSubtitle(cv::Mat &frame, const std::string &text) { 
// Defines function to add subtitle.
cv::putText(frame, text, cv::Point(10, 30),
cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2); 
/* Draws text at position (10,30) with green color and thickness 2.*/
}
