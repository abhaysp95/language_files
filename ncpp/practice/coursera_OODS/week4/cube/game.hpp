#pragma once

#include "stack.hpp"
#include <vector>

class Game {
	public:
		Game();
		void solve();
		friend std::ostream& operator<<(std::ostream& os, const Game& game);

	private:
		std::vector<Stack> stacks_;
		void legalMove_(unsigned index1, unsigned index2);
		void move_(unsigned index1, unsigned index2);
};
