// header file
#ifndef _GUARD_PLAYER_H_
#define _GUARD_PLAYER_H_

#include <ncurses.h>

typedef struct player {
	int x_loc, y_loc, x_max, y_max;
	chtype character;
	WINDOW* curwin;
} Player;

Player init_player(WINDOW* win, int x, int y, chtype c);

void player_move(Player* player, int choice);

void player_move_up(Player* player, chtype trail);
void player_move_down(Player* player, chtype trail);
void player_move_left(Player* player, chtype trail);
void player_move_right(Player* player, chtype trail);

void display_player(Player* player);
#endif