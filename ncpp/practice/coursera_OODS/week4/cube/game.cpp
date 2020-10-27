#include "game.hpp"
#include "stack.hpp"
#include "uiuc/cube.hpp"
#include "uiuc/HSLAPixel.hpp"

void Game::solve() {
	// goal is to shift all cubes to 3rd stack
	while (stacks_[2].size() != 4) {
		legalMove_(0, 1);
		legalMove_(0, 2);
		legalMove_(1, 2);
	}
}

Game::Game() {
	// create three empty stacks
	for (int i = 0; i < 3; ++i) {
		Stack stackOfCubes;
		stacks_.push_back(stackOfCubes);
	}

	// create the four cubes, placing each on the [0]th stack:
	uiuc::Cube blue(4, uiuc::HSLAPixel::BLUE);
	stacks_[0].push_back(blue);

	uiuc::Cube orange(3, uiuc::HSLAPixel::ORANGE);
	stacks_[0].push_back(orange);

	uiuc::Cube purple(2, uiuc::HSLAPixel::ORANGE);
	stacks_[0].push_back(purple);

	uiuc::Cube yellow(1, uiuc::HSLAPixel::ORANGE);
	stacks_[0].push_back(yellow);
}

void Game::legalMove_(unsigned index1, unsigned index2) {
	if (stacks_[index1].size() == 0 && stacks_[index2].size() > 0) {
		move_(index2, index1);  // index1's will be inserted to index2's
	}
	else if (stacks_[index1].size() > 0 && stacks_[index2].size() == 0) {
		move_(index1, index2);
	}
	else if (stacks_[index1].size() > 0 && stacks_[index2].size() > 0) {
		if (stacks_[index1].peekTop().getLength() < stacks_[index2].peekTop().getLength()) {
			move_(index1, index2);
		}
		else {
			move_(index2, index1);
		}
	}
	std::cout << *this << std::endl;
}

void Game::move_(unsigned index1, unsigned index2) {
	// removeTop returns a copy of Cube, so just push_back
	stacks_[index2].push_back(stacks_[index1].removeTop());
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
	for (unsigned int i = 0; i < game.stacks_.size(); ++i) {
		os << "Stack[" << i << "]: " << game.stacks_[i];
	}
	return os;
}

/* for a four cube and 3 stack Tower of Hanoi problem the pattern would look something like this:

   0 -> 1
   0 -> 2
   1 -> 2

   0 -> 1
   0 <- 2
   1 <- 2

   0 -> 1
   0 -> 2
   1 -> 2

   0 <- 1
   0 <- 2
   1 -> 2

   0 -> 1
   0 -> 2
   1 -> 2

   No. of steps: 2^4 - 1 = 15 */
