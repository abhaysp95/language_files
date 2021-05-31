// main file

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include <panel.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char* pad_names[] = {
	"[first]",
	"[second]",
	"[third]"
};

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

typedef struct _data_info {
	char** data;
	int size;
} DATA;

char* filenames[] = {
	"input1.txt",
	"input2.txt",
	"input3.txt"
};

typedef struct _win_border_struct {
	chtype ls, rs, ts, bs, tl, bl, tr, br;
} WIN_BORDER;

typedef struct _win_struct {
	WINDOW* win;
	int startx, starty;
	int endx, endy;
	int rpos, cpos;
	WIN_BORDER border;
} WIN;

void read_data(DATA* data, char* filename);
void print_data(DATA* data);
void init_pads(WIN* pad, DATA* data);
void init_win_data(WIN* win, int pheight, int pwidth, DATA* data);
void init_win_label(WIN* win, int pheight, int pwidth, char* label);
void create_box(WIN* win);
void print_pad_names(WIN* pad, int cur_pad_num);
void free_data(DATA* data);

int main(int argc, char **argv) {
	DATA data[3];

	for (int i = 0; i < 3; ++i)
		read_data(&data[i], filenames[i]);

	/*for (int i = 0; i < 3; ++i) {
		printf("Printing %s:\n", filenames[i]);
		print_data(&data[i]);
	}*/

	WIN pad[3];
	PANEL* panels[3];
	PANEL* top;
	/*WIN* top_pad;*/

	initscr();
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);

	char* head = "This is a pad with smaller view";
	mvprintw(2, (COLS - strlen(head)) / 2, head);
	refresh();

	init_pads(pad, data);

	panels[0] = new_panel(pad[2].win);
	panels[1] = new_panel(pad[1].win);
	panels[2] = new_panel(pad[0].win);

	top = panels[0];
	prefresh(pad[0].win, pad[0].rpos, pad[0].cpos, pad[0].starty + 1,
			pad[0].startx + 1, pad[0].endy - 1, pad[0].endx - 1);

	set_panel_userptr(panels[0], panels[1]);
	set_panel_userptr(panels[1], panels[2]);
	set_panel_userptr(panels[2], panels[0]);

	/** check if we can set mulitple panel_userptr for same panel */
	/*set_panel_userptr(panels[0], &pad[0]);*/
	/*set_panel_userptr(panels[1], &pad[1]);*/
	/*set_panel_userptr(panels[2], &pad[2]);*/

	top_panel(panels[1]);

	update_panels();
	doupdate();

	/*getch();*/

	mvprintw(LINES - 1, 4, "Press <tab> and <\\> key for tab cycle, and arrow keys to scroll(vertical and horizontal)[press 'q' to exit]");
	refresh();


	int ch = 0;
	int cur_pad = 0;
	char info[1024];
	sprintf(info, "key_pressed: %d, cur_pad: %d, rpos: %d, cpos: %d", ch, cur_pad, pad[cur_pad].rpos, pad[cur_pad].cpos);
	move(LINES - 2, 4);
	clrtoeol();
	mvprintw(LINES - 2, 4, info);

	while ((ch = getch()) != 'q') {
		switch (ch) {
			case 9:
				/*move(LINES - 2, 4);*/
				/*clrtoeol();*/
				/*mvprintw(LINES - 2, 4, "tab");*/
				top = (PANEL*)panel_userptr(top);
				top_panel(top);
				if (cur_pad == 2)
					cur_pad = 0;
				else
					cur_pad++;
				// mvprintw(LINES - 2, 4, "%d", cur_pad);
				break;
			case 92:
				/*move(LINES - 2, 4);*/
				/*clrtoeol();*/
				/*mvprintw(LINES - 2, 4, "enter");*/
				top = (PANEL*)panel_userptr(top);
				bottom_panel(top);
				if (cur_pad == 0)
					cur_pad = 2;
				else
					cur_pad--;
				break;
			case KEY_UP:
				if (pad[cur_pad].rpos > 0)
					pad[cur_pad].rpos--;
				break;
			case KEY_DOWN:
				if (pad[cur_pad].rpos <= (data[cur_pad].size - (pad[cur_pad].endy - pad[cur_pad].starty)))
					pad[cur_pad].rpos++;
				break;
			case KEY_LEFT:
				if (pad[cur_pad].cpos > 0)
					pad[cur_pad].cpos--;
				break;
			case KEY_RIGHT:
				if (pad[cur_pad].cpos < 200)
					pad[cur_pad].cpos++;
				break;
		}
		prefresh(pad[cur_pad].win, pad[cur_pad].rpos, pad[cur_pad].cpos, pad[cur_pad].starty + 1,
				pad[cur_pad].startx + 1, pad[cur_pad].endy - 1, pad[cur_pad].endx - 1);
		print_pad_names(pad, cur_pad);
		sprintf(info, "key_pressed: %d, cur_pad: %d, rpos: %d, cpos: %d", ch, cur_pad, pad[cur_pad].rpos, pad[cur_pad].cpos);
		move(LINES - 2, 4);
		clrtoeol();
		mvprintw(LINES - 2, 4, info);
		refresh();
		update_panels();
		doupdate();
	}

	for (int i = 0; i < 3; i++)
		if (panels[i] != NULL)
			del_panel(panels[i]);
	for (int i = 0; i < 3; i++)
		if (pad[i].win != NULL)
			delwin(pad[i].win);
	endwin();

	free_data(data);
	return 0;
}

