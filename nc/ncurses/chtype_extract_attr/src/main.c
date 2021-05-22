// main file

#include <stdio.h>
#include <ncurses.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define A_ATTRS (A_ATTRIBUTES ^ A_COLOR)

char* color_pairs[] = {
	"Found color pair 1, [COLOR_RED, COLOR_BLACK]",
	"Found color pair 2, [COLOR_GREEN, COLOR_BLACK]",
	"Found color pair 3, [COLOR_YELLOW, COLOR_BLACK]",
	"Found color pair 4, [COLOR_BLUE, COLOR_BLACK]",
	"Found color pair 5, [COLOR_CYAN, COLOR_BLACK]",
	"Found color pair 6, [COLOR_MAGENTA, COLOR_BLACK]",
	"Found color pair 7, [COLOR_WHITE, COLOR_BLACK]"
};

int color_pair_len = sizeof(color_pairs) / sizeof(char*);

void setup_color_pairs();
unsigned int get_random_color(int max_color_index);

int main(int argc, char **argv) {
	initscr();
	noecho();
	curs_set(0);

	start_color();
	setup_color_pairs();

	WINDOW* output_win = newwin(1, 1, 5, 5);
	WINDOW* status_win = newwin(1, 75, 0, 0);
	char* status;

	refresh();
	wrefresh(output_win);
	wrefresh(status_win);

	bool reverse_on = false;
	char input = ' ';

	while (input != 'x') {
		mvwaddch(output_win, 0, 0, '@' | get_random_color(7));

		status = (char*)malloc(sizeof(char) * 1024);
		strcpy(status, "");

		wnoutrefresh(output_win);  // refresh output_win without refresh

		chtype ch = mvwinch(output_win, 0, 0);  // capture the character

		// code to detect specific color
		attr_t color = ch & A_COLOR;
		int idx = 0;
		for (;idx < color_pair_len; ++idx) {
			if (color == COLOR_PAIR(idx))
				break;
		}
		if (idx < color_pair_len)
			strncat(status, color_pairs[idx], strlen(color_pairs[idx]));

		// code to detect specific attribute
		attr_t reverse = ch & A_ATTRS;
		if (reverse == A_REVERSE)
			strncat(status, " [Reversed]", 12);

		// erase any previous message and display new message
		werase(status_win);
		mvwprintw(status_win, 0, 1, status);

		wnoutrefresh(status_win);

		doupdate();

		input = tolower(getch());

		// if user entered 'r', apply reverse attribute
		if (input == 'r') {
			if (reverse_on) {
				wattrset(output_win, A_NORMAL);
				reverse_on = false;
			}
			else {
				wattrset(output_win, A_REVERSE);
				reverse_on = true;
			}
		}
		if (status != NULL)
			free(status);
	}

	endwin();
	return 0;
}

void setup_color_pairs() {
	srand((unsigned)time(NULL));
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

unsigned int get_random_color(int max_color_index) {
	int color_pair_index = rand() % max_color_index + 1;
	attr_t random_color = COLOR_PAIR(color_pair_index);
	return random_color;
}