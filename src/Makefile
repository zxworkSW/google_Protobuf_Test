INC = -I../inc \
	  -I../protobuf \
	  -I../MySQL/include

SRC = $(wildcard */*.cpp *.cpp *.c */*.c *.cc */*.cc)
OBJ = $(patsubst %.cpp,%.o, $(patsubst %.c,%.o,$(SRC)))

CC = g++
CFLAGS = -g -Wall
VCPP = -std=c++11


all:$(OBJ)	
	
%.o:%.cpp
	$(CC) $(CFLAGS) $(INC) -c $< $(VCPP)
	
.PHONY:clean
clean:
	@$(MAKE) -C ./lib clean
	rm -rf *.o
	rm -rf */*.o	
