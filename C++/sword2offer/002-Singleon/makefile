CC = g++

#-w means close warnings
#-W means show warnings which will cause errors
# -Wall means show all warnings
CFLAGS = -std=c++11 -g -Wall
CXXFLAGS =
INCLUDE = -I .
TARGET =
LIBPATH = 

OBJS = \
	Singleon.o 

SRC = \
	Singleon.cpp

BIN = \
	Singleon

$(OBJS):$(SRC)
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)

install:$(OBJS)
	$(CC) -o $(BIN) $(OBJS) 

clean:
	rm *.o 
	rm $(BIN)
