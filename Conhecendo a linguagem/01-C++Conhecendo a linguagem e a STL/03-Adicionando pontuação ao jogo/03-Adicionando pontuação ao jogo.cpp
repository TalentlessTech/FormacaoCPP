#include <iostream>
using namespace std;

int main()
{
    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhação! *" << endl;
    cout << "**************************************" << endl;

    const int NUMERO_SECRETO = 42;

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    while (nao_acertou) {
        tentativas++;
        int chute;
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual seu chute? ";
        cin >> chute;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0;
        pontos -= pontos_perdidos;

        cout << "O valor do seu chute é: " << chute << endl;
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou)
        {
            cout << "Parabéns! Você acertou o número secreto!" << endl;
            nao_acertou = false;
        }
        else if (maior)
        {
            cout << "Seu chute foi maior que o número secreto!" << endl;
        }
        else
        {
            cout << "Seu chute foi menor que o número secreto!" << endl;
        }
    }
    cout << "Fim de jogo!" << endl;
    cout << "Você acertou o número secreto em " << tentativas << " tentativas" << endl;
    cout.precision(2);
    cout << fixed;
    cout << "Sua pontuação foi de " << pontos << " pontos." << endl;
}