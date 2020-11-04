#pragma once

#include <iostream>
#include <sstream>

namespace uiuc {
	class HSLAPixel {
		public:
			double h;  // hue of the pixel in degrees(0, 360)
			double s;  // saturation of the pixel
			double l;  // Luminance of the pixel
			double a;  // Alpha of the pixel

			/* A default pixel is completely opaque(non-transparent) and white. */
			HSLAPixel();
			HSLAPixel(double hue, double saturation, double luminance);
			HSLAPixel(double hue, double saturation, double luminance, double alpha);
			static HSLAPixel BLUE;
			static HSLAPixel ORANGE;
			static HSLAPixel YELLOW;
			static HSLAPixel PURPLE;
	};
};
