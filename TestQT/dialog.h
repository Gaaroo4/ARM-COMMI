#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:

    void on_cancelButton_clicked();

    void on_acceptButton_clicked();

private:
    Ui::Dialog *ui;
    int counter = 0;
    int temp = 0;
};

#endif // DIALOG_H
