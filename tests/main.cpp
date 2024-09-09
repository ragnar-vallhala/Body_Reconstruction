#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Open the default camera (0 is usually the ID for the default camera)
    cv::VideoCapture cap(0);

    // Check if the camera opened successfully
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open the camera." << std::endl;
        return -1;
    }

    // Create a window to display the video
    cv::namedWindow("Camera Feed", cv::WINDOW_AUTOSIZE);

    while (true) {
        cv::Mat frame;

        // Capture each frame
        cap >> frame;

        // Check if the frame is empty
        if (frame.empty()) {
            std::cerr << "Error: Blank frame grabbed." << std::endl;
            break;
        }

        // Display the frame
        cv::imshow("Camera Feed", frame);

        // Press 'q' to exit the loop
        if (cv::waitKey(30) >= 0) {
            break;
        }
    }

    // Release the camera
    cap.release();

    // Close the OpenCV window
    cv::destroyAllWindows();

    return 0;
}

