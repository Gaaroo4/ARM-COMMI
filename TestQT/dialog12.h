#ifndef DIALOG12_H
#define DIALOG12_H

#include <QDialog>

namespace Ui {
class Dialog12;
}

class Dialog12 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog12(QWidget *parent = nullptr);
    ~Dialog12();

private:
    Ui::Dialog12 *ui;
};

#endif // DIALOG12_H
