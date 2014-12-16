#include "qq_deftypes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include "server_head.h"

MYSQL* connect_db(MYSQL* db_mysql)
{
	db_mysql = mysql_init(NULL);
	if( !mysql_real_connect(db_mysql, "localhost", "root", "njuptosse", "qqtest", 0, NULL, 0)){
		printf("db_error: %s\n",mysql_error(db_mysql));
		mysql_close(db_mysql);
		return NULL;		
	}
	else{
		mysql_set_character_set(db_mysql, "utf8");
		return db_mysql;		
	}
}

char login_query(MYSQL* query_mysql,LOGIN_MSG_ST* query_st,int sockClient)
{
	int rtnValInt;
	char login_query_str[MAX_QUERY_SIZE]; 
	char online_str[MAX_QUERY_SIZE];
	char online_nickname[MAX_NNAME_SIZE];
	MYSQL_RES *query_res;
	MYSQL_RES *online_res;
	MYSQL_ROW query_row;

	sprintf(login_query_str,"select userpass from users where username = '%s'", query_st->userName);	

	rtnValInt = mysql_real_query(query_mysql, login_query_str, strlen(login_query_str));
	if( rtnValInt ){
		printf("Error making query: %s\n",mysql_error(query_mysql));
		mysql_close(query_mysql);
		return 0x99;
	}
	else{
		query_res = mysql_use_result(query_mysql);		
		if( query_res ){
			query_row = mysql_fetch_row(query_res);		
			if( query_row == NULL ){	
				mysql_free_result(query_res);
				mysql_close(query_mysql);
				return NO_SUCH_USER;
			}
			else{
				if( strcmp(query_row[0], query_st->userPass)){		
					mysql_free_result(query_res);
					mysql_close(query_mysql);
					return WRONG_PASSWORD;
				}
				else{
					mysql_free_result(query_res);
					//获取用户昵称
					memset(login_query_str, 0, MAX_QUERY_SIZE);
					memset(&query_row, 0, sizeof(query_row));
					sprintf(online_str,"select nickname from users where username = '%s'",query_st->userName);
					mysql_real_query(query_mysql, online_str, strlen(online_str));
					online_res = mysql_use_result(query_mysql);
					query_row = mysql_fetch_row(online_res);
					strncpy(online_nickname, query_row[0], strlen(query_row[0]));
					memset(online_str, 0, strlen(online_str)+1);
					sprintf(online_str, "update onlineuser SET userstatus = 'on',currentSock=%d where username = '%s'",sockClient,online_nickname);
					//获取用户昵称
					mysql_free_result(online_res);
					//更新用户状态
					mysql_real_query(query_mysql, online_str, strlen(online_str));
					mysql_close(query_mysql);

					//全部用户更新用户列表
					//refresh_sendToAll(&refresh_mysql);
					return LOGIN_AUTH_SUCCEED;
				}
			}
		}
	}
	return 0x99;
}

