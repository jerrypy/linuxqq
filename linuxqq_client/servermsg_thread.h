#include <QThread>
#include "qq_deftypes.h"
#include "login.h"

#ifndef SERVERMSG_THREAD_H
#define SERVERMSG_THREAD_H

class ServerMSG_thread : public QThread
{
    Q_OBJECT;
public:
    ServerMSG_thread(QObject *parent = NULL);
    void run();
    void Handle_Server_MSG(char*);

signals:
    void main_refresh_users();
};

#endif // SERVERMSG_THREAD_H
