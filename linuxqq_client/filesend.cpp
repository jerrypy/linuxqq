#include "filesend.h"
#include "ui_filesend.h"

FileSend::FileSend(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileSend)
{
    ui->setupUi(this);
}

FileSend::~FileSend()
{
    delete ui;
}
