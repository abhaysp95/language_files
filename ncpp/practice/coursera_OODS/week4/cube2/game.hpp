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
		void moveCube_(Stack& s1, Stack& s2);
		void move_(unsigned start, unsigned end, Stack& source, Stack& target, Stack& spare, unsigned depth);
};
