#ifndef _BOX_HPP
#define _BOX_HPP

#include <iostream>
#include <iomanip>
#include <utility>

// adding using statement generally a bad practice (I think for namespace), but
// "std::rel_ops" is one of the exceptions
using namespace std::rel_ops;

class Box {
	private:
		double length {1.0};
		double width {1.0};
		double height {1.0};
	public:
		explicit Box(double l, double w, double h);
		explicit Box(double s);
		Box() = default;

		double volume() const;

		// accessors
		double getLength() const;
		double getWidth() const;
		double getHeight() const;

		bool hasSameVolumeAs(const Box& other) const;

		// overload 'less-than' operator
		bool operator<(const Box& other) const;
		inline bool operator<(double value) const {  // overloading for operator<()
			return this->volume() < value;  // since the function is inline, I defined function here too
		}
		inline bool operator>=(const Box& other) const {
			return this->volume() >= other.volume();
		}
		inline bool operator>=(double value) const {
			return this->volume() >= value;
		}
		inline bool operator==(const Box &other) const {  // just for demo
			return this->volume() < other.volume();
		}
		/* inline bool operator==(const Box &other) const {  // another (more sane) way for ==
			// you can't use std::rel_ops with this definition for obvious reasons
			// I'm commenting this definition to use std::rel_ops right now
			return (this->length == other.getLength()
					&& this->width == other.getWidth()
					&& this->height == other.getHeight());
		} */

		// friend std::ostream& operator<<(std::ostream& stream, const Box& box) {  // works
		/* inline friend std::ostream& operator<<(std::ostream& stream, const Box& box) {  // works
			stream << "Box(" << std::setw(2) << box.getLength() << ','
				<< std::setw(2) << box.getWidth() << ','
				<< std::setw(2) << box.getHeight() << ')';
			return stream;
		} */
		// friend std::ostream& operator<<(std::ostream& stream, const Box& box);  // not work

		/* inline Box operator+(const Box& other) const {  // check new way below
			return Box { std::max(this->length, other.getLength()),
				std::max(this->width, other.getWidth()),
				this->height + other.height };
		} */
		inline Box& operator+=(const Box& other) {
			this->length = std::max(this->length, other.getLength());
			this->width = std::max(this->width, other.getWidth());
			this->height += other.getHeight();
			return *this;
		}
		inline Box operator+(const Box& other) {
			return Box{*this} += other;
		}

		// prefix and postfix operators
		inline Box& operator++() {  // prefix increment operator overloading
			++this->length;
			++this->width;
			++this->height;
			return *this;
		}
		inline const Box operator++(int) {  // dummy parameter int to tell difference (postfix incremenet)
			Box copy{*this};
			++(*this);
			return copy;
		}
		// prefix and postfix decrement (should I throw exception if arm size gets less than zero ?)
		inline Box& operator--() {
			--this->length;
			--this->width;
			--this->height;
			return *this;
		}
		inline const Box operator--(int) {
			Box copy{*this};
			--(*this);
			return copy;
		}

		inline explicit operator bool() const {  // if (box) {...}
			return this->volume();
		}
};

// since volume() is public, you can have operator<() as ordinary function as well
/** should be defined in same namespace (or scope) as the Box class itself */
// bool operator<(const Box &first, const Box &second);
/** though, this works generally, but using it with "std::rel_ops" namespace
 * gave error for ambiguity (since bool operator<(const Box &other) const;
 * method is already in class Box) */

/* inline bool operator<(const Box &box, double value) {
	// no need because operator<(doube value) method above in class is doing same thing
	return box.volume() < value;
} */

// an inline function shouldn't be defined in cpp class
inline bool operator<(double value, const Box &box) {
	return box.volume() < value;
}

/* inline std::ostream& operator<<(std::ostream& stream, const Box& box) {  // works
	stream << "Box(" << std::setw(2) << box.getLength() << ','
		<< std::setw(2) << box.getWidth() << ','
		<< std::setw(2) << box.getHeight() << ')';
  return stream;
} */
std::ostream& operator<<(std::ostream& stream, const Box& box);  // works

#endif

/**
  * Note: what is ODR violation ?
  */
