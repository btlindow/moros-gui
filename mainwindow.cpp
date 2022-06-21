#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "configuration.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->populateCb();
    connect(ui->pb_connect, &QPushButton::clicked, this, &MainWindow::onConnect);
}

void MainWindow::onConnect()
{
    qDebug() << "MainWindow::pb_connect::clicked ";
    Configuration* cfg = new Configuration(this);
    QString device = ui->cb_devices->currentText();
    if (!cfg->connectTo(device))
    {
        QMessageBox mbox;
        mbox.critical(this, "Connection Error", "Couldn't connect to device: " + device + ".");
        mbox.show();
    }
    else
    {
        cfg->show();
        this->hide();
    }
}

void MainWindow::populateCb(void)
{
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    for (auto &port: ports)
    {
        if (port.manufacturer() != "")
            ui->cb_devices->addItem(port.portName());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

