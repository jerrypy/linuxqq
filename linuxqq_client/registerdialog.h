#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit RegisterDialog(QWidget *parent = 0);
    ~RegisterDialog();
    
private slots:
    void on_pbOk_clicked();

private:
    void clearEdit();
    Ui::RegisterDialog *ui;

};

#endif // REGISTERDIALOG_H