void read_data(DATA* data, char* filename) {
	int fd;
	fd = open(filename, O_RDONLY);

	int slen = 1;
	data->data = (char**)malloc(sizeof(char*) * slen);

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
			data->data[slen - 1] = (char*)malloc(sizeof(char) * (strlen(sen) + 1));
			strncpy(data->data[slen - 1], sen, strlen(sen) + 1);
			/*printf("%s", data[slen - 1]);*/ cc = 0;
			data->data = realloc(data->data, (++slen) * sizeof(char*));
			free(sen);
			sen = NULL;
		}
	}
	slen--;
	data->size = slen;

	free(sen);
	sen = NULL;
}

void print_data(DATA* data) {
	for (int i = 0; i < data->size; i++)
		printf("%s", data->data[i]);
}

/** second param to be only used for init_win_data() */
void init_pads(WIN* pad, DATA* data) {
	/*char label[12];*/
	for (int i = 0; i < 3; i++) {

		/*sprintf(label, "Window: %d", i + 1);*/
		/*init_win_label(pad + i, 150, 150, label);*/

		init_win_data(pad + i, (data + i)->size, 200, (data + i));

		keypad(pad[i].win, TRUE);
		prefresh(pad[i].win, 0, 0, pad[i].starty + 1, pad[i].startx + 1, pad[i].endy - 1, pad[i].endy - 1);
	}
	print_pad_names(pad, 0);
}

void init_win_data(WIN* win, int pheight, int pwidth, DATA* data) {
	win->win = newpad(pheight, pwidth);
	keypad(win->win, TRUE);
	/** have atleast one row and column space more than you want to view with pad */
	win->startx = 9;
	win->starty = 4;
	win->endx = COLS - 9;
	win->endy = LINES - 4;
	win->rpos = 0;
	win->cpos = 0;

	win->border.ts = ACS_HLINE;
	win->border.bs = ACS_HLINE;
	win->border.ls = ACS_VLINE;
	win->border.rs = ACS_VLINE;
	win->border.tl = ACS_ULCORNER;
	win->border.tr = ACS_URCORNER;
	win->border.bl = ACS_LLCORNER;
	win->border.br = ACS_LRCORNER;

	create_box(win);
	for (int i = 0; i < data->size; i++) {
		wprintw(win->win, data->data[i]);
	}
}

void init_win_label(WIN* win, int pheight, int pwidth, char* label) {
	win->win = newpad(pheight, pwidth);
	keypad(win->win, TRUE);
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

	create_box(win);
	int x = (win->endx - win->startx);
	int y = (win->endy - win->starty);
	mvwprintw(win->win, y / 2, (x - strlen(label)) / 2, label);
	prefresh(win->win, win->rpos, win->cpos, win->starty + 1, win->startx + 1, win->endy - 1, win->endx - 1);
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

void print_pad_names(WIN* pad, int cur_pad_num) {
	WIN* win = &pad[0];  // just for ease

	int n = ARRAY_SIZE(pad_names);
	refresh();
	int d = 4;
	int y = win->starty + (win->endy - win->starty);
	int x = win->startx + d;
	for (int i = 0; i < n; i++) {
		/*mvprintw(LINES - 1, 4, "%d", n);*/
		if (i == cur_pad_num)
			attron(A_REVERSE);
		mvaddstr(y, x, pad_names[i]);
		if (i == cur_pad_num)
			attroff(A_REVERSE);
		x += (strlen(pad_names[i]) + d);
	}
	refresh();
}

void free_data(DATA* data) {
	if (data == NULL)
		return;
	for (int i = 0; i < 3; i++) {
		if ((data + i)->data != NULL) {
			for (int j = 0; j < (data + i)->size; j++)
				if ((data + i)->data[j] != NULL)
					free((data + i)->data[j]);
		}
	}
}