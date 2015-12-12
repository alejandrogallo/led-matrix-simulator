#include <curses.h>

#include <signal.h>

static void finish(int sig);

main(int argc, char *argv[])

{

	/* actualice aquí sus estructuras de datos no son de curses */

	(void) signal(SIGINT, finish); /* organizar interrupciones para terminar */

	(void) initscr(); /* inicializar la librería curses */

	keypad(stdscr, TRUE); /* permitir el mapeo de teclado */

	(void) nonl(); /* decir a curses no hacer NL->CR/NL a la salida */

	(void) cbreak(); /* coger los caracteres de entrada uno cada vez, no esperar por ellos \n */

	(void) noecho(); /* no hacer el eco de entrada */

	if (has_colors())

	{

		start_color();

		/*
		 *
		 * * Asignación de colores simples, todos los necesarios normalmente.
		 *
		 * */

		init_pair(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);

		init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);

		init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);

		init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);

		init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);

		init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);

		init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);

		init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);

	}

	for (;;)

	{

		int c = getch(); /* refresco, aceptar una tecla pulsada en la entrada */

		/* procesar el comando y la tecla pulsada */

	}

	finish(0); /* Ya lo hemos realizado */

}

static void finish(int sig)

{

	endwin();

	/* hacer el wrapup no-curses aqui */

	exit(0);

}
