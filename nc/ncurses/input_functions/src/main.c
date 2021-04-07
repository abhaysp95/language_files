// main file

#include <stdio.h>
#include <string.h>
#include <ncurses.h>

int main(int argc, char **argv) {
	char msg[] = "Enter a string: ";
	char str[80];
	int row, col;

	initscr();
	getmaxyx(stdscr, row, col);
	mvprintw(row/2, (col - strlen(msg))/2, "%s", msg);
	getstr(str);
	mvprintw(LINES - 2, 0, "You entered: %s", str);
	getch();
	endwin();
	return 0;
}

/** functions to take inputs:
  1. getch(): reads single char at a time, if you'll not use cbreak(), curses
	 will not read your input characters contiguously but will begin read them
	 only after a new line or EOF is encountered. To avoid this, cbreak() must
	 used so that characters are immediately available to your program. When
	 noecho() is set(used), the characters that are keyed in by the user will
	 not show up on the screen.
  2. scanw(): like scanf() with added capability of getting input from any
	 location on the screen
  2.1 scanw() and mvscanw(): usage is similar to that of sscanf(), where the
	line to be scanned is provided by wgetstr() function, i.e., these functions
	call to wgetstr() function and uses the resulting line for a scan
  2.2 wscanw() and mvwscanw(): similar to above two function() except that they
	read from a window, which is supplied as one of the arguments to these
	function
  2.3 vwscanw(): similar to vscanf(). This can be used when a variable number
	of arguments are to be scanned
  3. getstr(): used to get string from the terminal. Function performs the same
	 task as would be achieved by a series of calls to getch() until a newline,
	 carriage return, or end-of-file is recieved.
  */