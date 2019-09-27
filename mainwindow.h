#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dialog.h>
#include <vector>
#include <QTableWidgetItem>
#include <products.h>
#include <bundle.h>
#include <tech.h>
#include <techbuilder.h>
#include <builder.h>
#include <bundlebuilder.h>

using std::vector;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:

    vector<products*> techEntries;
    vector<products*> bundleEntries;
    vector<Dialog*> carts = {};
    Dialog* dial = nullptr;

private:
    Ui::MainWindow *ui;

private slots:

    void actByYourChange(QObject*);
    void xbuttonShow();
    void disable();
    void on_add_clicked();
    void on_show_clicked();

signals:
    void added(products* entry);
};

#endif // MAINWINDOW_H
