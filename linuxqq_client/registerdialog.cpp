#include <QMessageBox>
#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "qq_deftypes.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "connectserver.h"

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());

}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}




void RegisterDialog::clearEdit()
{
    ui->editName->clear();
    ui->editPass->clear();
    ui->editConfirmPass->clear();
    ui->editNickName->clear();
}

void RegisterDialog::on_pbOk_clicked()
{
    QString uname,pass,confirmpass,sex,nickname,serverIP;
    REGISTER_MSG_ST regST;

    /* 判断用户输入是否合法模块 */
    if(!ui->editServerIP->text().isEmpty())
        serverIP = ui->editServerIP->text().trimmed();
    else{
          QMessageBox::about(0, tr("提示"),tr("地址不能为空")) ;
          return ;
         }

    if(!ui->editName->text().isEmpty())
        uname = ui->editName->text().trimmed();
    else{
    QMessageBox::about(0, tr("提示"),tr("帐号不能为空")) ;
    return ;
    }

    QByteArray baUname = uname.toLocal8Bit();
    if(strlen(baUname.data())>12){
        QMessageBox::about(0,tr("提示"),tr("帐号不超过12字节，一个汉字占3个字节"));
        clearEdit();
        return;
            }

    if(uname.indexOf(QRegExp("[`\?.,;'\"]+"),0) > -1)
    {
        QMessageBox::about(0,tr("提示"),tr("用户名中含有非法字符"));
        clearEdit();
        return;
    }




    if(!ui->editPass->text().isEmpty())
    pass = ui->editPass->text();
    else{
    QMessageBox::about(0, tr("提示"),tr("密码不能为空"));
    return ;
    }

    if(!ui->editConfirmPass->text().isEmpty())
    confirmpass = ui->editConfirmPass->text();
    else{
    QMessageBox::about(0, tr("提示"),tr("确认密码不能为空"));
    return ;
    }

    QByteArray baUpass = pass.toLocal8Bit();

    if(strlen(baUpass.data())<6 || strlen(baUpass.data())>16){
        QMessageBox::about(0, tr("提示"), tr("密码长度需在6-16位之间"));
        clearEdit();
        return;
    }

    if(pass.indexOf(QRegExp("[`\?.,;'\"]+"),0) > -1)
    {
        QMessageBox::about(0,tr("提示"),tr("密码中含有非法字符"));
        clearEdit();
        return;
    }

    if(!ui->editNickName->text().isEmpty())
    nickname = ui->editNickName->text().trimmed();
    else{
    QMessageBox::about(0, tr("提示"),tr("昵称不能为空"));
    return ;
    }
    if(nickname.indexOf(QRegExp("[`\?.,;'\"]+"),0) > -1)
    {
        QMessageBox::about(0,tr("提示"),tr("昵称中含有非法字符"));
        clearEdit();
        return;
    }



    if(!ui->cbxSex->currentText().isEmpty())
    sex = ui->cbxSex->currentText();

    if(pass.compare(confirmpass) != 0)
    {
    QMessageBox::about(0, tr("提示"),tr("确认密码与密码不相符"));
    return ;
    }
    /* 判断用户输入是否合法模块 */

    memset(&regST, 0, sizeof(regST));

    strcpy(regST.userName, baUname.data());

    strcpy(regST.userPass, baUpass.data());

    QByteArray baUnick = nickname.toLocal8Bit();
    strcpy(regST.nickName, baUnick.data());

    QByteArray baUsex = sex.toLocal8Bit();
    strcpy(regST.userSex, baUsex.data());

    char arrRegMSG[REGISTER_MSG_SIZE];
    char arrRegMSGSend[REGISTER_MSG_SIZE + 1];

    memset(arrRegMSG, 0, REGISTER_MSG_SIZE);
    memcpy(arrRegMSG, &regST, sizeof(regST));

    arrRegMSGSend[0] = REGISTER_MSG_ID;
    memcpy(arrRegMSGSend+1, arrRegMSG, REGISTER_MSG_SIZE);

     ssize_t numBytesSent;
     int rtnVal = connectserver(serverIP);

     switch(rtnVal)
     {
         case 1000001:
             QMessageBox::warning(this, tr("Warning"), tr("输入地址不合法"),QMessageBox::Ok) ;
             return ;
             break;
         case 1000002:
              QMessageBox::warning(this, tr("Warning"), tr("地址转换失败"),QMessageBox::Ok) ;
              return ;
              break;
         case 1000003:
             QMessageBox::warning(this, tr("Warning"), tr("连接服务器失败"),QMessageBox::Ok);
             return ;
             break;
         case 1000004:
             QMessageBox::warning(this, tr("Warning"), tr("连接服务器失败"), QMessageBox::Ok);
             return ;
             break;
         default:

            QString showpass = pass.replace(3,16,"******");

            int option = QMessageBox::question(this, tr("确认注册"),tr("<font color = red><h2>确认注册信息</h2></font><h6>用户名: %1</h6><h6>密码: %2\n</h6><h6>性别: %3</h6><h6>昵称: %4</h6>").arg(uname).arg(showpass).arg(sex).arg(nickname),QMessageBox::Yes | QMessageBox::Cancel,QMessageBox::Yes);
            if(option == 16384){
                numBytesSent = send(rtnVal, arrRegMSGSend,REGISTER_MSG_SIZE + 1, 0);

            }
            else{
                clearEdit();
                return;
            }
             break;
     }

     if(numBytesSent < 0){
         QMessageBox::warning(this, tr("Warning"), tr("注册信息发送失败"), QMessageBox::Ok);
     }
   else
{

         char arrServerMSGRecv[SERVER_MSG_MAX_SIZE] = " ";
         recv(rtnVal, arrServerMSGRecv, SERVER_MSG_MAX_SIZE, 0);
         if( arrServerMSGRecv[0] == 0x20 )
             switch( arrServerMSGRecv[1] ){
                 case CONNECT_DB_FAILED:
                     QMessageBox::warning(this, tr("Warning"), tr("服务器异常"), QMessageBox::Ok);
                     clearEdit();
                     break;
                 case USERNAME_ALREADY_USED:
                     QMessageBox::warning(this, tr("Warning"), tr("用户名已被注册"), QMessageBox::Ok);
                     clearEdit();
                     break;
                 case NICKNAME_ALREADY_USED:
                     QMessageBox::warning(this, tr("Warning"), tr("昵称已被注册"), QMessageBox::Ok);
                     ui->editNickName->clear();
                     break;
                 case REG_SUCCEED:
                     QMessageBox::about(0, tr("结果"),tr("注册成功"));
                     this->close();
                     break;
                 default:
                     break;
             }

    }
     ::close(rtnVal);
}
