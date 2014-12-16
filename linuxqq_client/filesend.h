#ifndef FILESEND_H
#define FILESEND_H

#include <QDialog>

namespace Ui {
class FileSend;
}

class FileSend : public QDialog
{
    Q_OBJECT
    
public:
    explicit FileSend(QWidget *parent = 0);
    ~FileSend();
    
private:
    Ui::FileSend *ui;
};

#endif // FILESEND_H
