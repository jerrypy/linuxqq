#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "registerdialog.h"
#include "maininterface.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "qq_deftypes.h"
#include "connectserver.h"

int Login::sockClnt = -1;

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
}

Login::~Login()
{
    delete ui;
}



void Login::clearEdit()
{
        ui->editName->clear();
        ui->editPass->clear();
        ui->editName->setFocus();
}

void Login::on_pbLogin_clicked()
{
    // 用户名账户密码处理
    QString QSuserName, QSuserPass, QSserverIP;
    LOGIN_MSG_ST loginST; // 登录信息结构体
    char arrLoginMSG[LOGIN_MSG_SIZE];
    char arrLoginMSGSend[LOGIN_MSG_SIZE + 1]; // 加入信息标识后的数组

    QSuserName = ui->editName->text().trimmed();
    QSuserPass = ui->editPass->text().trimmed();
    QSserverIP = ui->editServerIP->text().trimmed();



    QByteArray baUname = QSuserName.toLocal8Bit();
    strcpy(loginST.userName, baUname.data());

    QByteArray baUpass = QSuserPass.toLocal8Bit();
    strcpy(loginST.userPass, baUpass.data());

    if( strlen(loginST.userName) > 10 || strlen(loginST.userName) == 0 || strlen(loginST.userPass) == 0){
        memset(loginST.userName, 0, MAX_UNAME_SIZE);
        memset(loginST.userPass, 0, MAX_UPASS_SIZE);
        QMessageBox::warning(this, tr("Warning"), tr("登录信息输入不合法"), QMessageBox::Ok);
        return ;
    }
    if(QSuserName.indexOf(QRegExp("[`\?.,;'\"]+"),0) > -1)
    {
        QMessageBox::about(0,tr("提示"),tr("帐号中含有非法字符"));
        clearEdit();
        return;
    }
    if(QSuserPass.indexOf(QRegExp("[`\?.,;'\"]+"),0) > -1)
    {
        QMessageBox::about(0,tr("提示"),tr("密码中含有非法字符"));
        clearEdit();
        return;
    }





    memset(arrLoginMSG, 0, LOGIN_MSG_SIZE);
    memcpy(arrLoginMSG, &loginST, sizeof(loginST));

    /* 信息标识添加 */
    memset(arrLoginMSGSend, 0, LOGIN_MSG_SIZE + 1);
    arrLoginMSGSend[0] = LOGIN_MSG_ID;
    memcpy(arrLoginMSGSend + 1, arrLoginMSG, sizeof(arrLoginMSG));

    ssize_t numBytesSent;

    // 连接服务端 返回socket_fd
    int rtnVal = connectserver(QSserverIP);

    switch(rtnVal)
    {
        case 1000001:
            QMessageBox::warning(this, tr("Warning"), tr("输入地址不合法"),QMessageBox::Ok) ;
            ::close(rtnVal);
            return ;
            break;
        case 1000002:
             QMessageBox::warning(this, tr("Warning"), tr("地址转换失败"),QMessageBox::Ok) ;
             ::close(rtnVal);
             return ;
             break;
        case 1000003:
            QMessageBox::warning(this, tr("Warning"), tr("连接服务器失败"),QMessageBox::Ok);
            ::close(rtnVal);
            return ;
            break;
        case 1000004:
            QMessageBox::warning(this, tr("Warning"), tr("连接服务器失败"), QMessageBox::Ok);
            ::close(rtnVal);
            return ;
            break;
        default:
            // 若成功连接 发送信息
            numBytesSent = send(rtnVal, arrLoginMSGSend, LOGIN_MSG_SIZE + 1, 0);
            break;
    }


    if(numBytesSent < 0){
        QMessageBox::warning(this, tr("Warning"), tr("发送失败"), QMessageBox::Ok);
    }
    else{
    char arrServerMSGRecv[SERVER_MSG_MAX_SIZE] = " ";
    recv(rtnVal, arrServerMSGRecv, SERVER_MSG_MAX_SIZE, 0);
    if( arrServerMSGRecv[0] == SERVER_RETURN_MSG )
        switch( arrServerMSGRecv[1] ){
            case CONNECT_DB_FAILED:
                QMessageBox::warning(this, tr("Warning"), tr("服务器异常"), QMessageBox::Ok);
                break;
            case NO_SUCH_USER:
                QMessageBox::warning(this, tr("Warning"), tr("没有此用户"), QMessageBox::Ok);
                clearEdit();
                break;
            case WRONG_PASSWORD:
                QMessageBox::warning(this, tr("Warning"), tr("密码错误"), QMessageBox::Ok);
                ui->editPass->clear();
                ui->editPass->setFocus();
                break;
            case LOGIN_AUTH_SUCCEED:
                accept();

                break;
            default:
                break;
        }
    }


}


void Login::on_pbRegister_clicked()
{
   // RegisterDialog *reg = new RegisterDialog;
    //  reg->show();
    regDialog.show();

}

void Login::closeEvent(QCloseEvent *eventClose)
{
    int btn = QMessageBox::warning(this,tr("Warning"),tr("确认退出？"),QMessageBox::Yes | QMessageBox::Cancel);
    if(btn == QMessageBox::Yes){
        ::close(Login::sockClnt);
        eventClose->accept();
    }
    else
        eventClose->ignore();

}
