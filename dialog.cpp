#include "dialog.h"
#include "ui_dialog.h"
#include <string>
#include <QMessageBox>
#include <protable.h>
#include "tablevisitor.h"
#include "visitor.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->tableWidget_3->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_3->setColumnWidth(0,150);
    ui->tableWidget_3->setColumnWidth(1,390);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::updateCart(products* entry)
{
    ui->tableWidget_3->insertRow(ui->tableWidget_3->rowCount());
    QTableWidgetItem *Name = new QTableWidgetItem;
    ui->tableWidget_3->setItem(ui->tableWidget_3->rowCount()-1,0,Name);
    Name -> setText(entry->getName());
    QTableWidgetItem *Price = new QTableWidgetItem;
    ui->tableWidget_3->setItem(ui->tableWidget_3->rowCount()-1,1,Price);
    double value = entry->getPrice();
    Price -> setText(QString::number(value));
}

void Dialog::on_pushButton_clicked()
{

    int row = ui->tableWidget_3->currentRow();
    ui->tableWidget_3->removeRow(row);
}

void Dialog::on_checkout_clicked()
{
    //Calculate total using VISITOR and adjust label
    TableVisitor tbvs;
    ui->tableWidget_3->accept(&tbvs);
    ui->label->setText("TOTAL: $" + QString::number(tbvs.getValue()));
    ui->label->setStyleSheet("QLabel { color : red; }");
    ui->pushButton->setEnabled(false);
    ui->checkout->setEnabled(false);

    emit checkoutSend();
}

void Dialog::reject()
{
    emit xbutton();
    QDialog::reject();
}
