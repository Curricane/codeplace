CC = gcc
CFLAGS = 

BIN1 = serv_demo
SRC1 = demo_serv.c 

BIN2 = clnt_demo
SRC2 = demo_clnt.c

all: $(BIN1) $(BIN2)

$(BIN1):
	$(CC) -g -o $(BIN1) $(SRC1)  -lpthread
	$(CC) -g -o $(BIN2) $(SRC2) -lpthread

clean:
	rm $(BIN1) $(BIN2)
	rm -rf $(BIN1).dSYM $(BIN2).dSYM