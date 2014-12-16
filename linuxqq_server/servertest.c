#include<sys/socket.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<mysql/mysql.h>
#include<pthread.h>
#include"server_head.h"
#include"qq_deftypes.h"

#define BACKLOG 20
int main()
{
	MYSQL qqMysql;
	struct sockaddr_in servAddr, clientAddr;
	int sockServ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	int nReuse = 1;
	int rtnVal;
	int sockClient;
	char clientName[INET_ADDRSTRLEN];
	socklen_t clientAddrLen = sizeof(clientAddr);
	if( sockServ < 0 ){
		perror("Socket created failed!");
		exit(EXIT_FAILURE);
	}
	setsockopt(sockServ, SOL_SOCKET, SO_REUSEADDR, (const char*)&nReuse, sizeof(int));
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(SERVER_PORT);

	rtnVal = bind(sockServ, (struct sockaddr*)&servAddr, sizeof(servAddr));
	if( rtnVal < 0 ){
		perror("Bind failed!");
		exit(EXIT_FAILURE);
	}

	rtnVal = listen(sockServ, BACKLOG);
	if( rtnVal < 0 ){
		perror("Listen error!");
		exit(EXIT_FAILURE);
	}

	for(;;){
		sockClient = accept(sockServ, (struct sockaddr*)&clientAddr, &clientAddrLen);								
		if( sockClient < 0 ){
			perror("Accept error!");
			exit(EXIT_FAILURE);
		}
		printf("sockClient %d\n",sockClient);
		if( inet_ntop(AF_INET, &clientAddr.sin_addr.s_addr, clientName, sizeof(clientName)) != NULL){
			printf("Handling client %s/%d\n",clientName,ntohs(clientAddr.sin_port));		
		}
		else
			puts("Unable to get client address.");
		
		// 新建线程监听客户端发来的信息
		pthread_t threadID;
		threadArgsST *threadArgs = (threadArgsST *)malloc(sizeof(threadArgsST));
		if( threadArgs == NULL ){
			perror("malloc() failed!");
			exit(EXIT_FAILURE);		
		}
		memset(threadArgs, 0, sizeof(threadArgsST));
		threadArgs->sockClient = sockClient;
		threadArgs->mysqlArgs = &qqMysql;
		rtnVal = 0;
		rtnVal = pthread_create(&threadID, NULL, ClientMSGWatch, threadArgs);
		if( rtnVal != 0 ){
			perror("pthread_create() failed!");		
			exit(EXIT_FAILURE);
		}
		else
			printf("threadID: %lu, sockID: %d\n",threadID,sockClient);


	}
	close(sockServ);
	return 0;
}
