CFLAGS = -lmysqlclient -lpthread
CC = clang

servertest:auth_func.o db_operate_func.o servertest.o server_handle_func.o
	$(CC) -o servertest auth_func.o db_operate_func.o servertest.o \
	server_handle_func.o $(CFLAGS)
db_operate_func.o:server_head.h db_operate_func.c
	$(CC) -c db_operate_func.c 
auth_func.o:server_head.h auth_func.c
	$(CC) -c auth_func.c 
servertest.o:servertest.c server_head.h qq_deftypes.h
	$(CC) -c servertest.c
server_handle_func.o:server_handle_func.c server_head.h qq_deftypes.h
	$(CC) -c server_handle_func.c

clean:
	rm -f *.o


