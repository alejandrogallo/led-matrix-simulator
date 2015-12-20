#include<ncurses.h>
#include<stdio.h>
#include<time.h>


#ifndef __LED_MATRIX_SIMULATOR
#define __LED_MATRIX_SIMULATOR

#define NCOLS 8
#define NROWS 8
#define WIDTH 2
#define HEIGHT WIDTH*2
#define ON 1
#define OFF 2

#define LEFT 0
#define RIGHT 1
#define TOP 2
#define BOTTOM 3
#define RIGHT_LEFT 4
#define LEFT_RIGHT 5


void set_pixel(int i, int j, int mode);

void set_image(int frame[NROWS]);

void init_matrix();
void end_matrix();

void refresh_matrix ();

void slide(int *frame_left, int *frame_right, int DIRECTION);


// This is an implementation of the delay function. For every computer and processor it 
// will act differently, so you can replace it by a better function of your own. 
void _delay_ms();

#endif


