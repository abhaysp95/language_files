#ifndef _VESSEL_HPP
#define _VESSEL_HPP

// abstract class defining as vessel
class Vessel {
	public:
		virtual ~Vessel() = default;  // as always: a virtual destructor
		virtual double volume() const = 0;
};
// this class works as an interface

#endif
