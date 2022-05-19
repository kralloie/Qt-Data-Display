#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include "webserver.h"

MainWindow::MainWindow(QWidget *parent)   : QMainWindow(parent)   , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myWebServer = new WebServer(this);
    myWebServer->listen(QHostAddress::LocalHost, 6969);
    connect(myWebServer,SIGNAL(messageReceived(QString)),this,SLOT(messageReceived(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::messageReceived(const QString &message)
{
    myJson = QJsonDocument::fromJson(message.toLatin1());
    myJsonObject = myJson.object();
    ui->ageList->addItem(myJson["ageValue"].toString());
    ui->birthdayList->addItem(myJson["birthday"].toString());
    ui->lastNameList->addItem(myJson["lastName"].toString());
    ui->nameList->addItem(myJson["firstName"].toString());

    ageAmount += myJson["ageValue"].toVariant().toInt();
    ageDivisor++;
    averageAge = ageAmount / ageDivisor;
    ui->avgAge->setText("Average age: " + QString::number(averageAge));
}



