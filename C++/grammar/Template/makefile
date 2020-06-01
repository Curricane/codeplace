CC = g++
CFLAGS = -std=c++11 -Wall -g -O
CXXFLAGS = 
INCLUDE = -I../Utilities

#vpath %.cpp ../Utilities/

BIN = simpleDemo testMyVector 

BIN1 = simpleDemo
OBJS1 = \
	simpleDemo.o  
	
SRC1 = \
	simpleDemo.cpp 

BIN2 = testMyVector
OBJS2 = \
	testMyVector.o  
	

SRC2 = \
	testMyVector.cpp 
	





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