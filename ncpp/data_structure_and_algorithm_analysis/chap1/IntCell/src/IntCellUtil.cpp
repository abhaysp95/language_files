// cpp file for "IntCellUtil.hpp"

#include "../inc/IntCellUtil.hpp"

IntCell::IntCell(int initialvalue): _storedvalue{initialvalue} {}

// now this is a bad-bad idea
/**
  if you give a pointer to copy constructor, you might want to use that
  pointer later, that's the general idea, but if you delete it here
  than that's the access voilation, cause the other person might not know this
  */
IntCell::IntCell(IntCell* other): _storedvalue{ other->read() } {
	delete other;
}

int IntCell::read() const { return this->_storedvalue; }

void IntCell::write(int x) { this->_storedvalue = x; }