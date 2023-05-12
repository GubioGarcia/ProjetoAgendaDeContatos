#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <telefone.h>
#include <contato.h>
#include <contatocontrole.h>
#include <IcrudContato.h>
#include <QMessageBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonIncluir_clicked();

    void on_pushButtonConsultar_clicked();

    void on_pushButtonExcluir_clicked();

    void on_pushButtonAlterar_clicked();

private:
    Ui::MainWindow *ui;
    ggs::ICrudContato *agendaDeContatosControle;
};
#endif // MAINWINDOW_H
