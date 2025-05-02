#include "Comida.hpp"
#include <cstdlib>
#include <ctime>

Comida::Comida() {
    std::srand(std::time(nullptr));
    novaPosicao(640, 480);
}

void Comida::novaPosicao(int largura, int altura) {
    posicao = cv::Point(rand() % (largura - 100) + 50, rand() % (altura - 100) + 50);
    sortearForma();
}

void Comida::sortearForma() {
    tipoForma = rand() % 3; // 0 a 2
    cor = cv::Scalar(rand() % 256, rand() % 256, rand() % 256); // cor RGB aleatória
}

void Comida::desenhar(cv::Mat& frame) {
    switch (tipoForma) {
        case 0: // Círculo
            cv::circle(frame, posicao, 20, cor, -1);
            break;
        case 1: // Quadrado
            cv::rectangle(frame, posicao - cv::Point(20, 20), posicao + cv::Point(20, 20), cor, -1);
            break;
        case 2: // Triângulo
            {
                std::vector<cv::Point> pts;
                pts.push_back(posicao + cv::Point(0, -20));
                pts.push_back(posicao + cv::Point(-20, 20));
                pts.push_back(posicao + cv::Point(20, 20));
                cv::fillConvexPoly(frame, pts, cor);
            }
            break;
    }
}

cv::Point Comida::getPosicao() {
    return posicao;
}
