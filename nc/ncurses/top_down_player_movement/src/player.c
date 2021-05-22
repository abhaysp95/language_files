// c file for "player.h"

#include "../inc/player.h"

Player init_player(WINDOW* win, int x, int y, chtype c) {
	Player aplayer;
	aplayer.curwin = win;
	aplayer.character = c;
	aplayer.x_loc = x;
	aplayer.y_loc = y;
	getmaxyx(aplayer.curwin, aplayer.y_max, aplayer.x_max);
	return aplayer;
}

void player_move(Player* player, int choice) {
	/*init_color(COLOR_YELLOW, 850, 800, 100);*/
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	chtype tdot = '.' | COLOR_PAIR(1);
	switch (choice) {
		case KEY_UP:
			player_move_up(player, tdot);
			break;
		case KEY_DOWN:
			player_move_down(player, tdot);
			break;
		case KEY_LEFT:
			player_move_left(player, tdot);
			break;
		case KEY_RIGHT:
			player_move_right(player, tdot);
			break;
		default:
			break;
	}
}

void player_move_up(Player* player, chtype trail) {
	mvwaddch(player->curwin, player->y_loc, player->x_loc, '.');
	player->y_loc--;
	if (player->y_loc < 1)
		player->y_loc = 1;
}

void player_move_down(Player* player, chtype trail) {
	mvwaddch(player->curwin, player->y_loc, player->x_loc, '.');
	player->y_loc++;
	if (player->y_loc > player->y_max - 2)
		player->y_loc = player->y_max - 2;
}

void player_move_left(Player* player, chtype trail) {
	mvwaddch(player->curwin, player->y_loc, player->x_loc, '.');
	player->x_loc--;
	if (player->x_loc < 1)
		player->x_loc = 1;
}

void player_move_right(Player* player, chtype trail) {
	mvwaddch(player->curwin, player->y_loc, player->x_loc, '.');
	player->x_loc++;
	if (player->x_loc > player->x_max - 2)
		player->x_loc = player->x_max - 2;
}

void display_player(Player* player) {
	mvwaddch(player->curwin, player->y_loc, player->x_loc,
			player->character);
}