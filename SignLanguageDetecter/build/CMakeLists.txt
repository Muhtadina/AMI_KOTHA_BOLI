cmake_minimum_required(VERSION 3.10) // Specifies the minimum
CMake version required to build the project.
project(SignLanguageDetector)
// Names the project for build
artifacts.
set(CMAKE_CXX_STANDARD 17)
// Sets the C++ standard to
C++17 for modern features like std::string_view.
find_package(OpenCV REQUIRED)
// Locates the OpenCV package
and sets variables like OpenCV_INCLUDE_DIRS.
include_directories(include ${OpenCV_INCLUDE_DIRS}) // Adds include
paths for headers and OpenCV.
file(GLOB SOURCES "src/*.cpp")
SOURCES variable.
// Collects all .cpp files in src/ into
add_executable(sign_detector ${SOURCES}) // Creates an executable
named sign_detector from the sources.
target_link_libraries(sign_detector ${OpenCV_LIBS}) // Links OpenCV
libraries to the executable for runtime dependencies.
