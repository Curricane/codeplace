CC = g++
CFLAGS = -std=c++11 -Wall -g -O

SRC = \
	queueWithTwoStacks.cpp

OBjS = \
	queueWithTwoStacks.o 

BIN = queueWithTwoStacks

$(BIN):$(OBjS)
	$(CC) $(CFLAGS) -o $(BIN) $(OBjS)

clean:
	rm -f *.o 
	rm $(BIN)