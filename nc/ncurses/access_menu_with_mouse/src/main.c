// main file

#include <stdio.h>
#include <string.h>
#include <ncurses.h>

#define WIDTH 30
#define HEIGHT 10

int startx = 0;
int starty = 0;

char* choices[] = {
	"Choice 1",
	"Choice 2",
	"Choice 3",
	"Choice 4",
	"Exit"
};

int n_choices = sizeof(choices) / sizeof(char*);
void print_menu(WINDOW* menu_win, int hightlight);
void report_choice(int mouse_x, int mouse_y, int* p_choice);

int main(int argc, char **argv) {
	WINDOW* menu_win;
	MEVENT event;

	int highlight = 1;
	int choice = 0;
	int c;

	initscr();
	clear();
	noecho();
	cbreak();
	startx = (80 - WIDTH) / 2;
	starty = (24 - HEIGHT) / 2;

	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menu_win, TRUE);
	mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
	mvprintw(1, 0, "Click of Exit to quit(Works best in a virtual console)");
	refresh();
	print_menu(menu_win, highlight);

	mousemask(ALL_MOUSE_EVENTS, NULL);

	while (1) {
		c = wgetch(menu_win);
		switch (c) {
			case KEY_UP:
				if (highlight == 1)
					highlight = n_choices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if (highlight == n_choices)
					highlight = 1;
				else
					++highlight;
				break;
			case KEY_MOUSE:
				if (getmouse(&event) == OK) {
					// when the user clicks the left mouse button
					if (event.bstate & BUTTON1_PRESSED)
						report_choice(event.x + 1, event.y + 1, &choice);
				}
				break;
			case 10:
				choice = highlight;
				break;
			default:
				mvprintw(24, 0, "Character pressed is = %3d");
				refresh();
				break;
		}
		print_menu(menu_win, highlight);
		if (choice != 0)
			break;
	}
	if(choice >= 0) {
		mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
		getch();
	}
	clrtoeol();  // The erase and werase routines copy blanks to every position in the window, clearing the screen
	refresh();
	endwin();
	return 0;
}

void print_menu(WINDOW* menu_win, int highlight) {
	int x, y, i;
	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	for (i = 0; i < n_choices; ++i) {
		if (highlight == i + 1) {
			wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
}

void report_choice(int mouse_x, int mouse_y, int* p_choice) {
	int i, j, choice;
	i = startx + 2;
	j = starty + 3;

	for (choice = 0; choice < n_choices; ++choice)
		if (mouse_y == j + choice && mouse_x >= i && mouse_x <= i + strlen(choices[choice])) {
			if (choice == n_choices - 1)
				*p_choice = -1;
			else
				*p_choice = choice + 1;
			break;
		}
	printf("p_choice is: %d\n", *p_choice);
}