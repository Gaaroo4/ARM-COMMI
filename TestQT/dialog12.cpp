#include "dialog12.h"
#include "ui_dialog12.h"

Dialog12::Dialog12(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog12)
{
    ui->setupUi(this);
}

Dialog12::~Dialog12()
{
    delete ui;
}
