// main file

#include <stdio.h>
#include <ncurses.h>
#include <menu.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

char* choices[] = {
	"choice 1",
	"choice 2",
	"choice 3",
	"choice 4",
	"choice 5",
	"Exit",
	(char*)NULL
};


int main(int argc, char **argv) {
	ITEM** items;
	MENU* menu;
	WINDOW* menu_win;
	int n_choices;


	initscr();
	cbreak();
	noecho();
	start_color();
	curs_set(0);

	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);

	n_choices = ARRAY_SIZE(choices);

	items = (ITEM**)calloc(n_choices, sizeof(ITEM*));
	for (int i = 0; i < n_choices; ++i)
		items[i] = new_item(choices[i], choices[i]);

	menu = new_menu((ITEM**)items);

	menu_win = newwin(8, 40, 4, 4);
	keypad(menu_win, TRUE);
	set_menu_win(menu, menu_win);
	set_menu_sub(menu, derwin(menu_win, 5, 38, 2, 1));
	set_menu_mark(menu, "--> ");
	box(menu_win, 0, 0);

	menu_opts_off(menu, O_ONEVALUE);

	attron(COLOR_PAIR(2));
	mvprintw(LINES - 3, 0, "Use <space> to toggle item selection");
	mvprintw(LINES - 2, 0, "Press <enter> to see selected items(F1 to exit)");
	attroff(COLOR_PAIR(2));
	refresh();

	post_menu(menu);
	wrefresh(menu_win);

	int ch;
	while ((ch = wgetch(menu_win)) != KEY_F(1)) {
		switch (ch) {
			case KEY_DOWN:
				menu_driver(menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(menu, REQ_UP_ITEM);
				break;
			case ' ':
				menu_driver(menu, REQ_TOGGLE_ITEM);
				break;
			case 10:
				{
					char temp[1024];
					ITEM** titems;

					temp[0] = '\0';
					titems = menu_items(menu);
					for (int i = 0; i < item_count(menu); ++i) {
						if (item_value(titems[i]) == TRUE) {
							strncat(temp, item_name(titems[i]), strlen(item_name(titems[i])));
							strncat(temp, " ", 1);
						}
					}
					move(20, 0);
					clrtoeol();
					mvprintw(20, 0, temp);
					refresh();
				}
				break;
		}
	}

	for (int i = 0; i < item_count(menu); ++i)
		free_item(items[i]);
	free_menu(menu);
	delwin(menu_win);

	endwin();
	return 0;
}