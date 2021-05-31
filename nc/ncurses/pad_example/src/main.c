// main file

#include <stdio.h>
#include <ncurses.h>

int main(int argc, char **argv) {
	WINDOW* pad_ptr;
	int x, y;
	int pad_lines, pad_cols;
	char disp_char;

	initscr();

	pad_lines = LINES + 50;
	pad_cols = COLS + 50;

	pad_ptr = newpad(pad_lines, pad_cols);
	box(pad_ptr, 0, 0);

	disp_char = 'a';
	for (x = 0; x < pad_lines; x++) {
		for (y = 0; y < pad_cols; y++) {
			mvwaddch(pad_ptr, x, y, disp_char);
			if (disp_char == 'z')
				disp_char = 'a';
			else
				disp_char++;
		}
	}

	/*prefresh(pad_ptr, 0, 0, 3, 3, 9+3, 9+3);*/
	prefresh(pad_ptr, 0, 0, 0, 0, LINES, COLS);

	getch();
	delwin(pad_ptr);

	endwin();
	return 0;
}