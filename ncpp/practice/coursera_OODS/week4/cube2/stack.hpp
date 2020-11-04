#pragma once

#include <vector>
#include "uiuc/cube.hpp"

class Stack {
	public:
		void push_back(const uiuc::Cube& cube);
		uiuc::Cube removeTop();
		uiuc::Cube& peekTop();
		unsigned size() const;

		/* An overloaded operator <<, allowing us to print the stack
		 * via `cout << `: */
		friend std::ostream& operator<<(std::ostream& os, const Stack& stack);

	private:
		std::vector<uiuc::Cube> cubes_;
};
