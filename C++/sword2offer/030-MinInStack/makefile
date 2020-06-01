CC = g++
AR = ar
AS = as

CFLAGS = -std=c++11 -Wall -g -O
CXXFLAGS = 
INCLUDE = -I .

#vpath %.cpp ../Utilities/

BINFILES = minStack

SRC = $(wildcard *.c)
OBJS = $(patsubst %.cpp, %.o, $(SRC))

all: $(BINFILES)

OBJ1 = minStack.o
# OBJ2 = testSearch.o search.o
# OBJ3 = testOperationAdapter.o sort.o search.o operationAdapter.o

# $(OBJS): $(SRC)
# 	$(CC) $(CFLAGS) ${INCLUDE} -c $(SRC)

minStack: $(OBJ1)
	$(CC) $(CFLAGS) $(INCLUDE) -o minStack $(OBJ1)


# # OBJFILES = sort.o search.o 
# OBJFILES = $(patsubst %.cpp, %.o, $(SRC))




# TESTFILES =

# ADDLIBS =

# XDEOENDS = 



# $(BINFILES): %: $(OBJFILES)
# 	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^
	

clean:
	rm *.o 
	rm $(BINFILES)