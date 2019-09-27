#ifndef PROPUSHBUTTON_H
#define PROPUSHBUTTON_H

#include <QPushButton>

class ProPushButton: public QPushButton
{

    Q_OBJECT

public:

    ProPushButton(QWidget* qw) : QPushButton(qw){}

signals:

    void iChanged(QObject*);

private slots:

    void myClicked();

};

#endif // PROPUSHBUTTON_H
