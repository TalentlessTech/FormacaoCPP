#include <iostream>
using namespace std;

int main()
{
    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinha��o! *" << endl;
    cout << "**************************************" << endl;

    const int NUMERO_SECRETO = 42;

    bool nao_acertou = true;
    int tentativas = 0;

    while (nao_acertou) {
        tentativas++;
        int chute;
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual seu chute? ";
        cin >> chute;

        cout << "O valor do seu chute �: " << chute << endl;
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou)
        {
            cout << "Parab�ns! Voc� acertou o n�mero secreto!" << endl;
            nao_acertou = false;
        }
        else if (maior)
        {
            cout << "Seu chute foi maior que o n�mero secreto!" << endl;
        }
        else
        {
            cout << "Seu chute foi menor que o n�mero secreto!" << endl;
        }
    }
    cout << "Fim de jogo!" << endl;
    cout << "Voc� acertou o n�mero secreto em " << tentativas << " tentativas" << endl;
}