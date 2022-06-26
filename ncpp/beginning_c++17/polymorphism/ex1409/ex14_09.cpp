// Calling virtual functions from constructors and destructors

#include "box.hpp"
#include "carton.hpp"

#include <iostream>
#include <typeinfo>  // for std::type_info

// define trivial non-polymorphic base and derived classes
class NonPolyBase {};
class NonPolyDerived: public NonPolyBase {};

Box& get_some_box();
NonPolyBase& get_some_nonpoly();

#define SEP "--------------"

int main(void) {
	// part1: typeid() on type and == operator
	std::cout << "Type double has name " << typeid(double).name() << std::endl;
	std::cout << "1 is " << (typeid(1) == typeid(int) ? "an int" : "no int") << std::endl;

	std::cout << SEP << std::endl;

	// part2: typeid() on polymorphic references
	Carton carton{ 1, 2, 3, "paperboard" };
	Box& box_reference = carton;

	std::cout << "Type of carton is " << typeid(carton).name() << std::endl;
	std::cout << "Type of carton is " << typeid(carton).hash_code() << std::endl;
	std::cout << "Type of box_reference is " << typeid(box_reference).name() << std::endl;
	std::cout << "These are " << (typeid(carton) == typeid(box_reference) ? "" : "not ") << "equal" << std::endl;

	std::cout << SEP << std::endl;

	// part3: typeid() on polymorphic pointers
	Box* box_pointer = &carton;
	std::cout << "Type of &carton is " << typeid(&carton).name() << std::endl;
	std::cout << "Type of box_reference is " << typeid(box_pointer).name() << std::endl;
	std::cout << "Type of *box_reference is " << typeid(*box_pointer).name() << std::endl;

	std::cout << SEP << std::endl;

	// part4: typeid() on non-polymorphic pointers
	NonPolyDerived derived;
	NonPolyBase& base_ref = static_cast<NonPolyBase&>(derived);

	std::cout << "Type of base_ref is " << typeid(base_ref).name() << std::endl;

	std::cout << SEP << std::endl;

	// part5: typeid() on expressions
	const std::type_info& type_info1 = typeid(get_some_box());  // function call evaluated
	const std::type_info& type_info2 = typeid(get_some_nonpoly());  // function call not evaluated
	std::cout << "Type of get_some_box() is " << type_info1.name() << std::endl;
	std::cout << "Type of get_some_nonpoly() is " << type_info2.name() << std::endl;
	std::cout << "Type before for get_some_nonpoly() with get_some_box(): " << type_info2.before(type_info1) << std::endl;
	std::cout << "Type before for get_some_box() with get_some_nonpoly(): " << type_info1.before(type_info2) << std::endl;

	return 0;
}

Box& get_some_box() {
	std::cout << "get_some_box() called..." << std::endl;
	static Carton carton{ 2, 3, 5, "duplex" };
	return carton;
}

NonPolyBase& get_some_nonpoly() {
	std::cout << "get_some_nonpoly() called..." << std::endl;
	static NonPolyDerived derived;
	return derived;
}

/**
 * If its operand is a type, typeid() evaluates to a reference to a type_info
 * object representing this type.
 * If its operand is any expression that evaluates to a reference to a
 * polymorphic type, this expression is evaluated, and the operand returns the
 * dynamic type of the value referred to by the outcome of this evaluation.
 * If its operand is any other expression, the expression is not evaluated, and
 * the result is the static type of the expression.
 */
