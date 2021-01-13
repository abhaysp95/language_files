// main file

#include <iostream>

class Sample {
	public:
		void show(int x) {
			std::cout << x;
		}
};

int main(int argc, char **argv) {
	Sample *p = new Sample();
	p->show(20);
	return 0;
}