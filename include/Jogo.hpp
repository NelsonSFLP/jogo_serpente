#ifndef JOGO_HPP
#define JOGO_HPP

#include "DetectorFace.hpp"
#include "Comida.hpp"
#include "Utils.hpp"
#include <opencv2/opencv.hpp>
#include <ctime>

class Jogo {
private:
    DetectorFace detector;
    Comida comida;
    int pontuacao;
    int recorde;
    std::string nomeJogador;
    std::string nomeRecordista;
    time_t inicio;


public:
    Jogo();
    void iniciar();
    void atualizar(cv::Mat& frame);
    bool tempoEsgotado();
    void mostrarPontuacao(cv::Mat& frame);
    void desenharInformacoes(cv::Mat& frame);
};

#endif
