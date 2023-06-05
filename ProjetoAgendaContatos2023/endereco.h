#ifndef ENDERECO_H
#define ENDERECO_H
#include <QString>
namespace ggs{
class Endereco
{
private:
    QString logradouro;
    int numero;
    int cep;
public:
    Endereco();
    Endereco(QString logradouro,int numero,int cep);

    QString toString()const;

    const QString &getLogradouro() const;
    void setLogradouro(const QString &newLogradouro);
    int getNumero() const;
    void setNumero(int newNumero);
    int getCep() const;
    void setCep(int newCep);
};
}
#endif // ENDERECO_H
