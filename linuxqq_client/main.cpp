#include <QApplication>
#include <QDesktopWidget>
#include <mysql/mysql.h>
#include <QTextCodec>

#include "login.h"
#include "maininterface.h"
#include "servermsg_thread.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /* 程序使用utf-8编码 */
    QTextCodec *codec = QTextCodec::codecForName("utf8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    Login w;
    MainInterface mWindow;
    ServerMSG_thread serverMSGthread;
    QObject::connect(&serverMSGthread, SIGNAL(main_refresh_users(void)), &mWindow, SLOT(m_refresh_users(void)));

    w.show();
    if(w.exec()==QDialog::Accepted)
    {
        mWindow.show();
        mWindow.refresh_users();

        w.hide();

        serverMSGthread.start();
       //serverMSGthread.wait();
        return a.exec();
    }
    else
    return 0;
}

