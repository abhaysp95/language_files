// main file

#include <stdio.h>
#include <panel.h>

int main(int argc, char **argv) {
	WINDOW* wins[3];
	PANEL* panels[3];

	int lines = 10, cols = 40, y = 2, x = 4;

	initscr();
	cbreak();
	noecho();

	wins[0] = newwin(lines, cols, y, x);
	wins[1] = newwin(lines, cols, y + 1, x + 10);
	wins[2] = newwin(lines, cols, y + 2, x + 20);

	for (int i = 0; i < 3; ++i)
		box(wins[i], 0, 0);

	for (int i = 0; i < 3; ++i) {
		int x_beg, y_beg;
		getbegyx(wins[i], y_beg, x_beg);
		mvwprintw(wins[i], y_beg, x_beg, "this");
	}


	// attach a panel to each window
	panels[0] = new_panel(wins[0]);
	panels[1] = new_panel(wins[1]);
	panels[2] = new_panel(wins[2]);

	update_panels();

	doupdate();

	getch();
	endwin();

	return 0;
}