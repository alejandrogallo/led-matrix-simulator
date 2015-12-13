#include<ncurses.h>
#include<stdio.h>
#include<unistd.h>

#include "alphabet.h"
#include "simulator.h"

int main(){
	init_matrix();
	int i; 
	for (i=0; i<sizeof(ALL)/sizeof(ALL[0]); i++){
		set_image(ALL[i]);
		refresh_matrix();
		sleep(1);
	}
	end_matrix();
	return 0;
}
