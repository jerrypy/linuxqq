#include "filerecieve.h"
#include "ui_filerecieve.h"

FileRecieve::FileRecieve(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileRecieve)
{
    ui->setupUi(this);
}

FileRecieve::~FileRecieve()
{
    delete ui;
}
