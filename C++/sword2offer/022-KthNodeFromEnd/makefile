CC = g++
CFLAGS = -std=c++11 -Wall -g -O
CXXFLAGS = 
INCLUDE = -I../Utilities

#vpath %.cpp ../Utilities/

BIN = kthNodeFromEnd

OBJS = \
	kthNodeFromEnd.o \
	List.o

SRC = \
	kthNodeFromEnd.cpp \
	../Utilities/List.cpp

$(OBJS): $(SRC) 
	$(CC) $(CFLAGS) ${INCLUDE} -c $(SRC)

install: $(OBJS)
	$(CC) $(CFLAGS) ${INCLUDE} -o $(BIN) $(OBJS) 

clean:
	rm *.o 
	rm $(BIN)

