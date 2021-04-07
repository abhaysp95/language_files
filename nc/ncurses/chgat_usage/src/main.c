// main file

#include <stdio.h>
#include <ncurses.h>

int main(int argc, char **argv) {
	initscr();
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_RED);
	printw("A big string, and I don't know what to type more");
	mvchgat(0, 0, -1, A_REVERSE | A_BOLD, 1, NULL);  // fifth parameter is the color index given to init_pair(1 is COLOR_CYAN)
	refresh();
	getch();
	endwin();
	return 0;
}