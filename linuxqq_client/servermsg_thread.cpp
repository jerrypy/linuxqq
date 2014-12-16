#include "servermsg_thread.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>

ServerMSG_thread::ServerMSG_thread(QObject *parent)
{

}



void ServerMSG_thread::run()
{
    char arrServerMSGRecv[SERVER_MSG_MAX_SIZE + 1];
    while(1){
        recv(Login::sockClnt, arrServerMSGRecv, SERVER_MSG_MAX_SIZE+1, 0);
        Handle_Server_MSG(arrServerMSGRecv);
        memset(arrServerMSGRecv, 0, SERVER_MSG_MAX_SIZE+1);
    }

}

void ServerMSG_thread::Handle_Server_MSG(char *arrServerMSGRecv)
{
    char arrServerMSG[SERVER_MSG_MAX_SIZE];
    strncpy(arrServerMSG, arrServerMSGRecv+1, SERVER_MSG_MAX_SIZE);

    switch(arrServerMSGRecv[0]){
        case USER_LOG_OFF_ID:
            emit main_refresh_users();
            break;
        default:
            break;
    }
}
