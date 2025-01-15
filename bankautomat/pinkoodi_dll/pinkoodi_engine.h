#ifndef PINKOODI_ENGINE_H
#define PINKOODI_ENGINE_H

#include <QDialog>
#include <QDebug>
#include <QString>
#include <QTimer>

namespace Ui {
class pinkoodi_engine;
}

class pinkoodi_engine : public QDialog
{
    Q_OBJECT

public:
    explicit pinkoodi_engine(QWidget *parent = nullptr);
    ~pinkoodi_engine();
    QTimer * timer;
    void pinkoodi_vaarin();

signals:
    void pinkoodi_signal(QString);

private slots:
    void on_a1_clicked();

    void on_a2_clicked();

    void on_a3_clicked();

    void on_a4_clicked();

    void on_a5_clicked();

    void on_a6_clicked();

    void on_a7_clicked();

    void on_a8_clicked();

    void on_a9_clicked();

    void on_a0_clicked();

    void on_clear_clicked();

    void on_enter_clicked();

    void aika_loppu();

private:
    Ui::pinkoodi_engine *ui;
    QString pinkoodi;
    int yritys = 3;


};

#endif // PINKOODI_ENGINE_H
