all: compile run
run:
	./main

compile:
	gcc -W test.c simulator.c -o test -lncurses -I.

clean:
	rm *.o
