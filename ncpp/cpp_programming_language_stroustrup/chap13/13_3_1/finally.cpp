#include <iostream>
#include <memory>

template<typename F>
struct Final_action {
	Final_action(F f): clean(f) {}
	~Final_action() { clean(); }
	F clean;
};

template<class F>
Final_action<F> finally(F f) {
	return Final_action<F>(f);
}

void test() {
	// handle undiciplined resource acquisition
	// demonstrate that arbitrary actions are possible
	int *p = new int{7};  // should use a unique_ptr(like below line)
	//std::unique_ptr<int*> p = std::make_unique<int*>(new int{7});
	int *buf = (int*)malloc(100 * sizeof(int));  // C-style allocation

	auto act1 = finally([&] {
				delete p;
				free(buf);
				std::cout << "(1)Goodbye, Cruel world\n";
			});

	int var = 0;
	std::cout << "(2)var = " << var << '\n';

	// nested block
	{
		var = 1;
		auto act2 = finally([&]{ std::cout << "(3)finally\n"; var =7; });
		std::cout << "(4)var = " << var << '\n';
	}  // act2 is invoked here

	std::cout << "(5)var = " << var << '\n';
}  // act1 is invoked here

int main(int argc, char** argv) {
	test();
	return 0;
}
