// main file

#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <panel.h>

#define NROWS 10
#define NCOLS 40

void init_wins(WINDOW** wins, int n);
void win_show(WINDOW* win, char* label, int label_color);
void print_in_middle(WINDOW* win, int starty, int startx, int width, char* string, chtype color);

int main(int argc, char **argv) {
	WINDOW* my_wins[3];
	PANEL* my_panels[3];
	PANEL* top;
	int ch;

	initscr();
	cbreak();
	noecho();
	curs_set(0);

	keypad(stdscr, TRUE);

	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);

	init_wins(my_wins, 3);

	my_panels[0] = new_panel(my_wins[0]);
	my_panels[1] = new_panel(my_wins[1]);
	my_panels[2] = new_panel(my_wins[2]);

	// setup the user pointer to next panel
	set_panel_userptr(my_panels[0], my_panels[1]);
	set_panel_userptr(my_panels[1], my_panels[2]);
	set_panel_userptr(my_panels[2], my_panels[0]);

	// update stacking order. 2nd panel will be on top
	update_panels();

	// show on screen
	attron(COLOR_PAIR(4));
	mvprintw(LINES - 2, 0, "Use tab to browse through windows (F1 to Exit)");
	attroff(COLOR_PAIR(4));
	doupdate();

	top = my_panels[2];

	while ((ch = getch()) != KEY_F(1)) {
		// use this to get keycode
		mvprintw(20, 5, "Key Name: %s - 0x%02x\n", keyname(ch), ch);
		switch(ch) {
			case 9:
				top = (PANEL*)panel_userptr(top);
				top_panel(top);
				break;
			case 10:
				// this is not exactly cyclic
				top = (PANEL*)panel_userptr(top);
				bottom_panel(top);
				break;
		}
		update_panels();
		doupdate();
	}

	for (int i = 0; i < 3; ++i)
		del_panel(my_panels[i]);
	// deleting panel doesn't deletes the window
	for (int i = 0; i < 3; ++i)
		delwin(my_wins[i]);

	endwin();
	return 0;
}

void init_wins(WINDOW** wins, int n) {
	int x, y;
	char label[80];
	y = 2;
	x = 10;
	for (int i = 0; i < n; ++i) {
		wins[i] = newwin(NROWS, NCOLS, y, x);
		sprintf(label, "Window Number %d", i + 1);
		win_show(wins[i], label, i + 1);
		y += 3;
		x += 10;
	}
}

// show window with border and label
void win_show(WINDOW* win, char* label, int label_color) {
	int startx, starty, height, width;

	getmaxyx(win, height, width);
	getbegyx(win, starty, startx);

	box(win, 0, 0);
	mvwaddch(win, 2, 0, ACS_LTEE);
	mvwhline(win, 2, 1, ACS_HLINE, width - 2);
	mvwaddch(win, 2, width - 1, ACS_RTEE);

	print_in_middle(win, 1, 0, width, label, COLOR_PAIR(label_color));
	mvwaddstr(win, height / 2, (width - strlen(label)) / 2, label);
}

void print_in_middle(WINDOW* win, int starty, int startx, int width, char* string, chtype color) {
	if (win == NULL)
		win = stdscr;
	int y, x, temp, length;
	getyx(win, y, x);
	if (startx != 0)
		x = startx;
	if (starty != 0)
		y = starty;
	if (width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length) / 2;
	x = startx + (int)temp;
	wattron(win, color);
	mvwprintw(win, y, x, "%s", string);
	wattroff(win, color);
	refresh();
}