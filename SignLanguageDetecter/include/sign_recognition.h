#ifndef SIGN_RECOGNITION_H               // Include guard to prevent multiple inclusions.
#define SIGN_RECOGNITION_H

#include <opencv2/opencv.hpp>           // For cv::Mat to process video frames.
#include <string>                       // For std::string to handle sign labels.

bool loadSignModel(const std::string &scriptPath, const std::string &labelsPath);  // Initializes the recognition system (Python script and labels file).
std::string recognizeSign(const cv::Mat &frame);  // Processes a frame and returns the detected sign label.
void unloadSignModel();                 // Cleans up resources (if any).

#endif 
