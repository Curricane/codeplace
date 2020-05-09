CC       = g++
CFLAGS   = -std=c++11 -Wall -g -O -fPIC
CXXFLAGS = 
INCLUDE  = -I .
TARGET   = 
LIBPATH  = .

# vpath %.h .

OBJS     = \
	divide-rightup.o

SRCS     = \
	divide-rightup.cpp

BIN = divide-rightup



# makefile uses the first command as the final command, equivalent to the main function in c.
$(OBJS):$(SRCS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRCS)

# this command should behind the main command
install:$(OBJS)
	$(CC) -o $(BIN) $(OBJS)

clean:
	rm -f *.o
	rm $(BIN)