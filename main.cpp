#include <iostream>
#include "src/ObjectLocator.hpp"

int main() {
//HT-SUA1600C-T1V-C-Snapshot-20240801-142825-481-11353606694157
//HT-SUA1600C-T1V-C-Snapshot-20240802-112720-489-12108955249708
    ObjectLocator objectLocator;
    cv::Mat src;
    src = cv::imread(
            "C:\\Users\\yichao.qin\\Documents\\Huateng\\Prof\\rotate6\\HT-SUA1600C-T1V-C-Snapshot-20240802-112720-489-12108955249708.BMP");
    cv::resize(src, src, {800, 600});
    cv::Mat mask = objectLocator.preprocess(src);

    std::vector<cv::RotatedRect> rects = objectLocator.findRectangleVects(mask);
    for (auto rect: rects) {
        objectLocator.getRotatedCroppedShape(src, rect);
    }
    return 0;
}
