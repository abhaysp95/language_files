// main file

#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

/** this is supposed to be bold */

int main(int argc, char **argv) {
	int ch, prev, row, col;
	prev = EOF;
	FILE *fp;
	int x, y;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <a c file name>\n", argv[0]);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		perror("Can't open input file");
		exit(1);
	}

	initscr();
	getmaxyx(stdscr, row, col);
	while((ch = fgetc(fp)) != EOF) {
		getyx(stdscr, y, x);  // current cursor position
		if (y == (row - 1)) {  // if we're at last line
			printf("< Press Any Key >");
			getch();
			clear();
			move(0, 0);  // set cursor to x:0, y:0
		}
		if (prev == '/' && ch == '*') {  // if pattern is /*
			attron(A_REVERSE | A_BLINK);
			getyx(stdscr, y, x);
			move(y, x - 1);  // move back 1 space
			printw("%c%c", '/', ch);
		}
		else {
			printw("%c", ch);
		}
		refresh();
		if (prev == '*' && ch == '/') {  // if pattern in */
			attroff(A_REVERSE | A_BLINK);
		}
		prev = ch;
	}

	getch();
	endwin();
	fclose(fp);
	return 0;
}