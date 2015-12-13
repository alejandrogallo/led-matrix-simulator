all: compile run
run:
	./test

compile:
	gcc -W test.c simulator.c -o test -lncurses -I.

clean:
	rm *.o
