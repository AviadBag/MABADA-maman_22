all: myset.out

run: myset.out
    ./$^

myset.out: myset.c
    gcc -Wall -ansi -pedantic -ggdb -o $@ $^

clean:
    rm -f *.out