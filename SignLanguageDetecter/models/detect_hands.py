# Purpose: Python script to process a frame using MediaPipe Hands for hand detection and classify it as a sign.
# Significance: Provides the AI component for gesture recognition, outputting a sign label for C++ integration.

import cv2                                # Imports OpenCV for image processing.
import mediapipe as mp                    # Imports MediaPipe for hand detection.
import sys                                # For command-line arguments.
import numpy as np                        # For numerical operations.

# Initialize MediaPipe Hands model.
mp_hands = mp.solutions.hands             # Loads MediaPipe Hands module.
hands = mp_hands.Hands(max_num_hands=1, min_detection_confidence=0.7)  # Configures model for single hand detection with 70% confidence.

# Simple rule-based classifier for demo signs (extend with trained model for more signs).
def classify_sign(landmarks):             # Defines function to classify hand landmarks as signs.
    # Example heuristic: Based on thumb position relative to other fingers.
    if landmarks:                         # Checks if landmarks are detected.
        thumb_tip = landmarks[4].y        # Gets y-coordinate of thumb tip (landmark 4).
        index_tip = landmarks[8].y        # Gets y-coordinate of index finger tip (landmark 8).
        if thumb_tip < index_tip - 0.1:   # If thumb is significantly above index finger, assume "Hello".
            return "Hello"
        elif thumb_tip > index_tip + 0.1: # If thumb is below, assume "No".
            return "No"
        else:                             # Neutral position, assume "Yes".
            return "Yes"
    return ""                             # Returns empty string if no landmarks detected.

def main():                               # Main function for script execution.
    if len(sys.argv) != 2:                # Checks if exactly one argument (image path) is provided.
        print("Usage: python3 detect_hands.py <image_path>", file=sys.stderr)  # Prints usage info.
        sys.exit(1)                       # Exits with error code.

    # Load and process the image.
    image = cv2.imread(sys.argv[1])       # Reads the input image from path.
    if image is None:                     # Checks if image loaded successfully.
        print("Failed to load image", file=sys.stderr)  # Prints error.
        sys.exit(1)                       # Exits on failure.

    image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)  # Converts image to RGB for MediaPipe.
    results = hands.process(image_rgb)    # Processes image with MediaPipe Hands.

    # Extract landmarks and classify.
    sign = ""                             # Initializes sign variable.
    if results.multi_hand_landmarks:      # Checks if hands are detected.
        landmarks = results.multi_hand_landmarks[0].landmark  # Gets landmarks of first hand.
        sign = classify_sign(landmarks)   # Classifies the landmarks as a sign.

    print(sign)                           # Outputs the detected sign to stdout.

    hands.close()                         # Releases MediaPipe Hands resources.

if __name__ == "__main__":               # Ensures main runs only if script is executed directly.
    main()                               # Calls main function.
