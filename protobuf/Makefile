DIR = $(shell pwd)

.SUFFIXES: .proto .pb.cc

CC = protoc
PROTO_TYPE = --cpp_out

INC = --proto_path=$(DIR)
SRC = $(wildcard $(DIR)/*.proto)
OBJ = $(patsubst %.proto,%.pb.cc,$(SRC))

OUT = $(PROTO_TYPE)=$(DIR)


all:$(OBJ)

%.pb.cc:%.proto
	$(CC) $(INC) $(OUT) $<

.PHONY:clean
clean:
	rm -rf $(DIR)/*.pb.*

.PHONY:disclean
disclean:clean
