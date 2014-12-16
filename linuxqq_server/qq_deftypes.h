#ifndef QQ_DEFTYPES_H
#define QQ_DEFTYPES_H


#define SERVER_PORT 54321

/* UTF-8编码 中文字占3个字节 */
//信息长度限制
#define MAX_UNAME_SIZE 10 // 用户名长度
#define MAX_UPASS_SIZE 16 //  用户密码长度
#define MAX_NNAME_SIZE 12 // 用户昵称长度
#define MAX_SEX_SIZE 6 // 用户性别长度
#define MAX_QUERY_SIZE 512 // 查询语句长度

//信息类型标识
#define LOGIN_MSG_ID 0x01
#define REGISTER_MSG_ID 0x02
#define SERVER_RETURN_MSG 0x20 //服务器返回结果信息类型

//返回信息标识
#define CONNECT_DB_FAILED 0x01
#define CONNECT_DB_SUCCEED 0x02

#define NO_SUCH_USER 0x03
#define WRONG_PASSWORD 0x04
#define LOGIN_AUTH_SUCCEED 0x05

#define USERNAME_ALREADY_USED 0x06
#define NICKNAME_ALREADY_USED 0x07
#define REG_SUCCEED 0x08


#define USER_LOG_OFF_ID 0x09

//信息结构
typedef struct _LOGIN_MSG_ST{
    char userName[MAX_UNAME_SIZE];
    char userPass[MAX_UPASS_SIZE];
}LOGIN_MSG_ST;
#define LOGIN_MSG_SIZE 32

typedef struct _REGISTER_MSG_ST{
    char userName[MAX_UNAME_SIZE];
    char userPass[MAX_UPASS_SIZE];
    char nickName[MAX_NNAME_SIZE];
    char userSex[MAX_SEX_SIZE];
}REGISTER_MSG_ST;
#define REGISTER_MSG_SIZE 48

#define SERVER_MSG_MAX_SIZE 1024
#define CLIENT_MSG_MAX_SIZE 1024

#endif // QQ_DEFTYPES_H
