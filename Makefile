all: compile run
run:
	./main

compile:
	gcc main.c -o main
