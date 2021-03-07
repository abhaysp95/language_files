// header file

#ifndef _GUARD_POINT_HPP_
#define _GUARD_POINT_HPP_

class Point {
	private:
		int _x, _y;
	public:
		Point(int x, int y);
		Point();
		int getX() const;
		int getY() const;
		void setX(int x);
		void setY(int y);
};

#endif