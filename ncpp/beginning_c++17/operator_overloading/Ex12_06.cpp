#include "truckload.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>

inline double random(double max_size) {
	return static_cast<double>(std::rand() / (RAND_MAX / max_size + 1));
}

int main(void) {
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	const double limit {99.0};             // Upper limit on Box dimensions
	TruckLoad load;
	const size_t boxCount {20};               // Number of Box object to be created
											  // Create boxCount Box objects
	for (size_t i {}; i < boxCount; ++i) {
		load.addCuboid(std::make_shared<Cuboid>(random(limit), random(limit), random(limit)));
	}

	std::cout << "printing first load:\n";
	std::cout << load;

	std::cout << "\nprinting another load:\n";
	TruckLoad another_load{load};
	std::cout << another_load;


	TruckLoad copied;
	copied = another_load;		// Use copy assignment

	std::cout << "The boxes in the copied Truckload are:\n";
	std::cout << copied;

	return 0;
}

/**
  * Valgrind output:
  *
  * $ valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose -s --tool=memcheck ./Ex1206
  *
  * ==546485== 1,440 (24 direct, 1,416 indirect) bytes in 1 blocks are definitely lost in loss record 7 of 7
  * ==546485==    at 0x4846003: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
  * ==546485==    by 0x10B6A1: TruckLoad::addCuboid(std::shared_ptr<Cuboid>) (truckload.cpp:46)
  * ==546485==    by 0x10A31C: main (Ex12_06.cpp:20)
  * ==546485==
  * ==546485== LEAK SUMMARY:
  * ==546485==    definitely lost: 72 bytes in 3 blocks
  * ==546485==    indirectly lost: 2,328 bytes in 77 blocks
  * ==546485==      possibly lost: 0 bytes in 0 blocks
  * ==546485==    still reachable: 0 bytes in 0 blocks
  * ==546485==         suppressed: 0 bytes in 0 blocks
  * ==546485==
  * ==546485== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)
  */

// so, truckload still've problems
