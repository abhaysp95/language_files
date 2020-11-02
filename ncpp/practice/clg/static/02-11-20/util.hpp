#ifndef UTIL_H
#define UTIL_H

namespace statclass {
	class A {
		private:
			int obnum_;
			static int count_;
		public:
			void setObnum();
			int getObnum();
			static int getCount();
	};
	class B {
		public:
			int var;
	};
	class C {
		public:
			int a;
			void setA(int a);
			void addA(C a, C b);
	};
};
#endif
