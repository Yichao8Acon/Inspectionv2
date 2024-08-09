#ifndef INSPECTIONV2_OBJECTLOCATOR_HPP
#define INSPECTIONV2_OBJECTLOCATOR_HPP

#include <opencv2/opencv.hpp>

class ObjectLocator {

public:
    /**
    * Blur and filter out selected HSV color
    *
    * @param input source image loaded in cv::Mat
    * @return processed image
    *
    */
    cv::Mat computeMask(cv::Mat &srcImg);

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
