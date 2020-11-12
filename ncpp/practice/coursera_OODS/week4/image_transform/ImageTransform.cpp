#include <iostream>
#include <cmath>
#include <cstdlib>

#include "uiuc/PNG.h"
#include "uiuc/HSLAPixel.h"
#include "ImageTransform.h"

/* ******************
   (Begin multi-line comment...)

   Write your name and email address in the comment space here:

Name:
Email:

(...end multi-line comment.)
 ******************** */

using uiuc::PNG;
using uiuc::HSLAPixel;

/**
 * Returns an image that has been transformed to grayscale.
 *
 * The saturation of every pixel is set to 0, removing any color.
 *
 * @return The grayscale image.
 */
PNG grayscale(PNG image) {
	/// This function is already written for you so you can see how to
	/// interact with our PNG class.
	for (unsigned x = 0; x < image.width(); x++) {
		for (unsigned y = 0; y < image.height(); y++) {
			HSLAPixel & pixel = image.getPixel(x, y);

			// `pixel` is a reference to the memory stored inside of the PNG `image`,
			// which means you're changing the image directly. No need to `set`
			// the pixel since you're directly changing the memory of the image.
			pixel.s = 0;
		}
	}

	return image;
}



/**
 * Returns an image with a spotlight centered at (`centerX`, `centerY`).
 *
 * A spotlight adjusts the luminance of a pixel based on the distance the pixel
 * is away from the center by decreasing the luminance by 0.5% per 1 pixel euclidean
 * distance away from the center.
 *
 * For example, a pixel 3 pixels above and 4 pixels to the right of the center
 * is a total of `sqrt((3 * 3) + (4 * 4)) = sqrt(25) = 5` pixels away and
 * its luminance is decreased by 2.5% (0.975x its original value).  At a
 * distance over 160 pixels away, the luminance will always decreased by 80%.
 *
 * The modified PNG is then returned.
 *
 * @param image A PNG object which holds the image data to be modified.
 * @param centerX The center x coordinate of the crosshair which is to be drawn.
 * @param centerY The center y coordinate of the crosshair which is to be drawn.
 *
 * @return The image with a spotlight.
 */
PNG createSpotlight(PNG image, int centerX, int centerY) {
	int icenterX = image.width() / 2;
	int icenterY = image.height() / 2;
	int distX = icenterX - centerX;
	int distY = icenterY - centerY;
	int radius = sqrt(pow(distX, 2) + pow(distY, 2));  // radius for crosshair circle
	bool newLuminanceSet = false;
	for (unsigned i = 0; i < image.width(); ++i) {
		for (unsigned j = 0; j < image.height(); ++j) {
			HSLAPixel &pixel = image.getPixel(i, j);
			newLuminanceSet = false;
			int distance = sqrt(pow(((int)i - centerX), 2) + pow(((int)j - centerY), 2));
			double max_decrease = (pixel.l * 80) / 100;
			double current_decrease = ((pixel.l) * distance * 0.5) / 100;
			if (((int)i >= centerX - radius) && ((int)i <= centerX + radius)) {
				if (((int)j >= centerY - radius) && ((int)j <= centerY + radius)) {
					if (distance <= radius) {
						if (current_decrease <= max_decrease) {
							pixel.l -= current_decrease;
							newLuminanceSet = true;
						}
					}
				}
			}
			if (!newLuminanceSet) {
				if (current_decrease <= max_decrease) {
					pixel.l -= current_decrease;
				}
				else {
					pixel.l -= max_decrease;
				}
			}
		}
	}
	return image;

}


/**
 * Returns a image transformed to Illini colors.
 *
 * The hue of every pixel is set to the a hue value of either orange or
 * blue, based on if the pixel's hue value is closer to orange than blue.
 *
 * @param image A PNG object which holds the image data to be modified.
 *
 * @return The illinify'd image.
 **/
PNG illinify(PNG image) {
	for (unsigned i = 0; i < image.width(); ++i) {
		for (unsigned j = 0; j < image.height(); ++j) {
			HSLAPixel &pixel = image.getPixel(i, j);
			int fromOrange1 = abs(pixel.h - 11);
			int fromOrange2 = abs(360 - fromOrange1);
			int fromBlue1 = abs(pixel.h - 216);
			int fromBlue2 = abs(360 - fromBlue1);
			/* example point -> 200
			   fo1 = 189
			   fo2 = 171
			   fb1 = 27
			   fb2 = 333 */
			/* example point -> 100
			   fo1 = 89
			   fo2 = 271
			   fb1 = 126
			   fb2 = 234 */
			if (((fromOrange1 < fromBlue1) && (fromOrange1 < fromBlue2)) ||
					((fromOrange2 < fromBlue1) && (fromOrange2 < fromBlue2))) {
				if (pixel.h == 200) {
					std::cout << "inside if" << std::endl;
				}
				pixel.h = 11;
			}
			else {
				pixel.h = 216;
			}
		}
	}
	return image;
}


/**
 * Returns an immge that has been watermarked by another image.
 *
 * The luminance of every pixel of the second image is checked, if that
 * pixel's luminance is 1 (100%), then the pixel at the same location on
 * the first image has its luminance increased by 0.2.
 *
 * @param firstImage  The first of the two PNGs, which is the base image.
 * @param secondImage The second of the two PNGs, which acts as the stencil.
 *
 * @return The watermarked image.
 */
PNG watermark(PNG firstImage, PNG secondImage) {
	for (unsigned int i = 0; i < firstImage.width(); ++i) {
		for (unsigned int j = 0; j < secondImage.height(); ++j) {
			HSLAPixel &pixel1 = firstImage.getPixel(i, j);
			HSLAPixel &pixel2 = secondImage.getPixel(i, j);
			if (pixel2.l == 1.0) {
				if (pixel1.l + 0.2 <= 1.0) {
					pixel1.l += 0.2;
				}
			}
		}
	}
	return firstImage;
}
