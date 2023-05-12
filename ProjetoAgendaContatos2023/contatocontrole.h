#ifndef CONTATOCONTROLE_H
#define CONTATOCONTROLE_H

#include <IcrudContato.h>
#include <QString>
#include <QStringList>
#include <QDebug>

namespace ggs {
    class ContatoControle : public ICrudContato
    {
    private:
        void verificarRegrasDeNegocio(const Contato &objContato) const;
    public:
        ContatoControle();
        virtual void incluir(const Contato &objContato) const;

        bool validarCpf(const QString& cpf)const;
        bool validarEmail(const QString& email)const;
        bool validarFone(const QString& fone)const;
    };
}

#endif // CONTATOCONTROLE_H
