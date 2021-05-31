// main file

#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "file1.txt"

char** data;

int read_file();
void free_data(int len);
void print_to_window(WINDOW* win, int len);

int main(int argc, char **argv) {

	int slen = read_file();
	if (slen == -1)
		return -1;

	WINDOW* win;

	initscr();
	cbreak();
	noecho();

	win = newwin(10, 50, 4, 4);
	box(win, 0, 0);
	keypad(win, TRUE);
	refresh();

	/*mvwprintw(win, 4, 4, "Hello");*/
	print_to_window(win, slen);
	wrefresh(win);

	delwin(win);
	endwin();

	free_data(slen);

	return 0;
}

int read_file() {
	int fd;
	fd = open(FILENAME, O_RDONLY);

	if (fd == -1) {
		fprintf(stderr, "Can't open file\n");
		return -1;
	}

	int sen_count = 1;
	data = (char**)malloc(sizeof(char*) * sen_count);

	int cc = 0;
	char* sen = (char*)malloc(sizeof(char) * 4096);

	char ch;
	while (read(fd, &ch, 1)) {
		if (ch == '.')
			ch = '\n';
		sen[cc++] = ch;
		if (ch == '\n') {
			/*lseek(fd, 1, SEEK_CUR);*/
			sen[cc] = '\0';
			data[sen_count - 1] = (char*)malloc(sizeof(char) * strlen(sen));
			strncpy(data[sen_count - 1], sen, strlen(sen));
			cc = 0;
			data = realloc(data, (++sen_count) * sizeof(char*));
		}
	}
	sen_count--;

	free(sen);

	/*for (int i = 0; i < sen_count; ++i) {*/
		/*printf("%s", data[i]);*/
		/*free(data[i]);*/
	/*}*/

	close(fd);
	return sen_count;
}

void free_data(int len) {
	for (int i = 0; i < len; ++i)
		free(data[i]);
	free(data);
}

void data_for_window(WINDOW* win, int lineno, int totalline) {
	int maxx, maxy, startx, starty;
	getmaxyx(win, maxy, maxx);
	getbegyx(win, starty, startx);

	int winline = 1;
	int x = 4;
	if (lineno < totalline) {
		for (int i = lineno; i < totalline; ++i) {
			if (winline == maxy - 1)
				break;
			mvwprintw(win, winline++, 1, data[i]);
			mvprintw(LINES - 4, x, "x: %d", strlen(data[i]));
			x += 2;
		}
	}
}

void print_to_window(WINDOW* win, int len) {
	int maxx, maxy, startx, starty;
	getmaxyx(win, maxy, maxx);
	getbegyx(win, starty, startx);

	/*data_for_window(win, 0, len);*/

	int ch;
	int count = 0;
	mvprintw(LINES - 3, 4, "count: %d", count);
	mvprintw(LINES - 2, 4, "len: %d", len);
	while ((ch = wgetch(win)) != KEY_F(1)) {
		switch (ch) {
			case KEY_DOWN:
				if (count <= (len - maxy + 1)) {
					count++;
					data_for_window(win, count, len);
				}
				break;
			case KEY_UP:
				if (count > 0) {
					count--;
					/*data_for_window(win, count, len);*/
				}
				break;
		}
		mvprintw(LINES - 2, 4, "count: %d", count);
		refresh();
	}
}
