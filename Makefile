target: main.c
	gcc -Wall -std=c99 main.c

test: main.c
	gcc -Wall -std=c99 main.c
	./a.out

clean: 
	rm a.out
