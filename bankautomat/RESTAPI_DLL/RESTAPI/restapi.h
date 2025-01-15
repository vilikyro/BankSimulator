#ifndef RESTAPI_H
#define RESTAPI_H
#include "RESTAPI_global.h"
#include "login.h"
#include <qstring.h>
#include <QObject>
#include <QString>
#include <QDebug>
class RESTAPI_EXPORT RESTAPI:public QObject
{
    Q_OBJECT
public:
    RESTAPI();
    ~RESTAPI();
    void setPin(QString kortinnumero, QString pin);
    bool getTrueFalse();
    void getAsiakas(QString tunnus);
    void getCredit(QString tilinnumero);
    void getDebit(QString tilinnumero);
    void getdebitTapahtuma(QString tapahtuma);
    void getcreditTapahtuma(QString credittapahtuma);
    void postTalletus(QString tilinum, QString summa);
    void postNosto(QString tilinum, QString summa);
    void postCredit(QString tilinum, QString summa);
    void setwebToken(const QByteArray &value);

private slots:
    void login_slot(QByteArray);
    void getasiakasSlot(QNetworkReply *reply);
    void getcreditSlot (QNetworkReply *reply);
    void getdebitSlot (QNetworkReply *reply);
    void getdebittapahtumaSlot (QNetworkReply *reply);
    void getcredittapahtumaSlot (QNetworkReply *reply);
    void postTallestusSlot (QNetworkReply *reply);
    void postNostoSlot (QNetworkReply *reply);
    void postCreditSlot (QNetworkReply *reply);


signals:
    void login_signal(QByteArray);
    void creditSignal(QString);
    void debitSignal(QString);
    void debittapahtumaSignal(QString);
    void credittapahtumaSignal(QString);
    void asiakasSignal(QString);
    void nimiToExe(QString,QString);
    void velkaToExe(QString);
    void saldoToExe(QString);
    void talletusToExe();
    void nostoToExe();
    void creditToExe();
    void debittapahtumaToExe(QString);
    void credittapahtumaToExe(QString);

private:

        QNetworkAccessManager * debittapahtumaManager;
        QNetworkAccessManager * credittapahtumaManager;
        QNetworkAccessManager * asiakasManager;
        QNetworkAccessManager * creditManager;
        QNetworkAccessManager * debitManager;
        QNetworkAccessManager * talletusManager;
        QNetworkAccessManager * nostoManager;
        QNetworkAccessManager * cnostoManager;
        QNetworkReply *reply;
        QByteArray response_data;
        Login *objectLogin;
        QByteArray webToken;
};
#endif // RESTAPI_H
