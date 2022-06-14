#ifndef _CYLINDER_H
#define _CYLINDER_H

#include <iostream>

class CylinderBox {
	public:
		// static constants
		static inline const float maxRadius { 35.0f };
		static inline const float maxHeight { 60.0f };
		static inline const std::string defaultMaterial { "paperboard" };

		CylinderBox(double radius, double height, std::string_view material = defaultMaterial);

		float Volume() const;

	private:
		static inline const float PI { 3.141592f };

		float radius;
		float height;
		std::string material;
};

#endif

/** you typically define all member variables that are both
 * static and const as inline as well */

/** same rule follows for static member functions as well. static member functions can't be const  */
