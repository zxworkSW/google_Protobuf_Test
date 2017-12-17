INC = -I./inc \
	  -I./protobuf \
	  -I./MySQL/include \
	  -I/usr/local/include

SRC = $(wildcard */*.cpp *.cpp *.c */*.c *.cc */*.cc)
OBJ = $(patsubst %.cpp,%.o, $(patsubst %.c,%.o,$(SRC)))
PRO = test.o

CC = g++
CFLAGS = -g -Wall
VCPP = -std=c++11
LIB = -L/usr/local/lib -lprotobuf

all:$(PRO)

$(PRO):build_proto build_obj
	$(CC) $(CFLAGS) $(INC) -o $@ $(OBJ) $(LIB) $(VCPP)

build_proto:
	@$(MAKE) -C ./protobuf

build_obj:
	@$(MAKE) -C ./src
	
.PHONY:clean
clean:
	@$(MAKE) -C ./src clean
	rm -rf *.o
	rm -rf */*.o	
