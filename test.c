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
		if (i<limit-1) slide(ALL[i],ALL[i+1], LEFT);
	}
	end_matrix();
	return 0;
}
