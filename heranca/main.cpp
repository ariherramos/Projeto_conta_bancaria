#include <iostream>
#include <string.h>
#include <map>
#include <utility>
#include "Conta.h"

using namespace std;

int main()
{
    vector<Conta*> _listaContas;
    _listaContas.push_back(new CorrenteComum(1234,"juca",10000));
    _listaContas[0]->deposito(10000,18,18,2017);
    _listaContas[0]->Retirada(21000,18,18,2017);
    _listaContas[0]->Extrato();

    _listaContas.push_back(new CorrenteLimite(2345,"banana",10000,200));
    _listaContas[1]->deposito(10000,18,18,2017);
    _listaContas[1]->Retirada(1000,18,18,2017);
    _listaContas[1]->Extrato();

    _listaContas.push_back(new Poupanca(3456,"maca",10000,18,10));
    _listaContas[2]->deposito(10000,18,18,2017);
    _listaContas[2]->Retirada(1000,18,18,2017);
    _listaContas[2]->Extrato();

    int x,i;
    float saldo=0;
    x=_listaContas.size();

    for(i=0;i<x;i++)
    {
        saldo=_listaContas[i]->getSaldo()+saldo;
    }
    cout<<"dinheiro no banco:"<<saldo<<endl;

    return 0;
}
