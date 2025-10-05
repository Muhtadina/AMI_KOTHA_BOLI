include "capture_module.h"
#include <iostream>

static cv::VideoCapture cap;

// Includes the header for function
// Includes iostream for error output.
// Declares a static VideoCapture
bool initCamera(int deviceID) {
// Defines function to open the camera.
cap.open(deviceID);

// Attempts to open the device (e.g.,/dev/video0).
if (!cap.isOpened()) {
// Checks if opening failed.
std::cerr << "Cannot open camera" << std::endl; // Prints error message.
return false;
// Returns false on failure.
}
return true;
// Returns true on success.

}
cv::Mat getFrame() {
cv::Mat frame;
frame.
cap >> frame;
into frame.
return frame;
}
void releaseCamera() {
cap.release();
}
