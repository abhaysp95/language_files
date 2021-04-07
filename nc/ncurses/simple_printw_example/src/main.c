// main file

#include <stdio.h>
#include <ncurses.h>
#include <string.h>

int main(int argc, char **argv) {
	const char* mesg = "Just a string";
	int row, col;
	initscr();
	getmaxyx(stdscr, row, col);  // get the number of rows and columns
	// mvprintw(row/2, (col - strlen(mesg)) / 2, "%s", mesg);  // print the number at center of the screen
	attron(A_BOLD | A_UNDERLINE);
	mvaddstr(row/2, (col - strlen(mesg)) / 2, mesg);  // I think you can't pass attribute OR'ing with mesg
	attroff(A_BOLD | A_UNDERLINE);
	mvprintw(row - 2, 0, "This screen has %d rows and %d columns\n", row, col);
	printw("Try resizing you window and then run this program again");
	refresh();
	getch();
	endwin();
	return 0;
}

/** there are functions like printw(), mvprintw(), wprintw(), mvwprintw(),
 * vwprintw() etc. for printing the string */