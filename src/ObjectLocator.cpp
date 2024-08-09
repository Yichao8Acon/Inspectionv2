#include "ObjectLocator.hpp"

cv::Mat ObjectLocator::preprocess(cv::Mat &srcImg) {
    cv::Mat blurredImg,
            imageMask,
            hsvImage;
    cv::blur(srcImg, blurredImg, this->blurKernelSize);
    cv::cvtColor(blurredImg, hsvImage, cv::COLOR_BGR2HSV);
    cv::inRange(hsvImage, lowerHSV, upperHSV, hsvImage);
    cv::erode(hsvImage, imageMask, cv::Mat(), cv::Point(-1, -1), this->openingKernelSize);
    cv::dilate(imageMask, imageMask, cv::Mat(), cv::Point(-1, -1), this->openingKernelSize);
    return imageMask;
}

std::vector<cv::RotatedRect> ObjectLocator::findRectangleVects(cv::Mat &srcImg) {
    std::vector<cv::RotatedRect> detectedRectVect;
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(srcImg, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

    std::vector<cv::Point> approx;
    cv::RotatedRect rotatedRect;
    for (const auto &contour: contours) {
        rotatedRect = cv::minAreaRect(contour);
        if (rotatedRect.size.area() < minRectAreaThresh) continue;
        detectedRectVect.push_back(rotatedRect);
    }
    return detectedRectVect;
}

void ObjectLocator::getRotatedCroppedShape(cv::Mat &src, cv::RotatedRect &rect) {
    cv::Point2f box[4];
    rect.points(box);

    cv::Point2f center = rect.center;
    cv::Mat M = cv::getRotationMatrix2D(center, rect.angle, 1.0);
    cv::Mat rotated;
    cv::Mat cropped;
    int w = src.cols;
    int h = src.rows;
    cv::warpAffine(src, rotated, M, cv::Size(static_cast<int>(w * 1.5), static_cast<int>(h * 1.5)));
    std::vector<cv::Point2f> transformed_pts;
    std::vector<cv::Point2f> box_vec(box, box + 4);
    cv::transform(box_vec, transformed_pts, M);
    std::sort(transformed_pts.begin(), transformed_pts.end(), [](const cv::Point2f &a, const cv::Point2f &b) {
        if (a.x == b.x)
            return a.y < b.y;
        return a.x < b.x;
    });
    // Create the bounding box
    cv::Rect crop_rect(transformed_pts[0], transformed_pts[3]);
    cropped = rotated(crop_rect);
    std::cout << cropped.size << std::endl;
    cv::imshow("", cropped);
    cv::imwrite("a.jpg", cropped);
    cv::waitKey(-1);
}

