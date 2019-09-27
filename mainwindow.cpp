#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QList>
#include <QStringList>
#include <cmath>

#include <propushbutton.h>
#include <vector>


using std::vector;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->tableWidget_2->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->tableWidget->setColumnWidth(3,230);
    ui->tableWidget_2->setColumnWidth(0,150);
    ui->tableWidget_2->setColumnWidth(1,150);
    ui->tableWidget_2->setColumnWidth(2,230);

    //CONNECT STATEMENTS
    //Load database connection (MEDIATOR)
    connect(ui->load, SIGNAL(clicked()), ui->load, SLOT(myClicked()));
    connect(ui->load, SIGNAL(iChanged(QObject*)), this, SLOT(actByYourChange(QObject*)));

    ui->add->setEnabled(false);
    ui->show->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actByYourChange(QObject* senderObj)
{
    if(senderObj == ui->load)
    {
       //BUILD DATABASE
        QStringList entryList;
        QFile inventory("Technology.csv");
        if (inventory.open(QIODevice::ReadOnly))
        {
            TechBuilder builder;
            QTextStream in(&inventory);
            while (!in.atEnd())
            {
                QString line = in.readLine();

                //BUILDER PATTERN
                tech* entry = builder.returnObject(line);
                techEntries.push_back(entry);

                //POPULATE TECH TABLE
                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                QTableWidgetItem *Name = new QTableWidgetItem;
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,Name);
                Name -> setText(entry->getName());

                //ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                QTableWidgetItem *Type = new QTableWidgetItem;
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,Type);
                Type -> setText(entry->getType());

                //ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                QTableWidgetItem *Price = new QTableWidgetItem;
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,Price);
                Price -> setText(QString::number(entry->getPrice()));

                //ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                QTableWidgetItem *Feature = new QTableWidgetItem;
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,Feature);
                Feature -> setText(entry->getAttribute());

                //CLEAR ENTRYLIST
                entryList.clear();

            }
            inventory.close();
            entryList.clear();
        }
        QFile bundles("Bundles.csv");
        if (bundles.open(QIODevice::ReadOnly))
        {

            BundleBuilder builder;
            QTextStream in(&bundles);
            while (!in.atEnd())
            {

                QString line = in.readLine();
                builder.linkProducts(techEntries);
                bundle* entry = builder.returnObject(line);
                bundleEntries.push_back(entry);

                //POPULATE TABLE
                ui->tableWidget_2->insertRow(ui->tableWidget_2->rowCount());
                QTableWidgetItem *Name = new QTableWidgetItem;
                ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount()-1,0,Name);
                Name -> setText(entry->getName());

                //ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                QTableWidgetItem *Price = new QTableWidgetItem;
                ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount()-1,1,Price);
                Price -> setText(QString::number(entry->getPrice()));

                //ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                QTableWidgetItem *Savings = new QTableWidgetItem;
                ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount()-1,2,Savings);
                Savings -> setText(entry->getSavings());

                //CLEAR ENTRYLIST
                entryList.clear();

            }
            bundles.close();
        }
    }
    ui->load->setEnabled(false);
    ui->add->setEnabled(true);
    ui->show->setEnabled(true);
}

void MainWindow::on_add_clicked()
{

    if(carts.size() == 0)
    {
        dial = new Dialog(this);
        carts.push_back(dial);
        //OBSERVER
        connect(this, &MainWindow::added, dial, &Dialog::updateCart);
    }

    QList<QTableWidgetItem*> item = ui->tableWidget->selectedItems();
    //TECH ENTRIES
    int size = item.size();
    int cnt = 0;

    //name of items selected found every fourth column
    while(cnt < size)
    {
        //Get name of item in row
        QTableWidgetItem* name = item[cnt];
        //convert item name to QString
        QString str_name = name->data(Qt::DisplayRole).toString();
        //iterate through database to find object to add
        for(unsigned i = 0; i<techEntries.size(); ++i)
        {
            //if name matches
            if (techEntries[i]->getName() == str_name)
            {
                //ADD TO SHOPPING CART
                emit added(techEntries[i]);
                //break;
            }
        }
        //update column count
        cnt += 4;
    }

    QList<QTableWidgetItem*> item2 = ui->tableWidget_2->selectedItems();
    //BUNDLE ENTRIES

    int size2 = item2.size();
    int cnt2 = 0;
    while(cnt2 < size2)
    {
        QTableWidgetItem* name = item2[cnt2];
        QString str_name = name->data(Qt::DisplayRole).toString();
        for(unsigned i = 0; i<bundleEntries.size(); ++i)
        {
            if (bundleEntries[i]->getName() == str_name)
            {
                //ADD TO SHOPPING CART
                emit added(bundleEntries[i]);
                //break;
            }
        }
        cnt2 += 3;
    }
    ui->show->setEnabled(true);

    //OBSERVER
    connect(dial, SIGNAL(xbutton()), this, SLOT(xbuttonShow()));
    connect(dial, SIGNAL(checkoutSend()), this, SLOT(disable()));
}

void MainWindow::on_show_clicked()
{
    if(dial == nullptr)
    {
        return;
    }
    if (ui->show->text()== "Hide Cart")
    {
        dial->hide();
        ui->show->setText("Show Cart");
        return;
    }
    dial->show();
    ui->show->setText("Hide Cart");
}

void MainWindow::xbuttonShow()
{
    ui->show->setText("Show Cart");
}

void MainWindow::disable()
{
    ui->show->setEnabled(false);
    ui->add->setEnabled(false);
}
