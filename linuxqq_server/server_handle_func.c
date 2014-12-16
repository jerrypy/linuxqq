#include<mysql/mysql.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include"server_head.h"
#include"qq_deftypes.h"

void *ClientMSGWatch(void *threadArgs)
{
	ssize_t numBytesRcvd;		
	pthread_detach(pthread_self());
	char arrClientMSGRecv[CLIENT_MSG_MAX_SIZE + 1];
	int sockClnt = ((threadArgsST *)threadArgs)->sockClient;
	MYSQL* mysqlWatch = ((threadArgsST *)threadArgs)->mysqlArgs;
	printf("sockClnt %d\n",sockClnt);
	free(threadArgs);
	//持续监听客户端发来信息
	while(1){
	numBytesRcvd = recv(sockClnt, arrClientMSGRecv, CLIENT_MSG_MAX_SIZE + 1, 0);
	//if( numBytesRcvd < 0 ){
	//	perror("while Recive failed!");		
	//	exit(EXIT_FAILURE);
	//}
	if( numBytesRcvd > 0 )
		Handle_Client_MSG(mysqlWatch, sockClnt, arrClientMSGRecv);
	//sleep(3);
	memset(arrClientMSGRecv, 0, CLIENT_MSG_MAX_SIZE + 1);
	}
	return (NULL);
}

void Handle_Client_MSG(MYSQL* mysql_handle,int sockClient, char* arrClientMSGRecv)
{
	LOGIN_MSG_ST loginST;
	REGISTER_MSG_ST regST;
	memset(&loginST, 0, sizeof(loginST));
	memset(&regST, 0, sizeof(regST));


	switch( arrClientMSGRecv[0] ){
		case LOGIN_MSG_ID:	
			memcpy(&loginST, arrClientMSGRecv + 1, sizeof(loginST));
			Login_Auth(mysql_handle, sockClient, &loginST);	
			break;
		case REGISTER_MSG_ID:
			memcpy(&regST, arrClientMSGRecv + 1, sizeof(regST));
			Register_Auth(mysql_handle, sockClient, &regST);
			close(sockClient);
			break;
		case USER_LOG_OFF_ID:
			//更新onlineuser表
			refresh_user_query(mysql_handle,sockClient);	
			close(sockClient);
			//所有在线用户更新他们的用户列表
			refresh_sendToAll(-1);
			break;
		default:
			break;
	}
}
