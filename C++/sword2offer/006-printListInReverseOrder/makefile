CC = g++
CFLAGS = -std=c++11 -Wall -g -O
CXXFLAGS = 
INCLUDE = -I .

BIN = printListInReverseOrder

OBJS = \
	printListInReverseOrder.o  

SRC = \
	printListInReverseOrder.cpp

$(OBJS): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

install: $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS)

clean:
	rm *.o 
	rm $(BIN)