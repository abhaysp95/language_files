// cpp file for "smiley.hpp"

#include "../inc/smiley.hpp"

Smiley::Smiley(Point p, int r): Circle(p, r), _mouth(nullptr) {}
Smiley::~Smiley() {
	delete this->_mouth;
	for (Shape* p: this->_eyes) {
		delete p;
	}
}

void Smiley::move(Point to) { /** do something */ }

void Smiley::draw() const {
	Circle::draw();
	for (Shape* p: this->_eyes) {
		p->draw();
	}
	this->_mouth->draw();
}
void Smiley::rotate(int d) { /** rotate to d degree */ }

void Smiley::add_eye(Shape *s) { this->_eyes.push_back(s); }
void set_mouth(Shape *s) { /** set mouth somewhere */ }

void Smiley::wink(int i) { /** wink an eye */ }