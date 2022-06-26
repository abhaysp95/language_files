#include "box.hpp"
#include "carton.hpp"
#include "cerealpack.hpp"

#include <iostream>
#include <vector>
#include <memory>

#define SEP "--------------"

int main(void) {
	Box* pBox{ new CerealPack(10.0, 20.0, 30.0, "plastic", "good") };
	pBox->showVolume();

	std::cout << SEP << std::endl;

	// dynamic crosscast
	Contents* pContent { dynamic_cast<Contents*>(pBox) };
	pContent->showType();

	return 0;
}
