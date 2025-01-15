#ifndef CREDITDEBIT_H
#define CREDITDEBIT_H

#include <QDialog>
#include <QTimer>
#include "restapi.h"

namespace Ui {
class creditdebit;
}

class creditdebit : public QDialog
{
    Q_OBJECT

public:
    explicit creditdebit(QWidget *parent = nullptr);
    ~creditdebit();
    QTimer * timer;

private slots:
    void on_DEBIT_clicked();
    void on_CREDIT_clicked();
    void aika_loppu();

private:
    Ui::creditdebit *ui;

signals:
    void tiliValittuSignal(QString);

};

#endif // CREDITDEBIT_H