char reg_query(MYSQL* query_mysql, REGISTER_MSG_ST* query_st)
{
		
	int rtnValInt;
        char reg_query_str[MAX_QUERY_SIZE];
	char online_str[MAX_QUERY_SIZE];
	MYSQL_RES *query_res;
	MYSQL_ROW query_row;
	sprintf(reg_query_str,"select userpass from users where username = '%s'", query_st->userName);
	sprintf(online_str,"insert into onlineuser values('%s','off',0)",query_st->nickName);
	rtnValInt = mysql_real_query(query_mysql, reg_query_str, strlen(reg_query_str));
	if( rtnValInt ){
		printf("Error making query: %s\n",mysql_error(query_mysql));
	        mysql_close(query_mysql);
		memset(reg_query_str, 0, MAX_QUERY_SIZE);
	        return 0x99;
	}
	else{
		/* 判断用户名是否已被注册 */
		query_res = mysql_use_result(query_mysql);
		if( query_res ){
                	query_row = mysql_fetch_row(query_res);	
			if( query_row != NULL ){
             	   		mysql_free_result(query_res);
		   		mysql_close(query_mysql);
				memset(reg_query_str, 0, MAX_QUERY_SIZE);
		   		return USERNAME_ALREADY_USED;	
				// 返回用户名已被注册信息
		   	}
			else{
				/* 用户名未被注册 判断是否存在相同昵称 */		
				mysql_free_result(query_res);
				memset(reg_query_str, 0, MAX_QUERY_SIZE);
				sprintf(reg_query_str, "select userpass from users where nickname = '%s'",query_st->nickName);
				rtnValInt = mysql_real_query(query_mysql, reg_query_str, strlen(reg_query_str));
				if( rtnValInt ){
					printf("Error making query: %s\n",mysql_error(query_mysql));
	        			mysql_close(query_mysql);
					memset(reg_query_str, 0, MAX_QUERY_SIZE);
	        			return 0x99;
				}
				else{
					query_res = mysql_use_result(query_mysql);
					if( query_res ){
						query_row = mysql_fetch_row(query_res);		
						if( query_row != NULL ){
							mysql_free_result(query_res);		
							mysql_close(query_mysql);
							memset(reg_query_str, 0, MAX_QUERY_SIZE);
							//返回昵称以被使用信息
							return NICKNAME_ALREADY_USED;
						}
						else{
							// 不存在相同用户名且不存在相同昵称
							memset(reg_query_str, 0, MAX_QUERY_SIZE);
							sprintf(reg_query_str, "insert into users (username,userpass,nickname,sex,regDate) values('%s','%s','%s','%s',%s)",query_st->userName,query_st->userPass,query_st->nickName,query_st->userSex,"now()");
							rtnValInt = mysql_real_query(query_mysql, reg_query_str, strlen(reg_query_str));
							if( rtnValInt ){
							printf("Error making query: %s\n",mysql_error(query_mysql));
	        					mysql_close(query_mysql);
							memset(reg_query_str, 0, MAX_QUERY_SIZE);
	        					return 0x99;
							}
							else{
								// 注册成功
								mysql_real_query(query_mysql, online_str, strlen(online_str));
								mysql_close(query_mysql);
								return REG_SUCCEED;
							}
						}
					}
		   		}
			}
		}

		}
		return 0x99;
}

//用户下线 更新onlineuser表
void refresh_user_query(MYSQL* query_mysql, int sockClient)
{
	query_mysql = connect_db(query_mysql);
	char offline_str[MAX_QUERY_SIZE];	
	sprintf(offline_str,"update onlineuser SET userstatus = 'off',currentSock = 0 where currentSock = %d",sockClient);
	mysql_real_query(query_mysql, offline_str, strlen(offline_str));
	mysql_close(query_mysql);
}

//提示所有用户更新用户列表
void refresh_sendToAll(int sockClient)
{
	MYSQL* refresh_mysql;
	refresh_mysql = connect_db(refresh_mysql);
	char online_sock_str[MAX_QUERY_SIZE];	
	char refresh_msg[2];
	sprintf(online_sock_str,"select currentSock from onlineuser where userstatus = 'on'");
	MYSQL_RES *sock_res;
	MYSQL_ROW sock_row;
	mysql_real_query(refresh_mysql, online_sock_str, strlen(online_sock_str));
	sock_res = mysql_use_result(refresh_mysql);
	sock_row = mysql_fetch_row(sock_res);
	if( sock_row == NULL ){
		return ;		
	}
	else{
		refresh_msg[0] = SERVER_RETURN_MSG;
		refresh_msg[1] = USER_LOG_OFF_ID;
		while(1){
				
			if(atoi(sock_row[0]) != sockClient)
				send(atoi(sock_row[0]), refresh_msg, 2, 0);				sock_row = mysql_fetch_row(sock_res);
			if(sock_row == NULL) break;
		}			
	}
	mysql_free_result(sock_res);
	
	mysql_close(refresh_mysql);
}
