#ifndef _CUBOID_H
#define _CUBOID_H

class Cuboid {
	private:
		double length;
		double width;
		double height;
	public:
		explicit Cuboid() = default;
		explicit Cuboid(double l, double w, double h);
		explicit Cuboid(double aSide);
		double Volume() const;
		bool hasLargerVolumeThean(Cuboid aCube);

		// copy constructor
		Cuboid(const Cuboid &aCube);

		// returing this object for method chaining
		Cuboid& setLength(double l);
		Cuboid& setWidth(double l);
		Cuboid& setHeight(double l);

		double getLength() const;
		double getWidth() const;
		double getHeight() const;
};

#endif
