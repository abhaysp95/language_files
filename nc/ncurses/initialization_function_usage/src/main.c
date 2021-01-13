// main file

#include <stdio.h>
#include <ncurses.h>
#include <stdbool.h>

int main(int argc, char **argv) {
	int ch;

	initscr();  // start curses mode
	raw();  // line buffering disabled
	keypad(stdscr, TRUE);  // we get f1, f2 etc.
	noecho();  // don't echo while we do getch
	printw("Type any character to see it in bold\n");
	ch = getch();
	// if raw hadn't been called we have to press enter before it gets to
	// the program
	if (ch == KEY_F(1)) {
		printw("F1 key pressed");
	}
	else {
		printw("The pressed key is ");
		attron(A_BOLD);
		printw("%c", ch);
		attroff(A_BOLD);
	}
	refresh();
	getch();
	endwin();
	return 0;
}