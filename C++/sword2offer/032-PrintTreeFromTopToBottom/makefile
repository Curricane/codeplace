CC = g++
CFLAGS = -std=c++11 -Wall -g -O
CXXFLAGS = 
INCLUDE = -I../Utilities

#vpath %.cpp ../Utilities/

BIN = printTreeFromTop2Bottom printTreeLines printTreeInZigzag

BIN1 = printTreeFromTop2Bottom
OBJS1 = \
	printTreeFromTop2Bottom.o  \
	BinaryTree.o

SRC1 = \
	printTreeFromTop2Bottom.cpp \
	../Utilities/BinaryTree.cpp

BIN2 = printTreeLines
OBJS2 = \
	printTreeLines.o  \
	BinaryTree.o

SRC2 = \
	printTreeLines.cpp \
	../Utilities/BinaryTree.cpp

BIN3 = printTreeInZigzag
OBJS3 = \
	printTreeInZigzag.o  \
	BinaryTree.o

SRC3 = \
	printTreeInZigzag.cpp \
	../Utilities/BinaryTree.cpp





# all 放在第一伪命令，在makefile中默认第一个伪命令是目标，这样需要的$(OBJS1) $(OBJS2)就会都执行
all: $(OBJS1) $(OBJS2) $(OBJS3)

# 预处理 编译 汇编
$(OBJS1): $(SRC1) 
	$(CC) $(CFLAGS) ${INCLUDE} -c $(SRC1)

$(OBJS2): $(SRC2) 
	$(CC) $(CFLAGS) ${INCLUDE} -c $(SRC2)

$(OBJS3): $(SRC3) 
	$(CC) $(CFLAGS) ${INCLUDE} -c $(SRC3)

# 链接
install: $(OBJS1) $(OBJS2) $(OBJS3)
	$(CC) $(CFLAGS) ${INCLUDE} -o $(BIN1) $(OBJS1) 
	$(CC) $(CFLAGS) ${INCLUDE} -o $(BIN2) $(OBJS2)
	$(CC) $(CFLAGS) ${INCLUDE} -o $(BIN3) $(OBJS3) 

clean:
	rm *.o 
	rm $(BIN)