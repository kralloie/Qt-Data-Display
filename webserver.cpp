#include "webserver.h"
#include <QWebSocket>

WebServer::WebServer(QObject *parent) : QWebSocketServer("TestServer",QWebSocketServer::NonSecureMode,parent)
{
       MySocket = nullptr;
       connect(this,SIGNAL(newConnection()),this,SLOT(whenNewConnection()));
}

void WebServer::whenNewConnection()
{
    MySocket = nextPendingConnection();
    connect(MySocket,SIGNAL(textMessageReceived(QString)),this,SLOT(onMessageReceived(QString)));
}

void WebServer::onMessageReceived(const QString &message)
{
    emit messageReceived(message);
}
