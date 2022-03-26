// header file

#ifndef _GUARD_INTCELLUTIL_HPP_
#define _GUARD_INTCELLUTIL_HPP_

class IntCell {
	private:
		int _storedvalue;
	public:
		explicit IntCell(int intialvalue = 0);
		IntCell(IntCell* other);
		int read() const;
		void write(int x);
};

#endif