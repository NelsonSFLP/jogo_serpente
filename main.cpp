#include "Jogo.hpp"
#include "Utils.hpp"
#include <iostream>

using namespace std;

void exibirMenu() {
    cout << "\n=== MENU PRINCIPAL ===" << endl;
    cout << "1. Iniciar Jogo" << endl;
    cout << "2. Ver Recorde Atual" << endl;
    cout << "3. Sair" << endl;
    cout << "Escolha uma opcao: ";
}

int main() {
    int opcao;

    while (true) {
        exibirMenu();
        cin >> opcao;
        cin.ignore(); // limpar o \n do buffer após cin

        if (opcao == 1) {
            Jogo jogo;
            jogo.iniciar();
        } else if (opcao == 2) {
            int r = carregarRecorde();
            string nome = carregarNomeRecorde();
            cout << "Recorde: " << r << " ponto(s), por " << nome << endl;
        } else if (opcao == 3) {
            cout << "Saindo do jogo..." << endl;
            break;
        } else {
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    }

    return 0;
}
