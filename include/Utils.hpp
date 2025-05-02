#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

int carregarRecorde();
std::string carregarNomeRecorde();
void salvarRecordeCompleto(const std::string& nome, int pontuacao);
void tocarSom(const std::string& caminho);

#endif
