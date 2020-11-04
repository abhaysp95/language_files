#include "game.hpp"
#include "stack.hpp"
#include "uiuc/cube.hpp"
#include "uiuc/HSLAPixel.hpp"

void Game::solve() {
	move_(0, stacks_[0].size() - 1, stacks_[0], stacks_[2], stacks_[1], 0);
}

Game::Game() {
	// create three empty stacks
	for (int i = 0; i < 3; ++i) {
		Stack stackOfCubes;
		stacks_.push_back(stackOfCubes);
		std::cout << "sizeof pushed stack: " << sizeof(stackOfCubes) << std::endl;
	}

	std::cout << "sizeof(stacks_): " << sizeof(stacks_) << ", " << stacks_.size() << std::endl;

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


void Game::moveCube_(Stack& s1, Stack& s2) {
	s2.push_back(s1.removeTop());
}

void Game::move_(unsigned start, unsigned end, Stack& source, Stack& target, Stack& spare, unsigned depth) {
	std::cout << "Planning (depth = " << depth++ << "): Move [" << start << ".." << end << "] from Stack@" << &source << " -> Stack@" << &target << ", Spare@" << &spare << std::endl;
	// check if we are only moving one cube
	if (start == end) {
		moveCube_(source, target);
		std::cout << *this << std::endl;
	}
	else {
		// otherwise, move according to strategy(recursive)
		move_(start + 1, end, source, spare, target, depth);
		move_(start, start, source, target, spare, depth);
		move_(start + 1, end, spare, target, source, depth);
	}
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
