// main file

#include <stdio.h>
#include <string.h>
#include <ncurses.h>

WINDOW* create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

int main(int argc, char **argv) {
	WINDOW* my_win;
	int startx, starty, width, height;
	int ch;

	initscr();
	cbreak();

	keypad(stdscr, TRUE);

	height = 3;
	width = 40;
	starty = (LINES - height) / 2;
	startx = (COLS - width) / 2;
	printw("Press F1 to exit");
	refresh();

	my_win = create_newwin(height, width, starty, startx);

	while((ch = getch()) != KEY_F(1)) {
		switch(ch) {
			case KEY_LEFT:
				destroy_win(my_win);
				my_win = create_newwin(height, width, starty, --startx);
				break;
			case KEY_RIGHT:
				destroy_win(my_win);
				my_win = create_newwin(height, width, starty, ++startx);
				break;
			case KEY_UP:
				destroy_win(my_win);
				my_win = create_newwin(height, width, --starty, startx);
				break;
			case KEY_DOWN:
				destroy_win(my_win);
				my_win = create_newwin(height, width, ++starty, startx);
				break;
		}
	}
	endwin();
	return 0;
}

WINDOW* create_newwin(int height, int width, int starty, int startx) {
	WINDOW* local_win;
	local_win = newwin(height, width, starty, startx);
	box(local_win, 0, 0);	/**
							 0, 0 gives default characters for the vertical and
							 for horizontal lines */
	char str[] = "This is a window !!!";
	attron(A_BOLD);
	mvwprintw(local_win, 1, ((width - strlen(str)) / 2), str);
	curs_set(0);
	wrefresh(local_win);	/** show that box */
	attroff(A_BOLD);
	return local_win;
}

void destroy_win(WINDOW* local_win) {
	/** box(local_win, ' ', ' ');  : This won't produce the desired result of
	 * erasing the window. It will leave it's four corners and so an ugly remnant
	 * of window */
	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	/** The paramters taken are:
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window
	 * 3. rs: character to be used for the right side of the window
	 * 4. ts: character to be used for the top side of the window
	 * 5. bs: character to be used for the bottom side of the window
	 * 6. tl: character to be used for the top left corner of the window
	 * 7. tr: character to be used for the top right corner of the window
	 * 8. bl: character to be used for the bottom left corner of the window
	 * 9. br: character to be used for the bottom right corner of the window
	 */
	wrefresh(local_win);
	delwin(local_win);
}