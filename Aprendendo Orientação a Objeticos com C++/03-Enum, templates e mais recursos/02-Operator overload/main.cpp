#include <iostream>
#include <string>
#include "DiaDaSemana.hpp"
#include "Gerente.hpp"
#include "Conta.hpp"
#include "ContaCorrente.hpp"
#include "ContaPoupanca.hpp"
#include "Titular.hpp"
#include "Cpf.hpp"
#include "Funcionario.hpp"

using namespace std;

void ExibeSaldo(const Conta& conta)
{
    cout << "O saldo da conta é: " << conta.recuperaSaldo() << endl;
}

void RealizaSaque(Conta& conta)
{
    conta.sacar(200);
}

void FazLogin(Autenticavel& alguem, string senha)
{
    if (alguem.autentica(senha)) {
        cout << "Login realizado com sucesso" << endl;
    } else {
        cout << "Senha inválida" << endl;
    }
}

ostream& operator<<(ostream& cout, const Conta& conta)
{
    Pessoa titular = conta.titular;
    cout << "O saldo da conta é (operador): " << conta.recuperaSaldo() << endl;
    cout << "O titular da conta é: " << titular.recuperaNome() << endl;

    return cout;
}

int main()
{
    Titular titular(Cpf("123.456.789-10"), "Vinicius", "umasenha");

    ContaPoupanca umaConta("123456", titular);
    umaConta.depositar(500);
    RealizaSaque(umaConta);

    ExibeSaldo(umaConta);

    Titular outro(Cpf("098.765.432-10"), "Vinicius Dias", "outrasenha");
    ContaCorrente umaOutraConta("654321", titular);
    (Conta&) umaOutraConta += 300;

    ContaCorrente outraContaCorrente("546312", titular);
    
    //umaOutraConta.transferePara(umaConta, 250);
    outraContaCorrente += umaOutraConta;

    cout << umaOutraConta;
    ExibeSaldo(outraContaCorrente);

    cout << "Número de contas: " << Conta::recuperaNumeroDeContas() << endl;

    Gerente umGerente(
        Cpf("000.000.000-00"),
        "Nome do Gerente",
        1500,
        DiaDaSemana::Terca,
        "123456"
    );

    return 0;
}