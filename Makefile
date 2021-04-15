BIN     := bin
SRC     := src
INCLUDE := include

CC       := gcc
CC_FLAGS := -Wall -ansi -pedantic -g -O0

EXECUTABLE := myset.out

all: $(BIN)/$(EXECUTABLE)

run: clean all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): ${SRC}/*.c
	${CC} ${CC_FLAGS} -o $@ -I${INCLUDE} $^

clean:
	rm -f ${BIN}/*
	clear