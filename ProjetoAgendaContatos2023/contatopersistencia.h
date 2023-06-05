#ifndef CONTATOPERSISTENCIA_H
#define CONTATOPERSISTENCIA_H
#include <IcrudContato.h>
#include <contato.h>
#include <QStringList>
#include <fstream> //Biblioteca para tratamento de arquivos

namespace ggs {
    class ContatoPersistencia : public ICrudContato
    {
    private:
        QString nomeDoArquivoNoDisco;
    public:
        ContatoPersistencia();
        void incluir(const Contato &objContato) const;
        std::list<Contato> *getListaDeContatos() const;
        Contato *consultar(QString cpf) const;
        void excluir(QString cpf) const;
    };
}

#endif // CONTATOPERSISTENCIA_H
