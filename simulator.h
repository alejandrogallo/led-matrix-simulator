#include<ncurses.h>
#include<stdio.h>
#include<unistd.h>


#ifndef __LED_MATRIX_SIMULATOR
#define __LED_MATRIX_SIMULATOR

#define NCOLS 8
#define NROWS 8
#define WIDTH 2
#define HEIGHT WIDTH*2
#define ON 1
#define OFF 2

void set_pixel(int i, int j, int mode);

void set_image(int frame[NROWS]);

void init_matrix();
void end_matrix();

void refresh_matrix ();

void slide_left(int *frame_left, int *frame_right);


// This is an implementation of the delay function. For every computer and processor it 
// will act differently, so you can replace it by a better function of your own. 
void _delay_ms();

#endif


