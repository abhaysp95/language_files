// main file

#include "../inc/player.h"

#include <stdio.h>
#include <ncurses.h>

int main(int argc, char **argv) {
	initscr();
	cbreak();
	noecho();
	use_default_colors();
	start_color();

	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	attr_t wmsg = A_REVERSE | COLOR_PAIR(1);

	chtype pchar = '@' | COLOR_PAIR(2);

	int x_max, y_max;
	getmaxyx(stdscr, y_max, x_max);

	WINDOW* playwin = newwin((y_max - 10), (x_max - 20), 5, 10);
	box(playwin, 0, 0);
	mvwprintw(playwin, 0, 2, "[Game Window]");
	refresh();
	wrefresh(playwin);

	keypad(playwin, TRUE);
	Player me = init_player(playwin, 1, 1, pchar);
	int choice;
	display_player(&me);
	wrefresh(playwin);

	WINDOW* msg;
	msg = newwin(2, 40, 1, 1);
	attron(wmsg);
	wprintw(msg, "Press 'x' to cancel");
	wrefresh(msg);
	attroff(wmsg);

	while ((choice = wgetch(playwin)) != 'x') {
		player_move(&me, choice);
		display_player(&me);
		wrefresh(playwin);
	}

	if (choice == 'x') {
		// destroy and create new window
		/*if (msg != NULL)*/
			/*delwin(msg);*/
		/*msg = newwin(2, 40, 1, 1);*/

		// logic to update message(kind of)
		int status = 0;
		if (msg != NULL) {
			status = wdeleteln(msg);
			wmove(msg, 0, 0);
		}
		if (status != -1)
			wprintw(msg, "Press any key to exit");
		wrefresh(msg);

		// logic to update message(kind of)
	}

	getch();
	endwin();
	return 0;
}