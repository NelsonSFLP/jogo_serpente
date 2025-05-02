#ifndef DETECTORFACE_HPP
#define DETECTORFACE_HPP

#include <opencv2/opencv.hpp>
#include <vector>

class DetectorFace {
private:
    cv::CascadeClassifier classificador;

public:
    DetectorFace();
    std::vector<cv::Rect> detectar(cv::Mat& frame);
};

#endif
