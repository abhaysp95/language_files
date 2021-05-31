// main file

#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

char* data[] = {
	"supposed to a data 1",
	"supposed to a data 2",
	"supposed to a data 3",
	"supposed to a data 4",
	"supposed to a data 5",
	"supposed to a data 6",
	"supposed to a data 7",
	"supposed to a data 8",
	"supposed to a data 9",
	"supposed to a data 10",
	"supposed to a data 11",
	"supposed to a data 12",
	"supposed to a data 13",
	"supposed to a data 14",
	"supposed to a data 15",
	"supposed to a data 16",
	"supposed to a data 17",
	"supposed to a data 18",
	"supposed to a data 19",
	"supposed to a data 20",
	"supposed to a data 21",
	"supposed to a data 22",
	"supposed to a data 23",
	"supposed to a data 24",
	"supposed to a data 25",
	"supposed to a data 26",
	"supposed to a data 27",
	"supposed to a data 28",
	"supposed to a data 29",
	"supposed to a data 30",
	"supposed to a data 31",
	"supposed to a data 32",
	"supposed to a data 33",
	"supposed to a data 34",
	"supposed to a data 35",
	"supposed to a data 36",
	"supposed to a data 37",
	"supposed to a data 38",
	"supposed to a data 39",
	"supposed to a data 40",
	"supposed to a data 41",
	"supposed to a data 42",
	"supposed to a data 43",
	"supposed to a data 44",
	"supposed to a data 45",
	"supposed to a data 46",
	"supposed to a data 47",
	"supposed to a data 48",
	"supposed to a data 49",
	"supposed to a data 50",
	"supposed to a data 51",
	"supposed to a data 52",
	"supposed to a data 53",
	"supposed to a data 54",
	"supposed to a data 55",
	"supposed to a data 56",
	"supposed to a data 57",
	"supposed to a data 58",
	"supposed to a data 59",
	"supposed to a data 60",
	"supposed to a data 61",
	"supposed to a data 62",
	"supposed to a data 63",
	"supposed to a data 64",
	"supposed to a data 65",
	"supposed to a data 66",
	"supposed to a data 67",
	"supposed to a data 68",
	"supposed to a data 69",
	"supposed to a data 70",
	"supposed to a data 71",
	"supposed to a data 72",
	"supposed to a data 73",
	"supposed to a data 74",
	"supposed to a data 75",
	"supposed to a data 76",
	"supposed to a data 77",
	"supposed to a data 78",
	"supposed to a data 79",
	"supposed to a data 80",
	"supposed to a data 81",
	"supposed to a data 82",
	"supposed to a data 83",
	"supposed to a data 84",
	"supposed to a data 85",
	"supposed to a data 86",
	"supposed to a data 87",
	"supposed to a data 88",
	"supposed to a data 89",
	"supposed to a data 90",
	"supposed to a data 91",
	"supposed to a data 92",
	"supposed to a data 93",
	"supposed to a data 94",
	"supposed to a data 95",
	"supposed to a data 96",
	"supposed to a data 97",
	"supposed to a data 98",
	"supposed to a data 99",
	"supposed to a data 100",
	"supposed to a data 101",
};

int main(int argc, char **argv) {
	initscr();

	int n_choices = ARRAY_SIZE(data);
	WINDOW* pad = newpad(n_choices + 1, COLS);

	keypad(pad, TRUE);

	wprintw(pad, "Panel Heading\n");

	int count = 0;
	while (count < n_choices) {
		wprintw(pad, data[count++]);
		wprintw(pad, "\n");
	}

	int mypadpos = 0;
	prefresh(pad, mypadpos, 0, 0, 0, LINES - 1, COLS - 1);


	int ch;
	while ((ch = wgetch(pad)) != 'q') {
		switch (ch) {
			case KEY_UP:
				if (mypadpos >= 0)
					mypadpos--;
				prefresh(pad, mypadpos, 0, 0, 0, LINES - 1, COLS - 1);
				break;
			case KEY_DOWN:
				if (mypadpos <= n_choices - LINES)
					mypadpos++;
				prefresh(pad, mypadpos, 0, 0, 0, LINES - 1, COLS - 1);
				break;
		}
	}

	delwin(pad);
	clear();
	refresh();

	endwin();
	return 0;
}