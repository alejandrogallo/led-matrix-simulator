#include<ncurses.h>
#include<stdio.h>
#include<unistd.h>

#include "alphabet.h"
#include "simulator.h"

int main(){
	init_matrix();
	int i; 
	int limit;
	limit  = sizeof(ALL)/sizeof(int);
	for (i=0; i<limit; i++){
		set_image(ALL[i]);
		refresh_matrix();
		sleep(1);
		if (i<limit-1) slide_left(ALL[i],ALL[i+1]);
	}
	end_matrix();
	return 0;
}
