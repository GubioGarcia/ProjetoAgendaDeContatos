#include "endereco.h"
namespace ggs{
Endereco::Endereco():
    logradouro(""),
    numero(0),
    cep(0)

{}
Endereco::Endereco(QString logradouro,int numero,int cep):
    logradouro(logradouro),numero(numero),cep(cep)
{}
QString Endereco::toString() const{
    QString saida = logradouro + ";";
    saida += QString::number(numero);
    saida += ";";
    saida += QString::number(cep);
    saida += ";";
    return saida;

}
const QString &Endereco::getLogradouro() const
{
    return logradouro;
}

void Endereco::setLogradouro(const QString &newLogradouro)
{
    logradouro = newLogradouro;
}

int Endereco::getNumero() const
{
    return numero;
}

void Endereco::setNumero(int newNumero)
{
    numero = newNumero;
}

int Endereco::getCep() const
{
    return cep;
}

void Endereco::setCep(int newCep)
{
    cep = newCep;
}
}
