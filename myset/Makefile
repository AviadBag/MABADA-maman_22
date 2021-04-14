all: myset.out

run: myset.out
	./$^

myset.out: myset.c set.c bitmap.c
	gcc -Wall -ansi -pedantic -ggdb -o $@ $^

clean:
	rm -f *.out