#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , agendaDeContatosControle(0)
{
    ui->setupUi(this);
    agendaDeContatosControle = new ggs::ContatoControle();
    // Desabilitar a edição direta de células, mas permitir a seleção de linhas
    ui->tableWidgetSaida->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidgetSaida->setSelectionBehavior(QAbstractItemView::SelectRows);
    //Configurando a Grid
    ui->tableWidgetSaida->setRowCount(0);
    ui->tableWidgetSaida->setColumnWidth(0, 100);
    ui->tableWidgetSaida->setColumnWidth(1, 210);
    ui->tableWidgetSaida->setColumnWidth(2, 210);
    ui->tableWidgetSaida->setColumnWidth(3, 210);
    try {
        mostrarContatosNaGrid(agendaDeContatosControle->getListaDeContatos());
    } catch (...) {
    }
    connect(ui->tableWidgetSaida, &QTableWidget::itemSelectionChanged, this, &MainWindow::selecaoDeItensNaTableWidget);

}

MainWindow::~MainWindow()
{
    delete agendaDeContatosControle;
    delete ui;
}

void MainWindow::selecaoDeItensNaTableWidget(){
    QList<QTableWidgetItem *> selectedItems = ui->tableWidgetSaida->selectedItems(); // armanezando dados da linha  coletada
    if (!selectedItems.isEmpty()) {
        int rowSelected = ui->tableWidgetSaida->row(selectedItems.first()); // row recebe nº da linha selecionada na grid
        std::list<ggs::Contato> *listaDeContatos = agendaDeContatosControle->getListaDeContatos(); // leitura da agenda
        // uso de iterator para correr a lista ao contato selecionado na grid
        std::list<ggs::Contato>::iterator iterator = listaDeContatos->begin();
        std::advance(iterator, rowSelected);
        // retorno das informações do contato selecionado as lineEdit
        if (iterator != listaDeContatos->end()) {
            ggs::Contato objContato = *iterator;
            ui->lineEditCpf->setText(objContato.getCpf());
            ui->lineEditCpf->setEnabled(false);
            ui->lineEditNomeCompleto->setText(objContato.getNomeCompleto());
            ui->lineEditNomeCompleto->setEnabled(false);
            ui->lineEditEmail->setText(objContato.getEmail());
            ui->lineEditEmail->setEnabled(false);
            ui->lineEditDdi->setText(QString::number(objContato.getFone().getDdi()));
            ui->lineEditDdi->setEnabled(false);
            ui->lineEditDdd->setText(QString::number(objContato.getFone().getDdd()));
            ui->lineEditDdd->setEnabled(false);
            ui->lineEditNumero->setText(QString::number(objContato.getFone().getNumero()));
            ui->lineEditNumero->setEnabled(false);
        }
    }
}

void MainWindow::mostrarContatosNaGrid(std::list<ggs::Contato> *listaDeContatos){
    try {
        // Limpar a grid
        if(listaDeContatos->empty()) return;
        ui->tableWidgetSaida->setRowCount(0);
        while(!listaDeContatos->empty()){
            ggs::Contato objeto = listaDeContatos->front();
            listaDeContatos->pop_front();
            //Montando a grid
            QTableWidgetItem *itemCPF = new QTableWidgetItem(objeto.getCpf());
            QTableWidgetItem *itemNome = new QTableWidgetItem(objeto.getNomeCompleto());
            QTableWidgetItem *itemEmail = new QTableWidgetItem(objeto.getEmail());
            QTableWidgetItem *itemTelefone = new QTableWidgetItem(objeto.getFone().obterTelefone());
            int linha = ui->tableWidgetSaida->rowCount();
            ui->tableWidgetSaida->insertRow(linha);
            ui->tableWidgetSaida->setItem(linha,0,itemCPF);
            ui->tableWidgetSaida->setItem(linha,1,itemNome);
            ui->tableWidgetSaida->setItem(linha,2,itemEmail);
            ui->tableWidgetSaida->setItem(linha,3,itemTelefone);
        }
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    } catch(...){
        QMessageBox::information(this,"ERRO","ERRO NA LISTAGEM");
    }
}

