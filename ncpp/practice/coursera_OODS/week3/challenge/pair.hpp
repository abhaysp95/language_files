#ifndef PAIR_H
#define PAIR_H

class Pair {
	public:
		int *pa, *pb;
		Pair(int, int);
		Pair(const Pair&);
		~Pair();
};

#endif
