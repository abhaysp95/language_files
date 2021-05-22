// main file

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int main(int argc, char **argv) {
	initscr();
	printw("Hello World !!!\n");
	refresh();
	getch();
	def_prog_mode();
	endwin();
	system("/bin/sh");
	reset_prog_mode();

	refresh();

	printw("Another string\n");
	refresh();
	getch();
	endwin();
	return 0;
}