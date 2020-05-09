CC = g++

#CFLAGS = "-Wall -g -O -fPIC" # can add quotation marks, as it causes an error
# you need to add -std=c++11 so that nullptr and other c++11 features can word normally
CFLAGS = -std=c++11 -Wall -g -O -fPIC 
CXXFLAGS = 
INCLUDE = -I .
LIBPATH = .
TARGET =

# vpath %.h .

OBJS = \
	assignmentOperator.o 

SRC = \
	assignmentOperator.cpp

BIN = assignmentOperator

$(OBJS):$(SRC)
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)

install:$(OBJS)
	$(CC) -o $(BIN) $(OBJS)

clean:
	rm *.o 
	rm $(BIN)

