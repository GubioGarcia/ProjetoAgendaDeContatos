/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QTableWidget *tableWidgetSaida;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonIncluir;
    QPushButton *pushButtonConsultar;
    QPushButton *pushButtonExcluir;
    QPushButton *pushButtonAlterar;
    QLabel *label_6;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEditCpf;
    QPushButton *pushButtonLimpar;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *lineEditNomeCompleto;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditEmail;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QLineEdit *lineEditDdi;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLineEdit *lineEditDdd;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_8;
    QLineEdit *lineEditNumero;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(792, 754);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 10, 301, 41));
        tableWidgetSaida = new QTableWidget(centralwidget);
        if (tableWidgetSaida->columnCount() < 4)
            tableWidgetSaida->setColumnCount(4);
        QFont font;
        font.setPointSize(14);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidgetSaida->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tableWidgetSaida->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        tableWidgetSaida->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        tableWidgetSaida->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidgetSaida->setObjectName("tableWidgetSaida");
        tableWidgetSaida->setGeometry(QRect(20, 340, 751, 351));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 290, 749, 41));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButtonIncluir = new QPushButton(layoutWidget);
        pushButtonIncluir->setObjectName("pushButtonIncluir");
        QFont font1;
        font1.setPointSize(12);
        pushButtonIncluir->setFont(font1);

        horizontalLayout_5->addWidget(pushButtonIncluir);

        pushButtonConsultar = new QPushButton(layoutWidget);
        pushButtonConsultar->setObjectName("pushButtonConsultar");
        pushButtonConsultar->setFont(font1);

        horizontalLayout_5->addWidget(pushButtonConsultar);

        pushButtonExcluir = new QPushButton(layoutWidget);
        pushButtonExcluir->setObjectName("pushButtonExcluir");
        pushButtonExcluir->setFont(font1);

        horizontalLayout_5->addWidget(pushButtonExcluir);

        pushButtonAlterar = new QPushButton(layoutWidget);
        pushButtonAlterar->setObjectName("pushButtonAlterar");
        pushButtonAlterar->setFont(font1);

        horizontalLayout_5->addWidget(pushButtonAlterar);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 210, 161, 51));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(20, 60, 751, 130));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        lineEditCpf = new QLineEdit(layoutWidget1);
        lineEditCpf->setObjectName("lineEditCpf");
        lineEditCpf->setFont(font);

        horizontalLayout->addWidget(lineEditCpf);

        pushButtonLimpar = new QPushButton(layoutWidget1);
        pushButtonLimpar->setObjectName("pushButtonLimpar");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(12);
        pushButtonLimpar->setFont(font2);

        horizontalLayout->addWidget(pushButtonLimpar);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName("label_4");

        horizontalLayout_2->addWidget(label_4);

        lineEditNomeCompleto = new QLineEdit(layoutWidget1);
        lineEditNomeCompleto->setObjectName("lineEditNomeCompleto");
        lineEditNomeCompleto->setFont(font);

        horizontalLayout_2->addWidget(lineEditNomeCompleto);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        lineEditEmail = new QLineEdit(layoutWidget1);
        lineEditEmail->setObjectName("lineEditEmail");
        lineEditEmail->setFont(font);

        horizontalLayout_3->addWidget(lineEditEmail);


        verticalLayout->addLayout(horizontalLayout_3);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(140, 197, 631, 78));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName("label_7");

        verticalLayout_2->addWidget(label_7);

        lineEditDdi = new QLineEdit(layoutWidget2);
        lineEditDdi->setObjectName("lineEditDdi");
        lineEditDdi->setFont(font);

        verticalLayout_2->addWidget(lineEditDdi);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName("label_5");

        verticalLayout_3->addWidget(label_5);

        lineEditDdd = new QLineEdit(layoutWidget2);
        lineEditDdd->setObjectName("lineEditDdd");
        lineEditDdd->setFont(font);

        verticalLayout_3->addWidget(lineEditDdd);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName("label_8");

        verticalLayout_4->addWidget(label_8);

        lineEditNumero = new QLineEdit(layoutWidget2);
        lineEditNumero->setObjectName("lineEditNumero");
        lineEditNumero->setFont(font);

        verticalLayout_4->addWidget(lineEditNumero);


        horizontalLayout_4->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 792, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:700;\">Agenda de Contatos</span></p></body></html>", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetSaida->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "CPF", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetSaida->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "NOME COMPLETO", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetSaida->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "EMAIL", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetSaida->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "TELEFONE", nullptr));
        pushButtonIncluir->setText(QCoreApplication::translate("MainWindow", "INCLUIR", nullptr));
        pushButtonConsultar->setText(QCoreApplication::translate("MainWindow", "CONSULTAR", nullptr));
        pushButtonExcluir->setText(QCoreApplication::translate("MainWindow", "EXCLUIR", nullptr));
        pushButtonAlterar->setText(QCoreApplication::translate("MainWindow", "ALTERAR", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">TELEFONE:</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">CPF:</span></p></body></html>", nullptr));
        pushButtonLimpar->setText(QCoreApplication::translate("MainWindow", "LIMPAR ENTRADAS", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">NOME COMPLETO:</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">EMAIL:</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">DDI</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">DDD</span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">N\303\232MERO</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
