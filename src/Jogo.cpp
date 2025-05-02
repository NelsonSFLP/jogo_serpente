#include "Jogo.hpp"

Jogo::Jogo() {
    pontuacao = 0;
    recorde = carregarRecorde();
    nomeRecordista = carregarNomeRecorde();
    std::cout << "Digite seu nome: ";
    std::getline(std::cin, nomeJogador);
    inicio = time(nullptr);
    comida.novaPosicao(640, 480);
}


void Jogo::iniciar() {
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Erro ao acessar a câmera." << std::endl;
        return;
    }

    cv::Mat frame;
    while (true) {
    cap >> frame;
    if (frame.empty()) break;

    cv::flip(frame, frame, 1);
    atualizar(frame);
    mostrarPontuacao(frame);
    comida.desenhar(frame);
    desenharInformacoes(frame);  // <<--- novo

    cv::imshow("Jogo da Serpente", frame);
    if (cv::waitKey(30) == 27 || tempoEsgotado()) break;
    }


    std::cout << "\nPontuação final: " << pontuacao << std::endl;
    if (pontuacao > recorde) {
        std::cout << "Novo recorde! Parabéns, " << nomeJogador << "!" << std::endl;
        salvarRecordeCompleto(nomeJogador, pontuacao);
    } else {
        std::cout << "Recorde atual: " << recorde << " por " << nomeRecordista << std::endl;
    }


    cap.release();
    cv::destroyAllWindows();
}

void Jogo::atualizar(cv::Mat& frame) {
    auto faces = detector.detectar(frame);
    cv::Point alvo = comida.getPosicao();
    // Desenhar a comida
    for (auto& face : faces) {
        cv::rectangle(frame, face, cv::Scalar(255, 0, 255), 2);
        cv::Point centro(face.x + face.width / 2, face.y + face.height / 2);
        // Desenhar o centro da face
        if (cv::norm(centro - alvo) < 40) {
            pontuacao++;
            tocarSom("assets/comida.wav");
            comida.novaPosicao(frame.cols, frame.rows);
            break;
        }
    }
}

//Verifica se o tempo esgotou
// Retorna true se o tempo esgotou, false caso contrário
bool Jogo::tempoEsgotado() {
    return difftime(time(nullptr), inicio) >= 60;
}

void Jogo::mostrarPontuacao(cv::Mat& frame) {
    //Pontuação canto superior esquerdo
    std::string texto = "Pontos: " + std::to_string(pontuacao);
    cv::putText(frame, texto, {10, 30}, cv::FONT_HERSHEY_SIMPLEX, 0.5, {255, 255, 255}, 2);
}

void Jogo::desenharInformacoes(cv::Mat& frame) {
    // Título centralizado
    std::string titulo = "  = JOGO DA SERPENTE =";
    int larguraTexto = cv::getTextSize(titulo, cv::FONT_HERSHEY_SIMPLEX, 1.0, 2, nullptr).width;
    int x = (frame.cols - larguraTexto) / 2;
    cv::putText(frame, titulo, {x, 40}, cv::FONT_HERSHEY_SIMPLEX, 1.0, {255, 255, 255}, 2);

    // Recorde atual no rodapé
    std::string recordeInfo = "Recorde: " + std::to_string(recorde) + " (" + nomeRecordista + ")";
    cv::putText(frame, recordeInfo, {10, frame.rows - 20}, cv::FONT_HERSHEY_SIMPLEX, 0.7, {255, 255, 255}, 2);
    // Mostrar tempo restante
    int tempoRestante = 60 - static_cast<int>(difftime(time(nullptr), inicio));
    std::string tempoTexto = "Tempo: " + std::to_string(tempoRestante) + "s";
    cv::putText(frame, tempoTexto, {10, frame.rows - 50}, cv::FONT_HERSHEY_SIMPLEX, 0.7, {0, 255, 0}, 2);

}
