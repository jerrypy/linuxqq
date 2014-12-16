#include "connectserver.h"
#include<QString>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include "qq_deftypes.h"
#include "login.h"


int connectserver(QString serverIP)
{
    // 服务器地址结构
    struct sockaddr_in servAddr;

    // 服务器IP地址格式转换
    char *servIP;
    QByteArray baServIP = serverIP.toLocal8Bit();
    servIP = baServIP.data();

    memset(&servAddr, 0, sizeof(servAddr));
    int rtnVal = inet_pton(AF_INET, servIP, &servAddr.sin_addr.s_addr);
    if( rtnVal == 0 ){

        return 1000001;
    }
    else if( rtnVal < 0 ){

        return 1000002;
    }

    Login::sockClnt = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if( Login::sockClnt < 0 ){

        return 1000003;
    }
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(SERVER_PORT);

    rtnVal = ::connect(Login::sockClnt, (struct sockaddr*)&servAddr, sizeof(servAddr));
    if( rtnVal < 0 )
    {

    return 1000004;
    }
    else{

        return Login::sockClnt;
       }

}