void MainWindow::limparInterface()const{
    ui->lineEditCpf->clear();
    ui->lineEditNomeCompleto->clear();
    ui->lineEditEmail->clear();
    ui->lineEditDdi->clear();
    ui->lineEditDdd->clear();
    ui->lineEditNumero->clear();
}

void MainWindow::on_pushButtonIncluir_clicked()
{
    try {
        QString cpf = ui->lineEditCpf->text();
        QString nomeCompleto = ui->lineEditNomeCompleto->text();
        QString email = ui->lineEditEmail->text();
        int ddi = ui->lineEditDdi->text().toInt();
        int ddd = ui->lineEditDdd->text().toInt();
        int numeroFone = ui->lineEditNumero->text().toInt();

        ggs::Telefone fone(ddi, ddd, numeroFone);
        ggs::Contato objContato(cpf, nomeCompleto, email, fone);

        agendaDeContatosControle->incluir(objContato);

        limparInterface();

        mostrarContatosNaGrid(agendaDeContatosControle->getListaDeContatos());
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}

void MainWindow::on_pushButtonConsultar_clicked()
{
    try {
        QString cpf = ui->lineEditCpf->text();
        if(cpf == "") throw QString("Informe o CPF.");
        ggs::Contato *contatoConsulta = 0;
        contatoConsulta = agendaDeContatosControle->consultar(cpf);
        if(contatoConsulta){
            ui->lineEditCpf->setText(contatoConsulta->getCpf());
            ui->lineEditNomeCompleto->setText(contatoConsulta->getNomeCompleto());
            ui->lineEditEmail->setText(contatoConsulta->getEmail());
            ui->lineEditDdi->setText(QString::number(contatoConsulta->getFone().getDdi()));
            ui->lineEditDdd->setText(QString::number(contatoConsulta->getFone().getDdd()));
            ui->lineEditNumero->setText(QString::number(contatoConsulta->getFone().getNumero()));
            delete contatoConsulta;
        } else{
            QMessageBox::information(this, "ERRO DO SISTEMA", "CPF NÃO EXISTE");
        }
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}

void MainWindow::on_pushButtonExcluir_clicked()
{
    try {
        QString cpf = ui->lineEditCpf->text();
        if(cpf == "") throw QString("Selecione o contato que deseja excluir.");
        ggs::Contato *contatoExcluir = 0;
        contatoExcluir = agendaDeContatosControle->consultar(cpf);
        QString auxContato = contatoExcluir->getCpf() + '\n' + contatoExcluir->getNomeCompleto() + '\n' + contatoExcluir->getEmail() + '\n' + contatoExcluir->getFone().obterTelefone();
        QMessageBox::StandardButton confirmacaoDeExclusao = QMessageBox::warning(this, "EXCLUIR CONTATO", "Deseja EXCLUIR o contato permanentemente?\n\n" + auxContato, QMessageBox::Yes | QMessageBox::No);
        if (confirmacaoDeExclusao == QMessageBox::Yes) {
            agendaDeContatosControle->excluir(cpf);
        } else return;

        limparInterface();
        mostrarContatosNaGrid(agendaDeContatosControle->getListaDeContatos());

        QMessageBox::information(this, "EXCLUIR CONTATO", "Contato encluído!");

    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}

void MainWindow::on_pushButtonAlterar_clicked()
{
    try {

    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}

void MainWindow::on_pushButtonLimpar_clicked()
{
    ui->lineEditCpf->clear();
    ui->lineEditNomeCompleto->clear();
    ui->lineEditEmail->clear();
    ui->lineEditDdi->clear();
    ui->lineEditDdd->clear();
    ui->lineEditNumero->clear();

    ui->lineEditCpf->setEnabled(true);
    ui->lineEditNomeCompleto->setEnabled(true);
    ui->lineEditEmail->setEnabled(true);
    ui->lineEditDdi->setEnabled(true);
    ui->lineEditDdd->setEnabled(true);
    ui->lineEditNumero->setEnabled(true);
}
