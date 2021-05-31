// main file

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include <menu.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 4

char* choices[] = {
	"Choice 1",
	"Choice 2",
	"Choice 3",
	"Choice 4",
	"Exit"
};

int main(int argc, char **argv) {
	ITEM** my_items;
	MENU* my_menu;
	int n_choices;
	/*ITEM* cur_item;*/

	initscr();
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);

	n_choices = ARRAY_SIZE(choices);
	my_items = (ITEM**)calloc(n_choices + 1, sizeof(ITEM*));

	for (int i = 0; i < n_choices; ++i)
		my_items[i] = new_item(choices[i], choices[i]);
	my_items[n_choices] = (ITEM*)NULL;

	my_menu = new_menu((ITEM**)my_items);

	mvprintw(LINES - 2, 0, "F1 to Exit!!!");
	post_menu(my_menu);
	refresh();

	int ch;

	while ((ch = getch()) != KEY_F(1)) {
		switch (ch) {
			case KEY_DOWN:
				menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				break;
		}
	}

	free_item(my_items[0]);
	free_item(my_items[1]);
	free_item(my_items[2]);
	endwin();
	return 0;
}