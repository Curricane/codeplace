CC = g++
CFLAGS = -std=c++11 -Wall -g -O
CXXFLAGS = 
INCLUDE = -I../Utilities

#vpath %.cpp ../Utilities/

BIN = demo1 demo2 demo3 coutLinesAndWords

BIN1 = demo1 
BIN2 = demo2
BIN3 = demo3
BIN4 = coutLinesAndWords

OBJS1 = \
	demo1.o  

SRC1 = \
	demo1.cpp 

OBJS2 = \
	demo2.o  

SRC2 = \
	demo2.cpp

OBJS3 = \
	demo3.o  

SRC3 = \
	demo3.cpp

OBJS4 = \
	coutLinesAndWords.o  

SRC4 = \
	coutLinesAndWords.cpp


# 链接
install: $(OBJS1) $(OBJS2) $(OBJS3) $(OBJS4)
	$(CC) $(CFLAGS) ${INCLUDE} -o $(BIN1) $(OBJS1)
	$(CC) $(CFLAGS) ${INCLUDE} -o $(BIN2) $(OBJS2)
	$(CC) $(CFLAGS) ${INCLUDE} -o $(BIN3) $(OBJS3)
	$(CC) $(CFLAGS) ${INCLUDE} -o $(BIN4) $(OBJS4)

# all 放在第一伪命令，在makefile中默认第一个伪命令是目标，这样需要的$(OBJS1) $(OBJS2)就会都执行
# all: $(OBJS1) $(OBJS2) $(OBJS3)

# 预处理 编译 汇编
$(OBJS1): $(SRC1) 
	$(CC) $(CFLAGS) ${INCLUDE} -c $(SRC1)

$(OBJS2): $(SRC2) 
	$(CC) $(CFLAGS) ${INCLUDE} -c $(SRC2)

$(OBJS3): $(SRC3) 
	$(CC) $(CFLAGS) ${INCLUDE} -c $(SRC3)

$(OBJS4): $(SRC4) 
	$(CC) $(CFLAGS) ${INCLUDE} -c $(SRC4)


  

clean:
	rm *.o 
	rm $(BIN)