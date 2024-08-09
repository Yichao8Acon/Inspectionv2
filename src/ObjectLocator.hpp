#ifndef INSPECTIONV2_OBJECTLOCATOR_HPP
#define INSPECTIONV2_OBJECTLOCATOR_HPP

#include <opencv2/opencv.hpp>

class ObjectLocator {

public:
    /**
    * Performs image preprocess.\n
    * This function takes an Mat and performs blurring, HSV color filtering, and morphology process.
    * @param input source image loaded in cv::Mat
    * @return processed image
    */
    cv::Mat preprocess(cv::Mat &srcImg);

    /**
    * Detects all rectangles in the image.\n
    * This function takes a source Mat and detects rectangles with rotations by finding contours and filtering out boundingBox by size.
    * @param input source image loaded in cv::Mat
    * @return vector of detected rotated rectangles.
    * @note The returned rotated rectangles are boundingBoxes containing the detected rectangles.\n
    *       It is not guaranteed that these bounding boxes will tightly fit because of the rotations.
    */
    std::vector<cv::RotatedRect> findRectangleVects(cv::Mat &srcImg);

    void getRotatedCroppedShape(cv::Mat &src, cv::RotatedRect &rect);

private:
    cv::Size blurKernelSize{3, 3};
    int openingKernelSize {3};
    cv::Scalar lowerHSV{0, 0, 40};
    cv::Scalar upperHSV{180, 255, 255};
    const float minRectAreaThresh = 10000;

};


#endif //INSPECTIONV2_OBJECTLOCATOR_HPP
