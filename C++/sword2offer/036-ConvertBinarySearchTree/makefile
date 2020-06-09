CC = g++
CFLAGS = -std=c++11 -Wall -g -O
CXXFLAGS = 
INCLUDE = -I../Utilities

#vpath %.cpp ../Utilities/

BIN = convertBinarySearchTree 

BIN1 = convertBinarySearchTree
OBJS1 = \
	convertBinarySearchTree.o  \
	BinaryTree.o

SRC1 = \
	convertBinarySearchTree.cpp \
	../Utilities/BinaryTree.cpp

# 链接
install: $(OBJS1) $(OBJS2) $(OBJS3)
	$(CC) $(CFLAGS) ${INCLUDE} -o $(BIN1) $(OBJS1)

# all 放在第一伪命令，在makefile中默认第一个伪命令是目标，这样需要的$(OBJS1) $(OBJS2)就会都执行
# all: $(OBJS1) $(OBJS2) $(OBJS3)

# 预处理 编译 汇编
$(OBJS1): $(SRC1) 
	$(CC) $(CFLAGS) ${INCLUDE} -c $(SRC1)


  

clean:
	rm *.o 
	rm $(BIN)