#include <iostream>
#include "pair.hpp"

int main(int argc, char **argv) {
	chlng::Pair p(15, 16);
	chlng::Pair q(p);
	chlng::Pair *hp = new chlng::Pair(23, 42);

	std::cout << "----------------" << std::endl;

	std::cout << "print for p: " << std::endl;
	p.print();
	std::cout << "print for q: " << std::endl;
	q.print();
	std::cout << "print for hp: " << std::endl;
	hp->print();

	std::cout << "----------------" << std::endl;

	std::cout << "comparing p with q: " << std::endl;
	std::cout << p.compare(q) << std::endl;
	std::cout << "comparing q with q: " << std::endl;
	std::cout << q.compare(q) << std::endl;
	std::cout << "comparing p with hp: " << std::endl;
	std::cout << p.compare(hp) << std::endl;
	std::cout << "comparing hp with hp: " << std::endl;
	std::cout << hp->compare(hp) << std::endl;

	std::cout << "----------------" << std::endl;

	chlng::Pair::print(p);
	chlng::Pair::print(q);
	chlng::Pair::print(hp);

	std::cout << "----------------" << std::endl;

	delete hp;
	std::cout << "message printed" << std::endl;
	return 0;
}
