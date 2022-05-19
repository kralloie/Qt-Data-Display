#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonDocument>
#include <QJsonObject>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class WebServer;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void messageReceived(const QString &message);
private:
    Ui::MainWindow *ui;
    WebServer *myWebServer;
    QJsonDocument myJson;
    QJsonObject myJsonObject;
    int ageAmount = 0;
    int ageDivisor = 0;
    int averageAge = 0.0f;
    QString avgAgeText = "";

};
#endif // MAINWINDOW_H
