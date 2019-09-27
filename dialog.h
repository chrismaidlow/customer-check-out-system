#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <products.h>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;

public slots:
    void updateCart(products* entry);

private slots:
    void on_pushButton_clicked();
    void on_checkout_clicked();
    void reject();

signals:
    void xbutton();
    void checkoutSend();

};

#endif // DIALOG_H
