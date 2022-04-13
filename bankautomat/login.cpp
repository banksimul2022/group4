#include "login.h"
#include "ui_login.h"
#include "QDebug"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    objectMyUrl=new MyUrl;
    base_url=objectMyUrl->getBase_url();
}

Login::~Login()
{
    delete ui;
    ui=nullptr;
    delete objectKorttiMain;
    objectKorttiMain=nullptr;
}

void Login::on_btnLogin_clicked()
{
    //qDebug()<<"base_url="+base_url;
    kortinnumero=ui->leKortinnumero->text();
    pin=ui->lePin->text();
    lukittu="2";
    objectKorttiMain=new KorttiMain(kortinnumero,lukittu);
    objectKorttiMain->show();

    QJsonObject jsonObj;
    jsonObj.insert("kortinnumero",kortinnumero);
    jsonObj.insert("pin",pin);

    QNetworkRequest request((base_url+"/login"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    LoginManager = new QNetworkAccessManager(this);
    connect(LoginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = LoginManager->post(request, QJsonDocument(jsonObj).toJson());
}

void Login::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
}

