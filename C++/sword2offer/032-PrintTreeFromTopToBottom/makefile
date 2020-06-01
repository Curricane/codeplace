CC = g++
CFLAGS = -std=c++11 -Wall -g -O
CXXFLAGS = 
INCLUDE = -I../Utilities

#vpath %.cpp ../Utilities/

BIN = printTreeFromTop2Bottom printTreeLines
BIN1 = printTreeFromTop2Bottom
BIN2 = printTreeLines

OBJS1 = \
	printTreeFromTop2Bottom.o  \
	BinaryTree.o

SRC1 = \
	printTreeFromTop2Bottom.cpp \
	../Utilities/BinaryTree.cpp

OBJS2 = \
	printTreeLines.o  \
	BinaryTree.o

SRC2 = \
	printTreeLines.cpp \
	../Utilities/BinaryTree.cpp

# all 放在第一伪命令，在makefile中默认第一个伪命令是目标，这样需要的$(OBJS1) $(OBJS2)就会都执行
all: $(OBJS1) $(OBJS2)

# 预处理 编译 汇编
$(OBJS1): $(SRC1) 
	$(CC) $(CFLAGS) ${INCLUDE} -c $(SRC1)

$(OBJS2): $(SRC2) 
	$(CC) $(CFLAGS) ${INCLUDE} -c $(SRC2)

# 链接
install: $(OBJS1) $(OBJS2)
	$(CC) $(CFLAGS) ${INCLUDE} -o $(BIN1) $(OBJS1) 
	$(CC) $(CFLAGS) ${INCLUDE} -o $(BIN2) $(OBJS2) 

clean:
	rm *.o 
	rm $(BIN)