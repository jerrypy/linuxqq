#include "maininterface.h"
#include "ui_maininterface.h"
#include "qq_deftypes.h"
#include "login.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QAbstractItemDelegate>
#include <QMessageBox>
#include <QTableWidget>
#include <mysql/mysql.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>


MainInterface::MainInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainInterface)
{
    ui->setupUi(this);
    this->move(1000,100);
    this->setFixedSize( this->width (),this->height ());

}



MainInterface::~MainInterface()
{
    delete ui;

}



void MainInterface::refresh_users()   // 刷新用户列表
{
    MYSQL users_mysql;
    MYSQL_RES *users_res;
    MYSQL_ROW users_row;
    mysql_init(&users_mysql);
    if( !mysql_real_connect(&users_mysql, "localhost", "onlineuser", "onlineuser", "qqtest", 0, NULL, 0)){
                    mysql_close(&users_mysql);
                    return ;
            }
            else{
                    mysql_set_character_set(&users_mysql, "utf8");
                    //QMessageBox::about(0,"about","ok");

            }
   char query_str[MAX_QUERY_SIZE] = "select username from onlineuser where userstatus = 'on'";
    mysql_real_query(&users_mysql, query_str,strlen(query_str));

    users_res = mysql_use_result(&users_mysql);

   unsigned int t = 0; //在线人数



  QString online_username;
   while(1){

        users_row = mysql_fetch_row(users_res);
        if(users_row == NULL) break;

        ui->tableWidget->insertRow(t);
        online_username = QString::fromLocal8Bit(users_row[0]);
        QTableWidgetItem *username = new QTableWidgetItem(online_username);
        QString online_status="在线";
        QTableWidgetItem *user_stat = new QTableWidgetItem(online_status);

        ui->tableWidget->setItem(t,0,username);
        ui->tableWidget->setItem(t,1,user_stat);



        t++;

    }
    ui->lblOnline->setText(tr("在线人数： %1人").arg(t));
    mysql_free_result(users_res);


    memset(&users_row, 0, sizeof(users_row));

    char off_str[MAX_QUERY_SIZE] = "select username from onlineuser where userstatus = 'off'";
    mysql_real_query(&users_mysql, off_str,strlen(off_str));

    users_res = mysql_use_result(&users_mysql);

    QString offline_username;

    unsigned int q = 0; //离线人数
    while(1){

        users_row = mysql_fetch_row(users_res);
        if( users_row == NULL ) break;

        ui->tableWidget->insertRow(t+q);

        offline_username = QString::fromLocal8Bit(users_row[0]);
        QString offline_status = "离线";
        QTableWidgetItem *off_username = new QTableWidgetItem(offline_username);
        QTableWidgetItem *off_status = new QTableWidgetItem(offline_status);
        ui->tableWidget->setItem(t+q,0,off_username);
        ui->tableWidget->setItem(t+q,1,off_status);
        q++;

    }
    mysql_free_result(users_res);


    mysql_close(&users_mysql);

}



void MainInterface::on_pbExit_clicked()
{
    this->close();
}

void MainInterface::closeEvent(QCloseEvent *event)   // 拦截退出关闭事件
{
    int btn = QMessageBox::warning(this,tr("Warning"),tr("确认退出？"),QMessageBox::Yes | QMessageBox::Cancel);
    if(btn == QMessageBox::Yes){
        char log_off[1];
        log_off[0] = USER_LOG_OFF_ID;
        ssize_t s = send(Login::sockClnt, log_off, 1, 0);
        if(s > 0)
            QMessageBox::about(this,tr("Warning"),"send");
        ::close(Login::sockClnt);
        event->accept();
    }
    else
        event->ignore();
}




/*
//  监听服务端信息线程
void* MainInterface::ServerMSGWatch(void *threadArgs)
{
    pthread_detach(pthread_self());
    char arrServerMSGRecv[SERVER_MSG_MAX_SIZE + 1];
    while(1){
        recv(Login::sockClnt, arrServerMSGRecv, SERVER_MSG_MAX_SIZE+1, 0);
        Handle_Server_MSG(arrServerMSGRecv);
        memset(arrServerMSGRecv, 0, SERVER_MSG_MAX_SIZE+1);
    }
    return NULL;

}

*/
// 处理服务端信息
/*
void MainInterface::Handle_Server_MSG(char *arrServerMSGRecv)
{
    char arrServerMSG[SERVER_MSG_MAX_SIZE];
    strncpy(arrServerMSG, arrServerMSGRecv+1, SERVER_MSG_MAX_SIZE);

    switch(arrServerMSGRecv[0]){
        case USER_LOG_OFF_ID:
            refresh_users();
            break;
        default:
            break;
}

*/
