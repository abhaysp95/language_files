// main file

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>

#define FILENAME "input.txt"

char** data;

typedef struct _win_border_struct {
	chtype ls, rs, ts, bs, tl, bl, tr, br;
} WIN_BORDER;

typedef struct _win_struct {
	WINDOW* win;
	int startx, starty;
	int endx, endy;
	WIN_BORDER border;
} WIN;

void init_pad(WIN* win, int pheight, int pwidth);
void create_box(WIN* win);

int main(int argc, char **argv) {
	WIN pad;
	int fd;
	fd = open(FILENAME, O_RDONLY);

	if (fd == -1) {
		fprintf(stderr, "Can't open file\n");
		return -1;
	}

	int slen = 1;
	data = (char**)malloc(sizeof(char*) * slen);

	int cc = 0;
	char* sen = (char*)malloc(sizeof(char) * 4096);

	char ch;
	while (read(fd, &ch, 1)) {
		if (ch == '.') {
			ch = '\n';
			lseek(fd, 1, SEEK_CUR);
		}
		if (sen == NULL)
			sen = (char*)malloc(sizeof(char) * 4096);
		sen[cc++] = ch;
		if (ch == '\n') {
			sen[cc] = '\0';
			data[slen - 1] = (char*)malloc(sizeof(char) * (strlen(sen) + 1));
			strncpy(data[slen - 1], sen, strlen(sen) + 1);
			/*printf("%s", data[slen - 1]);*/
			cc = 0;
			data = realloc(data, (++slen) * sizeof(char*));
			free(sen);
			sen = NULL;
		}
	}
	slen--;

	free(sen);
	sen = NULL;
	initscr();
	cbreak();
	curs_set(0);

	char* head = "This is a pad with smaller view";
	mvprintw(2, (COLS - strlen(head)) / 2, head);
	refresh();

	/*pad.win = newpad(slen + 1, COLS + 100);*/
	init_pad(&pad, slen + 1, COLS + 100);
	keypad(pad.win, TRUE);
	create_box(&pad);

	for (int i = 0; i < slen; ++i) {
		wprintw(pad.win, data[i]);
		free(data[i]);
	}
	free(data);

	int rpos = 0;
	int cpos = 0;
	prefresh(pad.win, rpos, cpos, 5, 10, LINES - 5, COLS - 10);

	int c;
	while ((c = wgetch(pad.win)) != 'q') {
		switch (c) {
			case KEY_UP:
				if (rpos > 0)
					rpos--;
				prefresh(pad.win, rpos, cpos, 5, 10, LINES - 5, COLS - 10);
				break;
			case KEY_DOWN:
				if (rpos <= slen - LINES)
					rpos++;
				prefresh(pad.win, rpos, cpos, 5, 10, LINES - 5, COLS - 10);
				break;
			case KEY_LEFT:
				if (cpos > 4)
					cpos -= 4;
				else
					if (cpos > 0)
						cpos = 0;
				prefresh(pad.win, rpos, cpos, 5, 10, LINES - 5, COLS - 10);
				break;
			case KEY_RIGHT:
				if (cpos <= 500) {
					cpos += 4;
				}
				prefresh(pad.win, rpos, cpos, 5, 10, LINES - 5, COLS - 10);
				break;
		}
	}

	delwin(pad.win);
	endwin();
	return 0;
}

void init_pad(WIN* win, int pheight, int pwidth) {
	win->win = newpad(pheight, pwidth);
	/** have atleast one row and column space more than you want to view with pad */
	win->startx = 9;
	win->starty = 4;
	win->endx = COLS - 9;
	win->endy = LINES - 4;

	win->border.ts = ACS_HLINE;
	win->border.bs = ACS_HLINE;
	win->border.ls = ACS_VLINE;
	win->border.rs = ACS_VLINE;
	win->border.tl = ACS_ULCORNER;
	win->border.tr = ACS_URCORNER;
	win->border.bl = ACS_LLCORNER;
	win->border.br = ACS_LRCORNER;
}

void create_box(WIN* win) {
	int x, y, w, h;

	x = win->startx;
	y = win->starty;
	w = win->endx - x;
	h = win->endy - y;

	mvaddch(y, x, win->border.tl);
	mvaddch(y, x + w, win->border.tr);
	mvaddch(y + h, x, win->border.bl);
	mvaddch(y + h, x + w, win->border.br);
	mvhline(y, x + 1, win->border.ts, w - 1);
	mvhline(y + h, x + 1, win->border.bs, w - 1);
	mvvline(y + 1, x, win->border.ls, h - 1);
	mvvline(y + 1, x + w, win->border.rs, h - 1);
	refresh();
}