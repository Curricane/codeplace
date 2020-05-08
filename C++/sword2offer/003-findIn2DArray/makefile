CC       = g++
CFLAGS   = -Wall -g -O -fPIC
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

# if below code exists, it will not generate $(BIN)
# $(OBJS):$(SRCS)
# 	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRCS)

$(BIN):$(OBJS)
	$(CC) -o $(BIN) $(OBJS)

clean:
	rm -f *.o