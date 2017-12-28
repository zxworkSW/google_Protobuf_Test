INC = -I./inc \
	  -I./protobuf \
	  -I./MySQL/include \
	  -I/usr/local/include

.SUFFIXES: .proto .pb.cc

PROTO_SRC = $(wildcard ./protobuf/*.proto)
SRC = $(wildcard */*.cpp)

PROTO_OBJ = $(patsubst %.proto,%.pb.cc, $(PROTO_SRC))
OBJ = $(patsubst %.cpp,%.o, $(SRC))
PRO = test.o

CC = g++
CFLAGS = -g -Wall
VCPP = -std=c++11
LIB = -L/usr/local/lib -lprotobuf

all:$(PRO)

$(PRO):$(PROTO_OBJ) $(OBJ)
	$(CC) $(CFLAGS) $(INC) -o $@ $^ $(LIB) $(VCPP)

%.pb.cc:%.proto
	@$(MAKE) -C ./protobuf

%.o:%.cpp
	@$(MAKE) -C ./src
	
	
	
.PHONY:clean
clean:
	@$(MAKE) -C ./src clean
	rm -rf $(PRO)
	
.PHONY:disclean
disclean:
	@$(MAKE) -C ./protobuf clean
	@$(MAKE) -C ./src clean
	rm -rf $(PRO)
