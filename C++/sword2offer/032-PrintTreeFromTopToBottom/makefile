CC = g++
CFLAGS = -std=c++11 -Wall -g -O
CXXFLAGS = 
INCLUDE = -I../Utilities

#vpath %.cpp ../Utilities/

BIN = printTreeFromTop2Bottom

OBJS = \
	printTreeFromTop2Bottom.o  \
	BinaryTree.o

SRC = \
	printTreeFromTop2Bottom.cpp \
	../Utilities/BinaryTree.cpp
	

$(OBJS): $(SRC) 
	$(CC) $(CFLAGS) ${INCLUDE} -c $(SRC)

install: $(OBJS)
	$(CC) $(CFLAGS) ${INCLUDE} -o $(BIN) $(OBJS) 

clean:
	rm *.o 
	rm $(BIN)