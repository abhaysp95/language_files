// main file

#include <stdio.h>
#include <ncurses.h>
#include <menu.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

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
	"Choice 11",
	"Choice 12",
	"Choice 13",
	"Choice 14",
	"Choice 15",
	"Choice 16",
	"Choice 17",
	"Choice 18",
	"Choice 19",
	"Choice 20",
	"Exit",
	(char*)NULL
};

int main(int argc, char **argv) {
	ITEM** my_items;
	MENU* my_menu;
	WINDOW* my_menu_win;
	int n_choices;

	initscr();
	cbreak();
	noecho();
	start_color();
	curs_set(0);

	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);

	n_choices = ARRAY_SIZE(choices);

	my_items = (ITEM**)calloc(n_choices, sizeof(ITEM*));

	for (int i = 0; i < n_choices; ++i)
		my_items[i] = new_item(choices[i], choices[i]);

	my_menu = new_menu((ITEM**)my_items);

	menu_opts_off(my_menu, O_SHOWDESC);

	my_menu_win = newwin(10, 50, 4, 4);
	keypad(my_menu_win, TRUE);

	set_menu_win(my_menu, my_menu_win);
	set_menu_sub(my_menu, derwin(my_menu_win, 6, 48, 3, 1));
	set_menu_format(my_menu, 5, 3);
	set_menu_mark(my_menu, " * ");

	box(my_menu_win, 0, 0);

	attron(COLOR_PAIR(2));
	mvprintw(LINES - 3, 0, "Use PageUp and PageDown to scroll");
	mvprintw(LINES - 2, 0, "Use Arrow keys to navigate(F1 to Exit)");
	attroff(COLOR_PAIR(2));
	refresh();

	post_menu(my_menu);
	wrefresh(my_menu_win);;

	int ch;
	while ((ch = wgetch(my_menu_win)) != KEY_F(1)) {
		switch (ch) {
			case KEY_DOWN:
				menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				break;
			case KEY_NPAGE:
				menu_driver(my_menu, REQ_SCR_DLINE);
				break;
			case KEY_PPAGE:
				menu_driver(my_menu, REQ_SCR_UPAGE);
				break;
			case KEY_LEFT:
				menu_driver(my_menu, REQ_LEFT_ITEM);
				break;
			case KEY_RIGHT:
				menu_driver(my_menu, REQ_RIGHT_ITEM);
				break;
		}
		wrefresh(my_menu_win);
	}

	unpost_menu(my_menu);
	free_menu(my_menu);
	for (int i = 0; i < n_choices; ++i)
		free_item(my_items[i]);
	delwin(my_menu_win);

	endwin();

	return 0;
}