#include "sign_recognition.h"
declarations.
#include <iostream>
(debugging/errors).
#include <fstream>
#include <cstdlib>
script.
#include <vector>

static std::vector<std::string> labels;

static std::string python_script_path;
MediaPipe processing.
// Path to the Python script for

static const std::string temp_frame_path = "/tmp/sign_detector_frame.jpg";
static const std::string temp_result_path = "/tmp/sign_detector_result.txt";
bool loadSignModel(const std::string &scriptPath, const std::string
&labelsPath) { // Loads the recognition setup.
python_script_path = scriptPath;

std::ifstream file(labelsPath);

if (!file.is_open()) {

std::cerr << "Failed to open labels file: " << labelsPath <<
std::endl; // Prints error if failed.
return false;
// Returns false on failure.
}
std::string label;

while (std::getline(file, label)) { // Reads each line (label) from file.
if (!label.empty()) {

labels.push_back(label);

}
}
file.close();

if (labels.empty()) {

std::cerr << "No labels loaded from: " << labelsPath << std::endl;

return false;

}
std::cout << "Loaded " << labels.size() << " sign labels" << std::endl;

return true;

}
std::string recognizeSign(const cv::Mat &frame) { 
// Processes a frame to detect a sign.

cv::imwrite(temp_frame_path, frame);

std::string cmd = "python3 " + python_script_path + " " + temp_frame_path + " > " + temp_result_path; // Constructs command to run Python script.
int result = system(cmd.c_str());
// Executes the Python script,
redirecting output to result file.
if (result != 0) {
// Checks if script execution failed.
std::cerr << "Python script failed with code: " << result << std::endl; 
// Prints error.
return "";
// Returns empty string on failure.
}
// Read the result from the temporary output file.
std::ifstream result_file(temp_result_path); // Opens result file.
if (!result_file.is_open()) {
// Checks if file opened.
std::cerr << "Failed to read result file: " << temp_result_path <<
std::endl; // Prints error.
return "";
// Returns empty string on failure.
}
std::string sign;
// Variable to store detected sign.
std::getline(result_file, sign);
// Reads the first line (detected sign
label).
result_file.close();
// Closes result file.
// Validate the sign against loaded labels.
for (const auto &label : labels) {
// Iterates through loaded labels.
if (sign == label) {
// Checks if detected sign matches a
valid label.
return sign;
// Returns the valid sign.
}
}
return "";
// Returns empty string if no valid sign
detected.
}
void unloadSignModel() {
// Cleans up resources.
labels.clear();
// Clears the labels vector.
// Remove temporary files.
std::remove(temp_frame_path.c_str()); // Deletes temporary frame
file.
std::remove(temp_result_path.c_str()); // Deletes temporary result file.
}
