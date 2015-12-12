#include<ncurses.h>
#include<stdio.h>
#include<unistd.h>

#define NCOLS 8
#define NROWS 8
#define WIDTH 2
#define HEIGHT WIDTH*2
#define ON 1
#define OFF 2

int DISPLAY[NROWS][NCOLS]= {
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0}
};
void set_pixel(int i, int j, int mode){
	int l,k;
	attron(COLOR_PAIR(mode));
	for (l=0; l<WIDTH; l++){
		for (k=0; k<HEIGHT; k++){
			move(j*WIDTH+l,i*HEIGHT+k);
			printw(" ");
		}
	}
	attroff(COLOR_PAIR(mode));

}
void init_matrix(){
	start_color();
	init_pair(ON, COLOR_GREEN, COLOR_RED);
	init_pair(OFF, COLOR_GREEN, COLOR_BLACK);
}

void refresh_matrix (){
	int i,j;
	int l,k;
	int ctl = 1;
	for (i=0; i<NROWS; i++){
		for (j=0; j<NCOLS; j++){
			if (DISPLAY[j][i]) ctl = 1; 
			else ctl =2;
			set_pixel(i,j,ctl);
		}
		
	}
}

int main(){
	initscr();                      /* Start curses mode              */
	init_matrix();
	refresh_matrix();
	refresh();                      /* Print it on to the real screen */
	int i; 
	for (i =0 ; i <10; i++){
		set_pixel(0,0,ON);
		refresh();
		sleep(1);
		set_pixel(0,0,OFF);
		refresh();
		sleep(1);
	}
	getch();                        /* Wait for user input */
	endwin();                       /* End curses mode                */

	return 0;
}
