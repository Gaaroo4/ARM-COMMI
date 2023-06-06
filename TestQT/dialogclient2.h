#ifndef DIALOGCLIENT2_H
#define DIALOGCLIENT2_H

#include <QDialog>

namespace Ui {
class DialogClient2;
}

class DialogClient2 : public QDialog
{
    Q_OBJECT

public:
    explicit DialogClient2(QWidget *parent = nullptr);
    ~DialogClient2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DialogClient2 *ui;
};

#endif // DIALOGCLIENT2_H
