CC = g++
CFLAGS = -std=c++11 -Wall -g -O
CXXFLAGS = 
INCLUDE = -I../Utilities

#vpath %.cpp ../Utilities/

BIN = entryNodeInListLoop

OBJS = \
	entryNodeInListLoop.o \
	List.o

SRC = \
	entryNodeInListLoop.cpp \
	../Utilities/List.cpp

$(OBJS): $(SRC) 
	$(CC) $(CFLAGS) ${INCLUDE} -c $(SRC)

install: $(OBJS)
	$(CC) $(CFLAGS) ${INCLUDE} -o $(BIN) $(OBJS) 

clean:
	rm *.o 
	rm $(BIN)


