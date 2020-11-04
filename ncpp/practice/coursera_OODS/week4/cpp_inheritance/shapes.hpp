#ifndef SHAPE_H
#define SHAPE_H

namespace uiuc {
	class Shape {
		private:
			double width_;
		public:
			//Shape();
			//Shape(double width);
			double getWidth() const;
			// having const here means this function can only modify those class variables which have keyword mutable in them
	};
};

#endif
