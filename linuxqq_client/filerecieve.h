#ifndef FILERECIEVE_H
#define FILERECIEVE_H

#include <QDialog>

namespace Ui {
class FileRecieve;
}

class FileRecieve : public QDialog
{
    Q_OBJECT
    
public:
    explicit FileRecieve(QWidget *parent = 0);
    ~FileRecieve();
    
private:
    Ui::FileRecieve *ui;
};

#endif // FILERECIEVE_H
