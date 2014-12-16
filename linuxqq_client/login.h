#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QCloseEvent>
#include "registerdialog.h"



namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT
    
public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    static int sockClnt;

protected:
    void closeEvent(QCloseEvent *eventClose);

signals:

    
private slots:
    void on_pbLogin_clicked();

    void on_pbRegister_clicked();

private:
    Ui::Login *ui;
    RegisterDialog regDialog;
    void clearEdit();
};



#endif // LOGIN_H

