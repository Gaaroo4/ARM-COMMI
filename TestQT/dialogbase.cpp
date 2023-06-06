#include "dialogbase.h"
#include "ui_dialogbase.h"
#include <QFile>

DialogBase::DialogBase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogBase)
{
    ui->setupUi(this);
}

DialogBase::~DialogBase()
{
    delete ui;
}


void DialogBase::on_cancelButt_clicked()
{
    close();
}


void DialogBase::on_acceptButt_clicked()
{
    QString qs = ("/Users/gaaroo/TestQT/DishBase/" + ui->nameOfDish->text() + ".txt");
    QFile file(qs);
    if (file.exists()) {

        file.remove();
    }
    qs = ("/Users/gaaroo/TestQT/DishBase/" + ui->nameOfDish->text() + ".txt");
    file.open(QIODevice::WriteOnly);
    file.write(ui->price->text().toStdString().c_str());
    ui->nameOfDish->setText(NULL);
    ui->price->setText(NULL);
    file.close();
    qs = NULL;
}

