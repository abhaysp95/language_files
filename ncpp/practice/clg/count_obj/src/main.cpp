// main file

#include <iostream>

/*class Apple {
	private:
		std::string _color{};
		int _size{};
	public:
		Apple() {}
		Apple(std::string color, int size): _color{color}, _size{size} {}
		static int count() {
			int count{};
			return count++;
		}
};*/

class Apple{
	private:
		std::string _color{};
		int _size{};
		int _objno{};
		static int _count;
	public:
		Apple() { this->_objno = ++this->_count; }
		Apple(std::string color, int size): _color{color}, _size{size} { this->_objno = ++this->_count; }
		int getObjNo() const { return this->_objno; }
		static int getObjCount(void) { return _count; }
		~Apple() { this->_count--; }
};
int Apple::_count{};

int main(int argc, char **argv) {
	Apple a{"green", 10};
	std::cout << "Object No: " << a.getObjNo() << "\n";
	Apple b{"blue", 20};
	std::cout << "Object No: " << b.getObjNo() << "\n";
	std::cout << "Count: " << Apple::getObjCount() << "\n";
	return 0;
}