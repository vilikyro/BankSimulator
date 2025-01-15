#include "login.h"

Login::Login(QObject *parent) : QObject(parent)
{
    qDebug()<<"Login muodostimessa";

    objectMyUrl = new MyUrl;
    base_url = objectMyUrl -> getBase_url();
    postManager = new QNetworkAccessManager(this);
}

Login::~Login()
{
    delete objectMyUrl;
    objectMyUrl = nullptr;
}

void Login::setPin(QString kortinnumero, QString pin)
{
    qDebug()<<"getPin alussa";
    QJsonObject jsonObj;
    jsonObj.insert("Kortinnumero", kortinnumero);
    jsonObj.insert("PIN", pin);

    QNetworkRequest request((base_url+"/login"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    connect(postManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(loginSlot(QNetworkReply*)));
    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());

}

void Login::getPin()
{

}


void Login::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;

    emit getTrueFalse(response_data);
    response_data = nullptr;

    /*reply->deleteLater();
    postManager->deleteLater();*/

}
