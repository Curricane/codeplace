CC = g++
AR = ar
AS = as

CFLAGS = -std=c++11 -Wall -g -O
CXXFLAGS = 
INCLUDE = -I .

#vpath %.cpp ../Utilities/

BINFILES = testSort testSearch testOperationAdapter

SRC = $(wildcard *.c)
OBJS = $(patsubst %.cpp, %.o, $(SRC))

all: $(BINFILES)

OBJ1 = testSort.o sort.o
OBJ2 = testSearch.o search.o
OBJ3 = testOperationAdapter.o sort.o search.o operationAdapter.o

# $(OBJS): $(SRC)
# 	$(CC) $(CFLAGS) ${INCLUDE} -c $(SRC)

testSort: $(OBJ1)
	$(CC) $(CFLAGS) $(INCLUDE) -o testSort $(OBJ1)

testSearch: $(OBJ2)
	$(CC) $(CFLAGS) $(INCLUDE) -o testSearch $(OBJ2)

testOperationAdapter: $(OBJ3)
	$(CC) $(CFLAGS) $(INCLUDE) -o testOperationAdapter $(OBJ3)

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