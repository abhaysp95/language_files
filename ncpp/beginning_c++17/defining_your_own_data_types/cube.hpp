#ifndef _CUBE_H
#define _CUBE_H

class Cube {
	private:
		double side;
	public:
		explicit Cube(double aSide);
		double Volume();
		bool hasLargerVolumeThean(Cube aCube);

		// copy constructor
		Cube(const Cube &aCube);
};

#endif
