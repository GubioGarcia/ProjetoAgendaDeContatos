#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , agendaDeContatosControle(0)
{
    ui->setupUi(this);
    agendaDeContatosControle = new ggs::ContatoControle();
}

MainWindow::~MainWindow()
{
    delete agendaDeContatosControle;
    delete ui;
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
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}

void MainWindow::on_pushButtonConsultar_clicked()
{
    try {

    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}

void MainWindow::on_pushButtonExcluir_clicked()
{
    try {

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
