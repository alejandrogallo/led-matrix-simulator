#include "simulator.h"

int DISPLAY[NROWS]= {0x18,0x3c,0x7e,0xdb,0xff,0x24,0x5a,0xa5};

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

void set_image(int frame[NROWS]){
	int i; 
	for (i=0; i<NROWS; i++){
		DISPLAY[i] = frame[i];
	}
}

void init_matrix(){
	initscr();                      /* Start curses mode              */
	start_color();
	init_pair(ON, COLOR_GREEN, COLOR_RED);
	init_pair(OFF, COLOR_GREEN, COLOR_BLACK);
}
void end_matrix(){
	getch();                        /* Wait for user input */
	endwin();                       /* End curses mode                */
}

void refresh_matrix (){
	int i,j;
	int ctl;
	for (i=0; i<NROWS; i++){
		for (j=0; j<NCOLS; j++){
			if (DISPLAY[i]&(1<<(NCOLS-1-j))) ctl = ON; 
			else ctl =OFF;
			set_pixel(j,i,ctl);
		}
		
	}
	// REFRESH NCURSES
	refresh();
}

void _delay_ms(int ms)
{
	long pause;
	clock_t now,then;

	pause = ms*(CLOCKS_PER_SEC/1000);
	now = then = clock();
	while( (now-then) < pause )
		now = clock();
}

void slide(int *frame_left, int *frame_right, int DIRECTION){
	int i, j, k;
	for (i=0; i<NROWS; i++){
		for (j=0; j<NCOLS; j++){
			switch (DIRECTION){
				case LEFT:
					DISPLAY[i] = (frame_left[i]<<j)|(frame_right[i]>>(NCOLS-j));
					break;
				case RIGHT:
					DISPLAY[i] = (frame_left[i]>>j)|(frame_right[i]<<(NCOLS-j));
					break;
				case BOTTOM:
					break;
					//for (k=0; k<j
				case RIGHT_LEFT:
					DISPLAY[i] = (frame_left[i]>>j)|(frame_right[i]>>(NCOLS-j));
					break;
			}
		}
		refresh_matrix();
		_delay_ms(100);
	}
}
