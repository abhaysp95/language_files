// main file

#include <stdio.h>
#include <ncurses.h>
#include <stdbool.h>

void print_key(const int* ch) {
	if (*ch == KEY_F(1)) {
		printw("F1 key pressed");
	}
	else {
		printw("The pressed key is ");
		/* attron(A_BOLD);
		printw("%c", *ch);
		attroff(A_BOLD); */

		// you can also use addch() to print desired character with attribute
		// either you can OR desired attributes or you can use:
		// attrset(), attron(), attroff
		// addch(*ch | A_BOLD | A_UNDERLINE);

		// there's mvaddch(), waddch(), mvwaddch() etc.
		// mvaddch() to move print the character to a point(x, y)
		// waddch() to add char to given window(you provide window name)
		// mvwaddch() is to add char to given window to give position(point(x, y))

		/* move(10, 10);
		addch(*ch | A_BOLD | A_UNDERLINE); */
		// the above two lines are similar to doing
		mvaddch(10, 10, *ch | A_BOLD | A_UNDERLINE);
	}
}

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
	print_key(&ch);
	refresh();
	getch();
	endwin();
	return 0;
}