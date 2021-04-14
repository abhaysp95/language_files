#ifndef TIK_TAK_TOE_HPP
#define TIK_TAK_TOE_HPP

#include <iostream>
#include <vector>
#define MAT_COUNT 3

namespace game {
	class Matrix {
		private:
			std::vector<std::vector<char>> values_;
		public:
			Matrix(int size);
			void print_Matrix();
			void insert_values(int x, int y, char sign);
			std::vector<std::vector<char>> see_matrix() const;
	};

	class Player {
		private:
			int id_;
			bool chance_done_;
			char sign_;
		public:
			Player();
			int get_id() const;
			void set_chance_done();
			bool get_chance_done() const;
			void set_sign(char sign);
			char get_sign() const;
	};
};

#endif