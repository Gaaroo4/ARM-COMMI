#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialog.h"
#include "dialogbase.h"
#include "dialogclient.h"
#include "dialogdelete.h"
#include "dialogclient2.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    ui->label->setHidden(1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::on_pushButton_clicked()
//{
//    ui->label->setHidden(0);
//    ui->label->setText("Button is clicked");
//    userInput = ui->UserInputTextBox->text();
//    ui->label_2->setText(userInput);
//}


void MainWindow::on_pushButton_clicked()
{
    Dialog dialog = Dialog(this);
    dialog.exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    DialogBase dialog = DialogBase(this);
    dialog.exec();
}


void MainWindow::on_pushButton_4_clicked()
{
    DialogDelete dialog = DialogDelete(this);
    dialog.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    DialogClient2 dialog = DialogClient2(this);
    dialog.exec();
}

