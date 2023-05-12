#ifndef ICRUDCONTATO_H
#define ICRUDCONTATO_H

#include <QString>
#include <list>
#include <contato.h>

namespace ggs {
    class ICrudContato{
    public:
        virtual void incluir(const Contato &objContato) const = 0;
        //virtual std::list<Contato> *getListaDeContatos() const = 0;
        //virtual const Contato &consultar(int cpf) const = 0;
        //virtual void alterar(const Contato &objContato) const = 0;
        //virtual void excluir(int cpf) const = 0;
   };
}

#endif // ICRUDCONTATO_H
