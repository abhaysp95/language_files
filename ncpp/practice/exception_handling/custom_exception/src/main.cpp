#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Woverloaded-virtual"
// declartion of warning function here
#pragma clang diagnostic pop

#include <iostream>
#include <exception>

class Overspeed: public std::exception {
	private:
		int speed;
		//using exception::what;  // silences the warning "'Overspeed::what' hides overloaded virtual function [-Woverloaded-virtual]"
		/* using it privately prevents the user of Overspeed to directly use Base::what() */
	public:
		const char* what() override {
			return "You're going too fast\nRemeber this is a car not plane\n";
		}
		void setSpeed(int speed) { this->speed = speed; }
		int getSpeed() { return this->speed; }
};

class Car {
	private:
		int speed;
	public:
		Car() {
			this->speed = 0;
			std::cout << "Car started" << std::endl;
		}
		void accelerate() throw(Overspeed) {  // throw(Overspeed) is just added for testing purpose
			while(true) {
				this->speed += 10;
				std::cout << "your speed is " << this->speed << " km\\h" << std::endl;
				if (this->speed >= 250) {
					Overspeed osp;
					osp.setSpeed(this->speed);
					throw osp;
				}
			}
		}
};

int main(int argc, char **argv) {
	Car c;
	try {
		c.accelerate();
	}
	catch (Overspeed s) {
		std::cout << s.what() << std::endl;
	}
    return 0;
}