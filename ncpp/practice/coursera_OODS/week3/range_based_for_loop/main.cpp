#include <iostream>
#include <vector>

int main(int argc, char **argv) {
	std::vector<int> *intList = new std::vector<int>(5);  // this will basically have 5 int blocks initialized to 0 and push_back is well "append", so declare intList here without size
	intList -> push_back(3);
	intList -> push_back(4);
	intList -> push_back(5);
	intList -> push_back(6);
	intList -> push_back(7);

	for (int x: *intList) {
		std::cout << x << std::endl;
	}

	std::cout << "----------------" << std::endl;

	std::vector<int> iList(5);
	iList.push_back(3);
	iList.push_back(4);
	iList.push_back(5);
	iList.push_back(6);
	iList.push_back(7);

	for (int x: iList) {
		std::cout << x << std::endl;
	}
	std::cout << "----------------" << std::endl;

	std::vector<int> *pList = new std::vector<int>;
	pList -> push_back(3);
	pList -> push_back(4);
	pList -> push_back(5);
	pList -> push_back(6);
	pList -> push_back(7);

	for (int x: *pList) {
		std::cout << x << std::endl;
	}

	std::cout << "----------------" << std::endl;

	/* now with this range based for loop x is temporary variable so whenever
	 * you iterate it copies values everytime to x and x is used, which is
	 * basically 'slow', if you make change in x then it's not reflected in
	 * orignal array(vector) you can use dereference now */
	for (int &x: *pList) {
		std::cout << x << std::endl;
	}

	std::cout << "----------------" << std::endl;

	/* but also with reference uses you can change content of the vector */
	for (int &x: *pList) {
		x = 99;
		std::cout << x << std::endl;
	}

	std::cout << "----------------" << std::endl;

	{
		int count{5};
		for (int &x: *pList) {
			x = count++;
		}
	}

	/* the above scope will make count be reclaimed as it's scope is over and
	 * value of pList will be written since it's created on heap, let's check
	 * this with stack based vector in last */

	/* but if you don't want to change values of orignal vector it's better to
	 * use const */
	for (const int &x: *pList) {
		// x = 99; it'll give error
		std::cout << x << std::endl;
	}

	std::cout << "----------------" << std::endl;

	{
		static int count{9};
		for (int &x: iList) {
			x = count++;
		}
		//std::vector<int> newList;
	}
	/* The above block, even though iList is stack based works because of the
	 * scope, iList is defined in global Translation unit, so it will be
	 * available to anything inside a block, so it has nothing to do with
	 * stack,heap(or poitner) here */

	for (int x: iList) {
		std::cout << x << std::endl;
	}

	/* some notes on unsigned int, sizes of containers are generally unsigned int */
	std::cout << "----------------" << std::endl;

	for (int i = 0; i < pList -> size() - 1; ++i) {
		// something(think how to print)
		std::cout << "now on unsigned type" << std::endl;
	}

	std::cout << "----------------" << std::endl;

	/* it's okay but when a vector is having size of 0, then it'll give some very long positive value */
	//std::vector<int> *dList = nullptr;
	std::vector<int> dList;
	for (int i = 0; i < (int) dList.size() - 1; ++i) {
		std::cout << "now on unsigned type" << std::endl;
		// infinte loop(maybe, segfault here)
		/* there's two ways now, either typecast to (int/signed int) or use i +
		 * 1 < dList -> size(), but also you have to check for max side too for
		 * int, but that's rare(as in daily usage) */
	}
	std::cout << "----------------" << std::endl;
	return 0;
}
