#ifndef CAPTURE_MODULE_H
#define CAPTURE_MODULE_H
#include <opencv2/opencv.hpp>
bool initCamera(int deviceID);
// Declares function to initialize the camera with a device ID (e.g., 0 for default).
cv::Mat getFrame();

// Declares function to retrieve a single frame as a cv::Mat object.
void releaseCamera();

// Declares function to release camera resources.

#endif // Ends the include guard.
