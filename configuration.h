#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include <QSerialPort>

namespace Ui {
class Configuration;
}

class Configuration : public QMainWindow
{
    Q_OBJECT

public:
    explicit Configuration(QWidget *parent = nullptr);
    bool connectTo(QString);
    ~Configuration();

private:
    Ui::Configuration *ui;
    QString _port;
};

#endif // CONFIGURATION_H
