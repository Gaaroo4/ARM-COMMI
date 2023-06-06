#include "dialog.h"
#include "ui_dialog.h"
#include <fstream>
#include <QString>
#include <QFile>
#include <QPushButton>
#include <iostream>

using namespace std;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    counter=1;

    ui->acceptButton->setFocus();

}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_cancelButton_clicked()
{close();

}


void Dialog::on_acceptButton_clicked()
{

    std::cout << counter << std::endl;

    static QString qs = ("/Users/gaaroo/TestQT/Clients/" + ui->lineEdit_5->text() + ".txt");


    switch(counter) {
    case 1: {
        ui->label->setText("Введите день недели:");
        QFile file(qs);
        if (file.open(QIODevice::WriteOnly | QIODevice::Append))
        counter++;
        break;
    }
    case 2: {
        ui->label->setText("Введите время посещения:");
        QFile file(qs);
        if (file.open(QIODevice::WriteOnly | QIODevice::Append))
        file.write(ui->lineEdit_5->text().toStdString().c_str());
        file.write("/0");
        counter++;
        break;
    }
    case 3: {
        ui->label->setText("Введите блюдо:");
        QFile file(qs);
        if (file.open(QIODevice::WriteOnly | QIODevice::Append))
            file.write(ui->lineEdit_5->text().toStdString().c_str());
        file.write("/0");
        counter++;
        break;
    }
    case 4: {
        QFile file(qs);
        if (file.open(QIODevice::WriteOnly | QIODevice::Append))
            file.write(ui->lineEdit_5->text().toStdString().c_str());
        file.write("/0");
        close();
        counter++;
        break;
    }
    }
    ui->lineEdit_5->setText(NULL);
}



