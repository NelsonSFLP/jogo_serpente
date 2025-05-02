#ifndef COMIDA_HPP
#define COMIDA_HPP

#include <opencv2/opencv.hpp>

class Comida {
private:
    cv::Point posicao;
    int tipoForma;         // 0: círculo, 1: quadrado, 2: triângulo
    cv::Scalar cor;        // cor aleatória
    void sortearForma();   // sorteia forma e cor aleatórias

public:
    Comida();
    void novaPosicao(int largura, int altura);
    void desenhar(cv::Mat& frame);
    cv::Point getPosicao();
};

#endif
