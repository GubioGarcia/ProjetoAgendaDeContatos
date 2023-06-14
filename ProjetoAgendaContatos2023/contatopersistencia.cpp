#include "contatopersistencia.h"

namespace ggs {
    ContatoPersistencia::ContatoPersistencia():
        nomeDoArquivoNoDisco("arquivoContatoBD.txt") // arquivo sendo criado no diretorio corrente da build do projeto
    {}

    void ContatoPersistencia::incluir(const Contato &objContato) const{
        std::ofstream arquivoContatoBD;
        arquivoContatoBD.open(nomeDoArquivoNoDisco.toStdString().c_str(), std::ios::out|std::ios::app);
        if(!arquivoContatoBD.is_open()){
            throw QString("Persistencia - Arquivo de Contatos nao foi aberto - Metodo incluir");
        }
        if(consultar(objContato.getCpf())){
            throw QString("CPF já cadastrado em outro contato");
        }
        arquivoContatoBD << objContato.toString().toStdString() + "\n";
        arquivoContatoBD.close();
    }

    Contato *ContatoPersistencia::consultar(QString cpf) const{
        try {
            std::ifstream arquivoAgenda;
            arquivoAgenda.open(nomeDoArquivoNoDisco.toStdString().c_str());
            if(!arquivoAgenda.is_open()){
                throw QString("Arquivo de Agenda nao foi aberto");
            }
            std::string linha;
            getline(arquivoAgenda, linha);
            while(!arquivoAgenda.eof()){
                QString str = QString::fromStdString(linha);
                QStringList strList = str.split(";");
                QString cpfObj = strList[0];
                QString nome = strList[1];
                QString email = strList[2];
                int ddi = strList[3].toInt();
                int ddd = strList[4].toInt();
                int numero = strList[5].toInt();
                QString logradouro = strList[6];
                QString numeroEndereco = strList[7];
                QString cep = strList[8];

                ggs::Telefone fone(ddi, ddd, numero);
                ggs::Endereco endereco(logradouro, numeroEndereco, cep);
                ggs::Contato *objContato = new Contato(cpfObj, nome, email, fone, endereco);
                if(cpf == cpfObj){
                    arquivoAgenda.close();
                    return objContato;
                }
                delete objContato;
                getline(arquivoAgenda,linha);
            }
            arquivoAgenda.close();
            return 0;
        } catch (QString &erro) {
            throw erro;
        } catch (std::bad_alloc &erro){
            throw QString("Objeto da classe list não foi criado");
        }
    }

    void ContatoPersistencia::excluir(QString cpf) const{
        // Operações de leitura e escrita simultâneas
        std::list<ggs::Contato> *listaDeContatos = getListaDeContatos();
        // Uso de iterator para correr a lista até o contato selecionado na grid
        //std::list<ggs::Contato>::iterator iterator = listaDeContatos->begin();
        std::list<ggs::Contato>::iterator iterator = std::find_if(listaDeContatos->begin(), listaDeContatos->end(), [cpf](const ggs::Contato& contato) {return contato.getCpf() == cpf;});

        // Excluindo contado diretamente na lista
        if (iterator != listaDeContatos->end()) listaDeContatos->erase(iterator);

        std::ofstream arquivoContatoBD;
        arquivoContatoBD.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivoContatoBD.is_open()){
            throw QString("Persistencia - Arquivo de Contatos nao foi aberto - Metodo excluir");
        }
        arquivoContatoBD << ""; // Limpando arquivo

        // Reescrevendo arquivo
        iterator = listaDeContatos->begin();
        while (iterator != listaDeContatos->end()) {
            incluir(*iterator);
            ++iterator;
        }

        arquivoContatoBD.close();
    }

    void ContatoPersistencia::alterar(const Contato &objContato) const{
        // Excluir contato anterior
        QString cpf = objContato.getCpf();
        excluir(cpf);

        // Incluir contato modificado
        incluir(objContato);
    }

    std::list<Contato> *ContatoPersistencia::getListaDeContatos() const{
        try {
            std::ifstream arquivoAgenda;
            arquivoAgenda.open(nomeDoArquivoNoDisco.toStdString().c_str());
            if(!arquivoAgenda.is_open()){
                throw QString("Arquivo de Agenda nao foi aberto");
            }
            std::list<ggs::Contato> *listaDeContatos = new std::list<Contato>();
            std::string linha;
            getline(arquivoAgenda,linha);
            while(!arquivoAgenda.eof()){
                QString str = QString::fromStdString(linha);
                QStringList strList = str.split(";");
                QString cpf = strList[0];
                QString nome = strList[1];
                QString email = strList[2];
                int ddi = strList[3].toInt();
                int ddd = strList[4].toInt();
                int numero = strList[5].toInt();
                QString logradouro = strList[6];
                QString numeroEndereco = strList[7];
                QString cep = strList[8];

                ggs::Telefone fone(ddi, ddd, numero);
                ggs::Endereco endereco(logradouro, numeroEndereco, cep);
                ggs::Contato objContato(cpf, nome, email, fone, endereco);

                listaDeContatos->push_back(objContato);
                getline(arquivoAgenda,linha);
            }
            arquivoAgenda.close();
            return listaDeContatos;
        } catch (QString &erro) {
            throw erro;
        } catch (std::bad_alloc &erro){
            throw QString("Objeto da classe list não foi criado");
        }
    }
}
