#ifndef COMIDA_HPP
#define COMIDA_HPP

#include <opencv2/opencv.hpp>

class Comida {
private:
    cv::Point posicao;

public:
    Comida();
    void novaPosicao(int largura, int altura);
    void desenhar(cv::Mat& frame);
    cv::Point getPosicao();
};

#endif
