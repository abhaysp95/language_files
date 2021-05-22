// main file

#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

typedef struct menu {
	char* name;
	int num_items;
	int selected_item;
	char** items;
} Menu;

typedef struct menu_list {
	WINDOW* win;
	WINDOW* menu_win;
	Menu* m_lst;
	int menu_nums;
	int selected_menu;
} MenuList;

// to add more menus, just change these arrays
const char* menu_names[] = {
	"[File]",
	"[Edit]",
	"[Option]"
};

const char* menu1_items[] = {
	"New",
	"Open",
	"Save",
	"Save As",
	"Print"
};

const char* menu2_items[] = {
	"Cut",
	"Copy",
	"Paste",
	"Undo",
	"Redo"
};

const char* menu3_items[] = {
	"About",
	"Exit"
};

const char** menu_items[] = {
	menu1_items,
	menu2_items,
	menu3_items
};

const int menu_items_sizes[] = {
	sizeof(menu1_items) / sizeof(char*),
	sizeof(menu2_items) / sizeof(char*),
	sizeof(menu3_items) / sizeof(char*)
};

void initialize_menu_list(MenuList* menu_list);
void initialize_menu_bar(MenuList* menu_list);
void initialize_menu_win(MenuList* menu_list);
void free_menu_list(MenuList* menu_list);
void print_menu(MenuList* menu_list);
void print_banner();
void select_next_item(Menu* menu);
void select_prev_item(Menu* menu);
void draw_menu_item(WINDOW* win, Menu menu);
void reset(MenuList* menu_list);



int main(int argc, char **argv) {
	MenuList menu_list;
	initialize_menu_list(&menu_list);

	initscr();
	noecho();
	curs_set(0);

	if (!has_colors()) {
		fprintf(stderr, "Your terminal doesn't support colors\n");
		return -1;
	}

	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);

	print_banner();

	initialize_menu_bar(&menu_list);

	print_menu(&menu_list);

	char ch;
	while ((ch = getch()) != 'x') {
		switch(ch) {
			case 'f':
				menu_list.selected_menu = 0;
				print_menu(&menu_list);
				break;
			case 'e':
				menu_list.selected_menu = 1;
				print_menu(&menu_list);
				break;
			case 'o':
				menu_list.selected_menu = 2;
				print_menu(&menu_list);
				break;
			default:
				menu_list.selected_menu = -1;
				print_menu(&menu_list);
				break;
		}
	}

	if (menu_list.win != NULL)
		delwin(menu_list.win);
	endwin();

	free_menu_list(&menu_list);
	return 0;
}

void print_banner() {
	int y_max, x_max;
	getmaxyx(stdscr, y_max, x_max);
	mvprintw(1, (x_max - 41) / 2, " __  __                  ____");
	mvprintw(2, (x_max - 41) / 2, "|  \\/  | ___ _ __  _   _| __ )  __ _ _ __");
	mvprintw(3, (x_max - 41) / 2, "| |\\/| |/ _ \\ '_ \\| | | |  _ \\ / _` | '__|");
	mvprintw(4, (x_max - 41) / 2, "| |  | |  __/ | | | |_| | |_) | (_| | |");
	mvprintw(5, (x_max - 41) / 2, "|_|  |_|\\___|_| |_|\\__,_|____/ \\__,_|_|");
	refresh();
}

void initialize_menu_list(MenuList* menu_list) {
	menu_list->menu_nums = sizeof(menu_names) / sizeof(char*);
	menu_list->m_lst = (Menu*)malloc(sizeof(Menu) * menu_list->menu_nums);
	for (int i = 0; i < menu_list->menu_nums; ++i) {
		menu_list->m_lst[i].name = (char*)malloc(sizeof(char) * 1024);
		strcpy(menu_list->m_lst[i].name, menu_names[i]);
		/*menu_list->m_lst[i].num_items = sizeof(*(menu_items[i])) / sizeof(char*);*/
		menu_list->m_lst[i].num_items = menu_items_sizes[i];
		menu_list->m_lst[i].selected_item = 0;
		menu_list->m_lst[i].items = (char**)malloc(sizeof(char*) * menu_list->m_lst[i].num_items);
		for (int j = 0; j < menu_list->m_lst[i].num_items; ++j) {
			menu_list->m_lst[i].items[j] = (char*)malloc(sizeof(char) * 1024);
			strncpy(menu_list->m_lst[i].items[j], menu_items[i][j], strlen(menu_items[i][j]));
		}
	}
	menu_list->selected_menu = -1;
}

void initialize_menu_bar(MenuList* menu_list) {
	int x_max, y_max;
	getmaxyx(stdscr, y_max, x_max);

	WINDOW* win = newwin(y_max / 2, x_max / 2, y_max/4 + 7, x_max/4);
	menu_list->win = win;
	box(win, 0, 0);
	initialize_menu_win(menu_list);
	refresh();
}

