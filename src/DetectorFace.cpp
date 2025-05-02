#include "DetectorFace.hpp"

DetectorFace::DetectorFace() {
    classificador.load("assets/haarcascade_frontalface_default.xml");
}

std::vector<cv::Rect> DetectorFace::detectar(cv::Mat& frame) {
    std::vector<cv::Rect> faces;
    classificador.detectMultiScale(frame, faces, 1.1, 3);
    return faces;
}
