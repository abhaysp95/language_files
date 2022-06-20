#ifndef _CUBOID_H
#define _CUBOID_H

#include <stddef.h>
#include <iostream>
#include <iomanip>

class Cuboid {
	private:
		double length {1.0};
		double width {1.0};
		double height {1.0};
		mutable unsigned count {};  // objectCount is serving same purpose
		static inline size_t objectCount {};
	public:
		explicit Cuboid() = default;
		explicit Cuboid(double l, double w, double h);
		explicit Cuboid(double aSide);
		double volume() const;
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

		void printVolume() const;
		size_t getObjectByCount() const;

		// friend function
		friend double surfaceArea(const Cuboid &aCuboid);

		int compare(const Cuboid &cuboid) const;
		// void listCuboid() const;

		friend inline std::ostream& operator<<(std::ostream& out, const Cuboid& cuboid) {
			out << " Box("
				<< std::setw(2) << cuboid.getLength() << ", "
				<< std::setw(2) << cuboid.getWidth() << ", "
				<< std::setw(2) << cuboid.getHeight() << ")";
			return out;
		}
};

#endif

	/** objectCount is static inline, before C++17 (usage of inline), you'll
	 * have to specifically define the static member values outside of class
	 * with a statement like this
	 * size_t Cuboid::objectCount {};
	 */
