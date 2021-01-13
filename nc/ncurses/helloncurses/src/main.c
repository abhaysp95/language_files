// main file

#include <stdio.h>
#include <ncurses.h>

int main(int argc, char **argv) {
	initscr();  // start curses mode
	printw("Hello Ncurses World");
	refresh();  // print it on the real screen
	getch();  // wait for user input
	endwin();  // end curses mode
	return 0;
}