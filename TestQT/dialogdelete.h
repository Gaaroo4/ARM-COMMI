#ifndef DIALOGDELETE_H
#define DIALOGDELETE_H

#include <QDialog>

namespace Ui {
class DialogDelete;
}

class DialogDelete : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDelete(QWidget *parent = nullptr);
    ~DialogDelete();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::DialogDelete *ui;
};

#endif // DIALOGDELETE_H
