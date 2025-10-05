#include <iostream>
#include <opencv2/opencv.hpp>
#include "capture_module.h"
#include "sign_recognition.h"
#include "subtitle_module.h"
#include "tts_module.h"

int main() {
// Main program entry point.
if (!initCamera(0)) {
// Initializes webcam (device ID 0, typically /dev/video0).
std::cerr << "Failed to initialize camera!" << std::endl; 
// Prints error if camera fails to open.
return -1;
// Exits program with error code on failure.
}
if (!loadSignModel("models/detect_hands.py", "models/labels.txt")) {
// Loads the sign recognition model (Python script and labels file).
std::cerr << "Failed to load sign recognition model!" << std::endl;
// Prints error if model loading fails.
releaseCamera();
// Releases camera resources before exiting.
return -1;
// Exits with error code.
}
cv::namedWindow("Sign Detector", cv::WINDOW_AUTOSIZE); 
// Creates a GUI window named "Sign Detector" with auto-sized properties.
while (true) {
// Enters main loop for continuous real- time processing.
cv::Mat frame = getFrame();
// Captures a single frame from the webcam.
if (frame.empty()) {
// Checks if frame is empty (e.g., camera disconnected).
std::cerr << "Empty frame received!" << std::endl; // Prints error.
break;
}
// Breaks loop on failure.
std::string sign = recognizeSign(frame); 
// Processes frame with MediaPipe to detect and classify a sign (e.g., "Hello", "Yes", "No").
if (!sign.empty()) {
// Checks if a valid sign was detected.
showSubtitle(frame, sign); // Overlays the detected sign as a subtitle on the frame.
speakText(sign);
// Converts the sign text to speech using eSpeak.
}
cv::imshow("Sign Detector", frame); // Displays the frame (with subtitle) in the GUI window.
if (cv::waitKey(30) == 27) { // Waits 30ms for a key press; checks for ESC (ASCII 27).
break;
// Exits loop if ESC is pressed.
}
}
unloadSignModel();
(e.g., temporary files).
releaseCamera();
cv::destroyAllWindows();
return 0;
}
