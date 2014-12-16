#include "qq_deftypes.h"
#include <sys/socket.h>
#include "server_head.h"
#include <unistd.h>

void Login_Auth(MYSQL* login_mysql, int sockClnt, LOGIN_MSG_ST* auth_login_st)
{
	char rtnVal;
	char arrServerMSG[2];
	arrServerMSG[0] = 0x20;	
	login_mysql = connect_db(login_mysql);		
	if( login_mysql == NULL ){
	//返回客户端信息：连接数据库失败			
		arrServerMSG[1] = CONNECT_DB_FAILED;
		send(sockClnt, arrServerMSG, 2, 0);
		}
	else{
		rtnVal = login_query(login_mysql,auth_login_st,sockClnt);
		arrServerMSG[1] = rtnVal;
		send(sockClnt, arrServerMSG, 2, 0);
		if(rtnVal != LOGIN_AUTH_SUCCEED)
			close(sockClnt);
		else if(rtnVal == LOGIN_AUTH_SUCCEED)
			refresh_sendToAll(sockClnt);
	}
}

void Register_Auth(MYSQL* reg_mysql, int sockClnt, REGISTER_MSG_ST* auth_reg_st)
{
	char rtnVal;
	char arrServerMSG[2];	
	reg_mysql = connect_db(reg_mysql);
	if( reg_mysql == NULL ){
		arrServerMSG[0] = 0x20;
		arrServerMSG[1] = CONNECT_DB_FAILED;	
		}
	else{
		rtnVal = reg_query(reg_mysql,auth_reg_st);	
		arrServerMSG[0] = 0x20;
		arrServerMSG[1] = rtnVal;
		send(sockClnt, arrServerMSG, 2, 0);
		//if( rtnVal != REG_SUCCEED )
		//	close(sockClnt);
	}
}

