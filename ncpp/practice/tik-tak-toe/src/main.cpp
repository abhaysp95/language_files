// main file

#include <iostream>
#include <limits>
#include <vector>
#include "../inc/gameutil.hpp"

void start_game(game::Player& player1, game::Player& player2);
int check_matrix(game::Player& player_chance, game::Matrix& matrix);

int check_matrix(game::Player& player_chance, game::Matrix& matrix) {
	for (int i = 0; i < MAT_COUNT; ++i) {
		int count{0};
		for (int j = 0; j < MAT_COUNT; ++j) {
			if (matrix.see_matrix()[i][j] == player_chance.get_sign()) {
				count++;
			}
			if (count == 3) {
				return player_chance.get_id();
			}
			else {
				if (count == 0) {
					break;
				}
			}
		}
	}
	for (int i = 0; i < MAT_COUNT; ++i) {
		int count{0};
		for (int j = 0; j < MAT_COUNT; ++j) {
			if (matrix.see_matrix()[j][i] == player_chance.get_sign()) {
				count++;
			}
			if (count == 3) {
				return player_chance.get_id();
			}
			else {
				if (count == 0) {
					break;
				}
			}
		}
	}
	for (int i = 0; i < MAT_COUNT; ++i) {
		int count{0};
		for (int j = 0; j < MAT_COUNT; ++j) {
			if ((i == j) || (i == MAT_COUNT - (j + 1))) {
				if (matrix.see_matrix()[i][j] == player_chance.get_sign()) {
					count++;
				}
			}
			if (count == 3) {
				return player_chance.get_id();
			}
			else {
				if (count == 0) {
					return 0;
				}
			}
		}
	}
	return 0;
}

void start_game(game::Player& player1, game::Player& player2) {
	game::Matrix matrix(MAT_COUNT);
	game::Player player_chance;
	player_chance = player1.get_chance_done() ? player1 : player2;
	while (true) {
		int x, y;
		std::cout << "Player " << player_chance.get_id() << " chance[sign '" << player_chance.get_sign() << "']" << std::endl;
		while(true) {
			std::cout << "Enter the position in matrix[3x3]: ";
			std::cin >> x >> y;
			if ((x > MAT_COUNT || x < 0) || (y > MAT_COUNT || y < 0)) {
				std::cout << "Enter x and y greater than 0 and less than equals to " << MAT_COUNT << std::endl;
			}
			else {
				break;
			}
		}
		matrix.insert_values(x, y, player_chance.get_sign());
		int result = check_matrix(player_chance, matrix);
		if (result == 1) {
			std::cout << "Player" << player_chance.get_id() << " is WINNER!" << std::endl;
			break;
		}
		else if (result == 2) {
			std::cout << "Player" << player_chance.get_id() << " is WINNER!" << std::endl;
			break;
		}
	}
}

int main(int argc, char **argv) {
	srand(time(0));
	int player_chance;
	char sign;
	std::cout << "Enter the player chance or press 'y' to generate the chance randomly[else 1 or 2]: ";
	std::cin >> player_chance;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		player_chance = (rand() % 2) + 1;
	}
	std::cout << "Player " << player_chance << " chance" << std::endl;
	game::Player player1, player2;
	if (player_chance == 1) {
		player1.set_chance_done();
		std::cout << "Choose the sign[o or x]: ";
		std::cin >> sign;
		player1.set_sign(sign);
		player2.set_sign((sign == 'x' ? 'o' : 'x'));
	}
	else {
		player2.set_chance_done();
		std::cout << "Choose the sign[o or x]: ";
		std::cin >> sign;
		player2.set_sign(sign);
		player1.set_sign((sign == 'x' ? 'o' : 'x'));
	}
	std::cout << "Player's sign: player1: " << player1.get_sign() << ", player2: " << player2.get_sign() << std::endl;
	start_game(player1, player2);
	return 0;
}