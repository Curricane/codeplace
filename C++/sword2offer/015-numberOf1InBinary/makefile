CC = g++
CFLAGS = -std=c++11 -Wall -g -O
CXXFLAGS = 
INCLUDE = -I .

#vpath %.cpp ../Utilities/

BIN = numberOf1InBinary

OBJS = \
	numberOf1InBinary.o 

SRC = \
	numberOf1InBinary.cpp
	

$(OBJS): $(SRC) 
	$(CC) $(CFLAGS) ${INCLUDE} -c $(SRC)

install: $(OBJS)
	$(CC) $(CFLAGS) ${INCLUDE} -o $(BIN) $(OBJS) 

clean:
	rm *.o 
	rm $(BIN)