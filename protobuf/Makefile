DIR = $(shell pwd)

CC = protoc
OBJ = --cpp_out

INC = --proto_path=$(DIR)
SRC = $(wildcard $(DIR)/*.proto)
OUT = $(OBJ)=$(DIR)


all:$(SRC)
	$(CC) $(INC) $(OUT) $^

.PHONY:clean
clean:
	rm -rf $(DIR)/*.pb.*
