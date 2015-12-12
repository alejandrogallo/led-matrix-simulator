all: compile run
run:
	./main

compile:
	cc -v main.c -o main
