#include "Utils.hpp"
#include <fstream>
#include <ctime>
#include <sstream>
#include <iostream>
#include <cstdlib>

int carregarRecorde() {
    std::ifstream arq("record.txt");
    std::string linha;
    int pontuacao = 0;

    while (std::getline(arq, linha)) {
        if (linha.find("Pontuacao:") != std::string::npos) {
            pontuacao = std::stoi(linha.substr(linha.find(":") + 1));
        }
    }
    return pontuacao;
}

std::string carregarNomeRecorde() {
    std::ifstream arq("record.txt");
    std::string linha;

    while (std::getline(arq, linha)) {
        if (linha.find("Nome:") != std::string::npos) {
            return linha.substr(linha.find(":") + 2);
        }
    }
    return "Desconhecido";
}

void salvarRecordeCompleto(const std::string& nome, int pontuacao) {
    std::ofstream arq("record.txt");

    // Pegar data/hora atual
    std::time_t agora = std::time(nullptr);
    std::tm* ptm = std::localtime(&agora);
    char buffer[32];
    std::strftime(buffer, 32, "%Y-%m-%d %H:%M:%S", ptm);

    arq << "Nome: " << nome << "\n";
    arq << "Pontuacao: " << pontuacao << "\n";
    arq << "Data: " << buffer << "\n";
}

void tocarSom(const std::string& caminho) {
    std::string comando = "aplay " + caminho + " > /dev/null 2>&1 &";
    system(comando.c_str());
}
