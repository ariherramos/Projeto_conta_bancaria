#ifndef CONTA_H
#define CONTA_H
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Conta
{
    protected:
        int _numeroConta;
        string _nome;
        float _saldo;
        vector<string>_extrato;

    public:
        Conta()
        {
        }

        float getSaldo()
        {
            return _saldo;
        }

        virtual void Extrato()
        {

        }

        virtual void Retirada(float x, int dia, int mes, int ano)
        {

        }

        void deposito(float x, int dia, int mes, int ano)
        {
            _saldo=_saldo+x;

            string dado;
            stringstream _x (stringstream::in | stringstream::out);
            stringstream _dia (stringstream::in | stringstream::out);
            stringstream _mes (stringstream::in | stringstream::out);
            stringstream _ano (stringstream::in | stringstream::out);
            _x << x;
            _dia << dia;
            _mes << mes;
            _ano << ano;

            dado.append("\nDeposito->");
            dado.append("Saldo:");
            dado.append(_x.str());
            dado.append("  Data:");
            dado.append(_dia.str());
            dado.append("//");
            dado.append(_mes.str());
            dado.append("//");
            dado.append(_ano.str());

            _extrato.push_back(dado);
        }
        void retirada(float x, int dia, int mes, int ano)
        {
            _saldo=_saldo-x;

            string dado;
            stringstream _x (stringstream::in | stringstream::out);
            stringstream _dia (stringstream::in | stringstream::out);
            stringstream _mes (stringstream::in | stringstream::out);
            stringstream _ano (stringstream::in | stringstream::out);
            _x << x;
            _dia << dia;
            _mes << mes;
            _ano << ano;

            dado.append("\nRetirada->");
            dado.append("Saldo:");
            dado.append(_x.str());
            dado.append("  Data:");
            dado.append(_dia.str());
            dado.append("//");
            dado.append(_mes.str());
            dado.append("//");
            dado.append(_ano.str());

            _extrato.push_back(dado);
        }

        void extrato()
        {
            for (vector<string>::iterator it = _extrato.begin() ; it != _extrato.end(); ++it)
                cout << ' ' << *it;
            cout << '\n';
        }

        virtual ~Conta();
};

class CorrenteComum:public Conta
{
    public:
        CorrenteComum(int numeroConta, string nome, float saldo)
        {
            _numeroConta=numeroConta;
            _nome=nome;
            _saldo=saldo;
        }
        virtual void Extrato()
        {
            cout<<"Numero da conta:"<<_numeroConta<<"\nNome:"<<_nome<<endl;
            extrato();
            cout<<"\nSaldo:"<<_saldo<<endl;
        }
        virtual void Retirada(float x, int dia, int mes, int ano)
        {
            if(x<=_saldo)
            {
                retirada( x, dia, mes, ano);
            }
            else
            {
                cout<<"Saldo insuficiente\n\n\n"<<endl;
            }

        }
};

class CorrenteLimite:public Conta
{
    private:
        float _limite;
    public:
        CorrenteLimite(int numeroConta, string nome, float saldo, float limite)
        {
            _numeroConta=numeroConta;
            _nome=nome;
            _saldo=saldo;
            _limite=limite;
        }

        virtual void Retirada(float x, int dia, int mes, int ano)
        {
            if(x<=(_saldo+_limite))
            {
                retirada( x, dia, mes, ano);
            }
            else
            {
                cout<<"Saldo insuficiente\n\n\n"<<endl;
            }

        }
        virtual void Extrato()
        {
            cout<<"Numero da conta:"<<_numeroConta<<"\nNome:"<<_nome<<endl;
            extrato();
            cout<<"\nLimite:"<<_limite<<endl;
            cout<<"\nSaldo:"<<_saldo<<endl;
        }
};

class Poupanca:public Conta
{
    private:
        int _dia;
        int _mes;
    public:
        Poupanca(int numeroConta, string nome, float saldo, int dia, int mes)
        {
            _numeroConta=numeroConta;
            _nome=nome;
            _saldo=saldo;
            _dia=dia;
            _mes=mes;
        }
        virtual void Extrato()
        {
            cout<<"Numero da conta:"<<_numeroConta<<"\nNome:"<<_nome<<endl;
            extrato();
            cout<<"\nData de aniversario:"<<_dia<<"//"<<_mes<<endl;
            cout<<"\nSaldo:"<<_saldo<<endl;
        }

        virtual void Retirada(float x, int dia, int mes, int ano)
        {
            if(x<=_saldo)
            {
                retirada( x, dia, mes, ano);
            }
            else
            {
                cout<<"Saldo insuficiente\n\n\n"<<endl;
            }

        }

};
#endif // CONTA_H
