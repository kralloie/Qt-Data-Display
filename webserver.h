#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <QWebSocketServer>
#include <QObject>

class WebServer : public QWebSocketServer
{
    Q_OBJECT
public:
    explicit WebServer(QObject *parent = nullptr);
signals:
    void messageReceived(QString);
private:
   QWebSocket *MySocket;
private slots:
      void whenNewConnection();
      void onMessageReceived(const QString &message);
};

#endif // WEBSERVER_H
