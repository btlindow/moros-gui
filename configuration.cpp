#include "configuration.h"
#include "ui_configuration.h"

Configuration::Configuration(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Configuration)
{
    ui->setupUi(this);
}

bool Configuration::connectTo(QString port)
{
    this->_port = port;
    return true;
}

Configuration::~Configuration()
{
    delete ui;
}
