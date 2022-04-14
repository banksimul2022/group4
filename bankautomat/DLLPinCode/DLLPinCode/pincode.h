#ifndef PINCODE_H
#define PINCODE_H

#include <QDialog>
#include <dllpincode.h>

namespace Ui {
class pincode;
}

class pincode : public QDialog
{
    Q_OBJECT

public:
    explicit pincode(QWidget *parent = nullptr);
    ~pincode();

private slots:
    void on_btnLogin_clicked();

private:
    Ui::pincode *ui;
};

#endif // PINCODE_H
