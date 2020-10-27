#ifndef PAIR_H
#define PAIR_H

namespace chlng {
	class Pair {
		public:
			int *pa, *pb;
			Pair(int, int);
			Pair(const Pair&);
			~Pair();
			void print();
			static void print(const Pair& obj);
			static void print(const Pair* obj);
			bool compare(const Pair& obj);
			bool compare(const Pair* obj);
	};
};

#endif
