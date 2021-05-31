// main file

#include <stdio.h>
#include <ncurses.h>
#include <menu.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 4

char* choices[] = {
	"Choice 1",
	"Choice 2",
	"Choice 3",
	"Choice 4",
	"Choice 5",
	"Choice 6",
	"Choice 7",
	"Choice 8",
	"Choice 9",
	"Choice 10",
	"Exit"
};

void print_in_middle(WINDOW* win, int starty, int startx, int width, char* string, chtype color);

int main(int argc, char **argv) {
	ITEM** my_items;
	int ch;
	MENU* my_menu;
	WINDOW* my_menu_win;
	int n_choices, i;

	// initialize curses
	initscr();
	start_color();
	noecho();
	cbreak();
	curs_set(0);
	keypad(stdscr, TRUE);

	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);

	n_choices = ARRAY_SIZE(choices);
	my_items = (ITEM**)calloc(n_choices, sizeof(ITEM*));
	for (i = 0; i < n_choices; ++i)
		my_items[i] = new_item(choices[i], choices[i]);
	my_items[n_choices] = (ITEM*)NULL;

	// create menu
	my_menu = new_menu((ITEM**)my_items);

	// create the window to be associated with the menu
	my_menu_win = newwin(10, 40, 4, 4);
	keypad(my_menu_win, TRUE);

	// set main window and sub window
	set_menu_win(my_menu, my_menu_win);
	set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));
	set_menu_format(my_menu, 5, 1);

	// set menu mark to the string "*"
	set_menu_mark(my_menu, " -> ");

	// print border and title for main window
	box(my_menu_win, 0, 0);
	print_in_middle(my_menu_win, 1, 0, 40, "My Menu", COLOR_PAIR(1));
	mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
	mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
	mvwaddch(my_menu_win, 2, 39, ACS_RTEE);
	refresh();

	// post the menu
	post_menu(my_menu);
	wrefresh(my_menu_win);

	attron(COLOR_PAIR(2));
	mvprintw(LINES - 2, 0, "F1 to Exit!!!");
	mvprintw(LINES - 1, 0, "Use Page Up or Page Down to scroll down or up a page of items!!!");
	attroff(COLOR_PAIR(2));
	refresh();

	while ((ch = wgetch(my_menu_win)) != KEY_F(1))  {
		switch(ch) {
			case KEY_DOWN:
				menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				break;
			case KEY_NPAGE:
				menu_driver(my_menu, REQ_SCR_DPAGE);
				break;
			case KEY_PPAGE:
				menu_driver(my_menu, REQ_SCR_UPAGE);
				break;
		}
		wrefresh(my_menu_win);
	}

	// unpost and free all the memory taken up
	unpost_menu(my_menu);
	free_menu(my_menu);
	for (i = 0; i < n_choices; ++i)
		free_item(my_items[i]);
	if (my_menu_win != NULL)
		delwin(my_menu_win);

	endwin();
	return 0;
}

void print_in_middle(WINDOW* win, int starty, int startx, int width, char* string, chtype color) {
	int length, x, y;
	float temp;

	if (win == NULL)
		win = stdscr;
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