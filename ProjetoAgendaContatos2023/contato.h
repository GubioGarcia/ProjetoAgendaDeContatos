#ifndef CONTATO_H
#define CONTATO_H
#include <telefone.h>
#include <QString>

namespace ggs {
    class Contato
    {
    private:
        QString cpf;
        QString nomeCompleto;
        QString email;
        Telefone fone;
    public:
        Contato();
        Contato(QString &cpf, QString &nomeCompleto, QString &email, Telefone &fone);//passagem de parâmetros por referência

        QString toString()const;
        QString obterTelefone()const;

        QString getNomeCompleto() const;
        void setNomeCompleto(const QString &newNomeCompleto);
        QString getEmail() const;
        void setEmail(const QString &newEmail);
        Telefone getFone() const;
        void setFone(const Telefone &newFone);
        QString getCpf() const;
        void setCpf(const QString &newCpf);
    };
}

#endif // CONTATO_H
