#pragma once
// this line tells the compiler to compile our class only once, even for multiple definations

// the header file only contains the functionality of the class

class Cube {
	public:
		double getVolume();
		double getSurfaceArea();
		void setLength(double length);
	private:
		double length_;
};
