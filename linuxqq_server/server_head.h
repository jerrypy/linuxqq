#ifndef __SERVER_HEAD__
#define __SERVER_HEAD__
#include "qq_deftypes.h"
#include <mysql/mysql.h>
#include <stdio.h>

typedef struct _thread_Args
{
	int sockClient;	
	MYSQL* mysqlArgs;
}threadArgsST;

void Login_Auth(MYSQL*,int,LOGIN_MSG_ST*);
MYSQL* connect_db(MYSQL*);
char login_query(MYSQL*,LOGIN_MSG_ST*,int);
void Handle_Client_MSG(MYSQL*, int, char*);
void Register_Auth(MYSQL*,int,REGISTER_MSG_ST*);
char reg_query(MYSQL*,REGISTER_MSG_ST*);
void *ClientMSGWatch(void *threadArgs);
void refresh_user_query(MYSQL*, int);
void refresh_sendToAll(int);



#endif
