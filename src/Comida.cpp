#include "Comida.hpp"
#include <cstdlib>
#include <ctime>

Comida::Comida() {
    std::srand(std::time(nullptr));
    novaPosicao(640, 480);
}

void Comida::novaPosicao(int largura, int altura) {
    posicao = cv::Point(rand() % (largura - 100) + 50, rand() % (altura - 100) + 50);
}

void Comida::desenhar(cv::Mat& frame) {
    cv::circle(frame, posicao, 20, {0, 255, 0}, -1);
}

cv::Point Comida::getPosicao() {
    return posicao;
}
