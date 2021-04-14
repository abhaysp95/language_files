#include "../inc/gameutil.hpp"

namespace game {
	static int count{0};
	Player::Player() {
		this->id_ = ++count;
		this->chance_done_ = false;
	}
	int Player::get_id() const { return this->id_; }
	void Player::set_chance_done() { chance_done_ = !chance_done_; }
	bool Player::get_chance_done() const { return this->chance_done_; }

	void Player::set_sign(char sign) { this->sign_ = sign; }
	char Player::get_sign() const { return this->sign_; }

	Matrix::Matrix(int size):values_(size, std::vector<char>(size)) {}
	void Matrix::print_Matrix() {
		for (int i = 0; i < (2 * MAT_COUNT) - 1; ++i) {
			for (int j = 0; j < (2 * MAT_COUNT) - 1; ++j) {
				if (i % 2 == 0) {
					if (j % 2 == 1) {
						std::cout << '|';
					}
					else {
						std::cout << ' ';
					}
				}
				else {
					if (j % 2 == 0) {
						std::cout << '-';
					}
					else {
						std::cout << '+';
					}
				}
			}
			std::cout << "\n";
		}
	}
	void Matrix::insert_values(int x, int y, char sign) {
		this->values_[x - 1][y - 1] = sign;
	}
	std::vector<std::vector<char>> Matrix::see_matrix() const {
		return this->values_;
	}
};



/*

all consecutive j for any one i are same:
0 0, 0 1, 0 2 or
1 0, 1 1, 1 2 or
2 0, 2 1, 2 2

all consecutive i for any one j are same


   */