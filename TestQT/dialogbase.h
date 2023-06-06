#ifndef DIALOGBASE_H
#define DIALOGBASE_H

#include <QDialog>

namespace Ui {
class DialogBase;
}

class DialogBase : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBase(QWidget *parent = nullptr);
    ~DialogBase();

private slots:
    void on_cancelButt_clicked();

    void on_acceptButt_clicked();

private:
    Ui::DialogBase *ui;
};

#endif // DIALOGBASE_H