void initialize_menu_win(MenuList* menu_list) {
	int x_max, y_max, x_beg, y_beg;
	getmaxyx(menu_list->win, y_max, x_max);
	getbegyx(menu_list->win, y_beg, x_beg);
	menu_list->menu_win = newwin(y_max - 2, x_max - 2, y_beg + 1, x_beg + 1);
	keypad(menu_list->menu_win, TRUE);
	wrefresh(menu_list->menu_win);
}

void free_menu_list(MenuList* menu_list) {
	for (int i = 0; i < menu_list->menu_nums; ++i) {
		if (menu_list->m_lst[i].name != NULL)
			free(menu_list->m_lst[i].name);
		for (int j = 0; j < menu_list->m_lst[i].num_items; ++j) {
			if (menu_list->m_lst[i].items[j] != NULL)
				free(menu_list->m_lst[i].items[j]);
		}
		if (menu_list->m_lst[i].items != NULL)
			free(menu_list->m_lst[i].items);
	}
	if (menu_list->m_lst != NULL)
		free(menu_list->m_lst);
}

void print_menu(MenuList* menu_list) {
	bool is_selected = false;
	int distance = 2;
	for (int i = 0; i < menu_list->menu_nums; ++i) {
		if (menu_list->selected_menu == i) {
			wattron(menu_list->win, A_STANDOUT);
			is_selected = true;
		}
		mvwprintw(menu_list->win, 0, distance, menu_list->m_lst[i].name);
		distance += strlen(menu_list->m_lst[i].name) + 1;
		wattroff(menu_list->win, A_STANDOUT);
		wrefresh(menu_list->win);

		int ch;
		draw_menu_item(menu_list->menu_win, menu_list->m_lst[i]);
		wrefresh(menu_list->menu_win);
		while (is_selected && (ch = wgetch(menu_list->menu_win))) {
			/*printf("%d\n", ch);*/
			switch(ch) {
				case KEY_DOWN:
					select_next_item(&menu_list->m_lst[i]);
					break;
				case KEY_UP:
					select_next_item(&menu_list->m_lst[i]);
					break;
				case 10:
					{
						char* msg = (char*)malloc(sizeof(char) * 1024);
						strcpy(msg, "You selected \"");
						char* mname = menu_list->m_lst[i].name;
						strncat(msg, mname, strlen(mname));
						strncat(msg, "\" menu and [", 12);
						char* miname = menu_list->m_lst[i].items[menu_list->m_lst[i].selected_item];
						strncat(msg, miname, strlen(miname));
						strncat(msg, "] menu item!!!", 14);
						attron(COLOR_PAIR(2));
						int y_max, x_max;
						getmaxyx(stdscr, y_max, x_max);
						mvprintw(10, (x_max - strlen(msg)) / 2, msg);
						attroff(COLOR_PAIR(2));
						refresh();
						free(msg);
					}
					menu_list->m_lst[i].selected_item = 0;
					is_selected = false;
					break;
				default:
					is_selected = false;
			}
		draw_menu_item(menu_list->menu_win, menu_list->m_lst[i]);
		}
		werase(menu_list->menu_win);
		wrefresh(menu_list->menu_win);
		reset(menu_list);
	}
	menu_list->selected_menu = -1;
	wrefresh(menu_list->win);
}

void select_next_item(Menu* menu) {
	if (menu == NULL)
		return;
	menu->selected_item++;
	if (menu->selected_item >= menu->num_items)
		menu->selected_item = 0;
}

void select_prev_item(Menu* menu) {
	if (menu == NULL)
		return;
	menu->selected_item--;
	if (menu->selected_item < 0)
		menu->selected_item = menu->num_items - 1;
}

void draw_menu_item(WINDOW* win, Menu menu) {
	int y_max, x_max;
	getmaxyx(win, y_max, x_max);
	for (int i = 0; i < menu.num_items; ++i) {
		mvwprintw(win, i, 0, menu.items[i]);
		if (menu.selected_item == i) {
			// if highlighted, change to COLOR_PAIR(1)
			mvwchgat(win, i, 0, x_max, A_NORMAL, 1, NULL);
		}
		else {
			// not selected
			mvwchgat(win, i, 0, x_max, A_STANDOUT, 0, NULL);
		}
	}
}

void reset(MenuList* menu_list) {
	int distance = 2;
	for (int i = 0; i < menu_list->menu_nums; ++i) {
		mvwprintw(menu_list->win, 0, distance, menu_list->m_lst[i].name);
		distance += strlen(menu_list->m_lst[i].name) + 1;
	}
	wrefresh(menu_list->win);
}