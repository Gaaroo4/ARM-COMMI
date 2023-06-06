#include "dialogdelete.h"
#include "ui_dialogdelete.h"
#include <QFile>

DialogDelete::DialogDelete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDelete)
{
    ui->setupUi(this);
}

DialogDelete::~DialogDelete()
{
    delete ui;
}


void DialogDelete::on_pushButton_2_clicked()
{
    close();
}


void DialogDelete::on_pushButton_clicked()
{
    QString qs = ("/Users/gaaroo/TestQT/DishBase/" + ui->lineEdit->text() + ".txt");
    QFile file(qs);
    file.remove();
    ui->lineEdit->setText(NULL);
}

